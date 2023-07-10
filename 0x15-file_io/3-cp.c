# include "main.h"

#define BUFFER_SIZE 1024


/**
 * main - Entry point of the program.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on successful execution, otherwise exits with an error code.
 */
int main(int argc, char **argv)
{
	int source_fd;
	int destination_fd;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	source_fd = open_source_file(argv[1]);
	destination_fd = open_destination_file(argv[2]);
	copy_data(source_fd, destination_fd);
	close_file(source_fd, argv[1]);
	close_file(destination_fd, argv[2]);

	exit(0);
}

/**
 * open_source_file - Opens the source file in read-only mode.
 * @src: The path of the source file.
 *
 * Return: The file descriptor for the source file.
 *         Exits with an error code if the file cannot be opened.
 */
int open_source_file(const char *src)
{
	int source_fd = open(src, O_RDONLY);

	if (source_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		exit(98);
	}

	return (source_fd);
}

/**
 * open_destination_file - Opens the destination file with appropriate flags.
 * @dest: The path of the destination file.
 *
 * Return: The file descriptor for the destination file.
 *         Exits with an error code if the file cannot be opened.
 */
int open_destination_file(const char *dest)
{
	int destination_fd = open(dest, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (destination_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
		exit(99);
	}
	return (destination_fd);
}

/**
 * copy_data - Copies data from the source file to the destination file.
 * @source_fd: The file descriptor for the source file.
 * @destination_fd: The file descriptor for the destination file.
 *
 * Return: None. Exits with an error code if there are any read/write errors.
 */
void copy_data(int source_fd, int destination_fd)
{
	ssize_t bytes_read;
	ssize_t bytes_written;
	char buffer[1024];

	while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(destination_fd, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to destination file\n");
			exit(99);
		}
	}
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from source file\n");
		exit(98);
	}
}

/**
 * close_file - Closes the file descriptor associated with the file.
 * @fd: The file descriptor to be closed.
 * @filename: The name of the file associated with the file descriptor.
 *
 * Return: None. Exits with an error code if there's an error
 */
void close_file(int fd, const char *filename)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd for file %s\n", filename);
		exit(100);
	}
}
