#include "main.h"

/**
 * push - pushes a node to the stack/queue
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	int k;

	if (every.com == NULL || isnumber(every.com) != 0)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}

	k = atoi(every.com);

	if (every.mode == 1)
		stack_push(stack, k);
	else
		queue_push(stack, k);
}

/**
 * pall - prints all elements of a stack/queue
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;

	if (*stack == NULL)
		return;

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - prints the top/front of stack/queue
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - deletes the top of stack
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = ptr->next;
	if (*stack != NULL)
		ptr->next->prev = NULL;
	free(ptr);
}

/**
 * swap - swaps the top two elements of the stack/queue
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = n;
}
