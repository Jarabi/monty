#include "monty.h"

/**
 * check_file - Check if file can be read
 * @filepath: Path to file
 */
void check_file(char *filepath)
{
	FILE *fd;

	if (filepath == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n" filepath);
		exit(EXIT_FAILURE);
	}

	if (access(filepath, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n" filepath);
		exit(EXIT_FAILURE);
	}

	fd = fopen(filepath, "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n" file);
		exit(EXIT_FAILURE);
	}
	read_file(fd);
	fclose(fd);
}

/**
 * read_file - Attempts to read file contents
 * @fd: File descriptor
 */
void read_file(FILE *fd)
{
	int fd_line = 1;
	size_t n = 0;
	char *lineptr = NULL;

	while (getline(&lineptr, &n, fd) != -1)
	{

