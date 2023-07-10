#ifndef _FILE_IO_
#define _FILE_IO_

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters);
int _strlen(const char *str);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int open_source_file(const char *src);
int open_destination_file(const char *dest);
void copy_data(int source_fd, int destination_fd);
void close_file(int fd, const char *filename);
int main(int argc, char *argv[]);
int _putchar(char c);

#endif
