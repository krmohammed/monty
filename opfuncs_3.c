#include "main.h"

/**
 * mul - multiplies the top element by the second top element
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int prod;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	prod = tmp->next->n * tmp->n;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	(*stack)->n = prod;

	free(tmp);
}


/**
 * pchar - prints the top/front of stack/queue
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
}

/**
 * pstr - prints the top/front of stack/queue
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (*stack == NULL)
		putchar('\n');

	tmp = *stack;
	while(tmp && tmp->n != 0)
	{
		if ((*stack)->n >= 0 || (*stack)->n <= 127)
		{
			putchar(tmp->n);
			tmp = tmp->next;
		}
		else
			return;
	}
}


/**
 * rotl - pushes top element to the last
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - pushes top element to the last
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	*stack = tmp;
}
