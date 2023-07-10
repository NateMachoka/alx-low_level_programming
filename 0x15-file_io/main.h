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
void exitWithError(const char *message, const void *arg);
int openSourceFile(const char *fileFrom);
int openDestinationFile(const char *fileTo);
void copyFileContent(int fdFrom, int fdTo);
int main(int argc, char *argv[]);
int _putchar(char c);

#endif
