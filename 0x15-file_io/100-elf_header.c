#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define ELF_MAGIC "\x7F\x45\x4C\x46"

typedef struct
{
	unsigned char e_ident[16];
	uint16_t e_type;
	uint16_t e_machine;
	uint32_t e_version;
	uint64_t e_entry;
	uint64_t e_phoff;
	uint64_t e_shoff;
	uint32_t e_flags;
	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
} Elf64_Ehdr;


/**
 * display_elf_header - Displays the information contained in the ELF header
 * @header: Pointer to the ELF header structure
 *
 * This function takes a pointer to the ELF header structure and displays
 * the information contained in the header. It prints the magic number,
 * class, data format, version, OS/ABI, ABI version, type, and entry point
 * address of the ELF file.
 */
void display_elf_header(const Elf64_Ehdr *header)
{
	int i;

	printf("Magic:   ");

	for (i = 0; i < 4; i++)
		printf("%02x ", header->e_ident[i]);

	printf("\n");

	printf("Class:                           %s\n",
	       header->e_ident[4] == 1 ? "ELF32" :
	       header->e_ident[4] == 2 ? "ELF64" : "Invalid");

	printf("Data:                            %s\n",
	       header->e_ident[5] == 1 ? "2's complement, little endian" :
	       header->e_ident[5] == 2 ? "2's complement, big endian" : "Invalid");

	printf("Version:                         %d (current)\n", header->e_ident[6]);

	printf("OS/ABI:                          %s\n",
	       header->e_ident[7] == 0 ? "System V" :
	       header->e_ident[7] == 1 ? "HP-UX" :
	       header->e_ident[7] == 2 ? "NetBSD" :
	       header->e_ident[7] == 3 ? "Linux" :
	       header->e_ident[7] == 6 ? "Solaris" :
	       header->e_ident[7] == 7 ? "AIX" :
	       header->e_ident[7] == 8 ? "IRIX" :
	       header->e_ident[7] == 9 ? "FreeBSD" :
	       header->e_ident[7] == 10 ? "Tru64" :
	       header->e_ident[7] == 11 ? "Novell Modesto" :
	       header->e_ident[7] == 12 ? "OpenBSD" :
	       header->e_ident[7] == 13 ? "OpenVMS" :
	       header->e_ident[7] == 14 ? "NonStop Kernel" :
	       header->e_ident[7] == 15 ? "AROS" :
	       header->e_ident[7] == 16 ? "Fenix OS" :
	       header->e_ident[7] == 17 ? "CloudABI" :
	       "Unknown");

	printf("ABI Version:                     %d\n", header->e_ident[8]);

	printf("Type:                            0x%04x\n", header->e_type);

	printf("Entry point address:             0x%lx\n", header->e_entry);
}

int main(int argc, char *argv[])
{
	int fd, i;
	Elf64_Ehdr header;
	int is_elf;

	if (argc != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		return (98);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		write(STDERR_FILENO, "Error opening file\n", 19);
		return (98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		write(STDERR_FILENO, "Error reading file\n", 19);
		close(fd);
		return (98);
	}

	is_elf = 1;

	for (i = 0; i < 4; i++)
	{
		if (header.e_ident[i] != ELF_MAGIC[i])
		{
			is_elf = 0;
			break;
		}
	}

	if (!is_elf)
	{
		write(STDERR_FILENO, "Not an ELF file\n", 16);
		close(fd);
		return (98);
	}

	display_elf_header(&header);

	close(fd);
	return (0);
}
