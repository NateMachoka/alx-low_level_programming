#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>
#include <gelf.h>

void print_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

void print_elf_header_info(Elf64_Ehdr *header)
{
	int i;

	printf("Magic: ");

	for (i = 0; i < EI_NIDENT; ++i)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");

	printf("Class: ");
	switch (header->e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:  printf("Invalid class\n"); break;
	case ELFCLASS32:    printf("ELF32\n"); break;
	case ELFCLASS64:    printf("ELF64\n"); break;
	default:            printf("Unknown\n"); break;
	}

	printf("Data: ");
	switch (header->e_ident[EI_DATA])
	{
	case ELFDATANONE:   printf("Invalid data encoding\n"); break;
	case ELFDATA2LSB:   printf("2's complement, little endian\n"); break;
	case ELFDATA2MSB:   printf("2's complement, big endian\n"); break;
	default:            printf("Unknown\n"); break;
	}

	printf("Version: %d\n", header->e_ident[EI_VERSION]);

	printf("OS/ABI: ");

	switch (header->e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:         printf("UNIX System V ABI\n"); break;
	case ELFOSABI_HPUX:         printf("HP-UX operating system\n"); break;
	case ELFOSABI_NETBSD:       printf("NetBSD\n"); break;
	case ELFOSABI_LINUX:        printf("GNU/Linux\n"); break;
	case ELFOSABI_SOLARIS:      printf("Solaris\n"); break;
	case ELFOSABI_AIX:          printf("AIX\n"); break;
	case ELFOSABI_IRIX:         printf("IRIX\n"); break;
	case ELFOSABI_FREEBSD:      printf("FreeBSD\n"); break;
	case ELFOSABI_TRU64:        printf("TRU64 UNIX\n"); break;
	case ELFOSABI_MODESTO:      printf("Novell Modesto\n"); break;
	case ELFOSABI_OPENBSD:      printf("OpenBSD\n"); break;
	case ELFOSABI_ARM_AEABI:    printf("ARM EABI\n"); break;
	case ELFOSABI_ARM:          printf("ARM\n"); break;
	case ELFOSABI_STANDALONE:   printf("Standalone (embedded) application\n"); break;
	default:                    printf("Unknown\n"); break;
	}

	printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

	printf("Type: ");

	switch (header->e_type)
	{
	case ET_NONE:   printf("No file type\n"); break;
	case ET_REL:    printf("Relocatable file\n"); break;
	case ET_EXEC:   printf("Executable file\n"); break;
	case ET_DYN:    printf("Shared object file\n"); break;
	case ET_CORE:   printf("Core file\n"); break;
	default:        printf("Unknown\n"); break;
	}

	printf("Entry point address: 0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[])
{
	const char *filename;
	int fd;
	Elf *elf;
	GElf_Ehdr header;

	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	filename = argv[1];
	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		print_error("Failed to open the file");
	}

	elf = elf_begin(fd, ELF_C_READ, NULL);

	if (elf == NULL)
	{
		print_error("Failed to initialize libelf");
	}

	if (elf_kind(elf) != ELF_K_ELF)
	{
		print_error("Not an ELF file");
	}

	if (gelf_getehdr(elf, &header) == NULL)
	{
		print_error("Failed to read the ELF header");
	}

	print_elf_header_info(&header);

	elf_end(elf);
	close(fd);

	return (0);
}
