#include "monty.h"

everywher_t every = {NULL, 1};

/**
 * main - entry point to the program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (always)
 */
int main(int argc, char **argv)
{
	FILE *fd;
	size_t len = 0;
	ssize_t get = 0;
	char *line = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
		error_usage();

	fd = fopen(argv[1], "r");
	if (fd == NULL)
		file_error(argv[1]);

	while ((get = getline(&line, &len, fd)) != -1)
	{
		line_number++;
		if (get != 0)
			execution(fd, line, &stack, line_number);
	}

	free(line);
	fclose(fd);

	return (0);
}
