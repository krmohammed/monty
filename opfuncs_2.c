#include "monty.h"

/**
 * add - adds the top two nodes of the stack
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		myFree(*stack);
		failed();
	}
	tmp = *stack;
	sum = tmp->n + tmp->next->n;
	(*stack) = tmp->next;
	(*stack)->prev = NULL;
	(*stack)->n = sum;

	free(tmp);
}

/**
 * nop - does nothing
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subs top element from second top element
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int diff;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		myFree(*stack);
		failed();
	}
	tmp = *stack;
	diff = tmp->next->n - tmp->n;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	(*stack)->n = diff;

	free(tmp);
}


/**
 * division - divides the second top element by the top element
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */

void division(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int quo;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		myFree(*stack);
		failed();
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		myFree(*stack);
		failed();
	}
	tmp = *stack;
	quo = tmp->next->n / tmp->n;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	(*stack)->n = quo;
	free(tmp);
}


/**
 * modu - computes the remainder of a division
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */

void modu(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int rem;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		myFree(*stack);
		failed();
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		myFree(*stack);
		failed();
	}
	tmp = *stack;
	rem = tmp->next->n % tmp->n;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	(*stack)->n = rem;
	free(tmp);
}
