#include "monty.h"

/**
 * execution - executes all operations in a monty file
 * @file: file
 * @line: line
 * @stack: stack type
 * @line_num: line number
 *
 */

void execution(FILE *file, char *line, stack_t **stack, int line_num)
{
	char *tok = NULL;
	int i;
	instruction_t coms[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", division},
		{"mod", modu}, {"mul", mul}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
		{"stack", stack_mode}, {"queue", queue_mode}, {NULL, NULL}
	};

	tok = strtok(line, " \t\n");
	every.com = strtok(NULL, " \t\n");
	i = 0;
	while (tok && coms[i].opcode != NULL)
	{
		if (tok && tok[0] == '#')
			return;
		if (strcmp(tok, coms[i].opcode) == 0)
		{
			coms[i].f(stack, line_num);
			return;
		}
		i++;
	}

	if (tok != NULL && coms[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, tok);
		fclose(file);
		free(line);
		exit(EXIT_FAILURE);
	}
}


/**
 * isnumber - checks if a string is a number or not
 * @nums: string to check
 *
 * Return: 0 if it is, 1 otherwisee
 */
int isnumber(char *nums)
{
	int i;

	for (i = 0; nums[i] != '\0'; i++)
	{
		if (nums[i] == '-')
			continue;
		if (nums[i] < 48 || nums[i] > 57)
			return (1);
	}
	return (0);
}
