#include "main.h"

/**
 * error_usage - prints usage error
 *
 */

void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * failed_malloc - prints error message when malloc fails
 *
 */

void failed_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * file_error - prints error messages when file op fails
 * @filename: name of file
 *
 */

void file_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
