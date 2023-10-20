#include "monty.h"

/**
 * stack_push - pushes an element to a stack
 * @stack: stack type
 * @data: node data
 *
 */

void stack_push(stack_t **stack, int data)
{
	stack_t *ptr;

	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
		failed_malloc();

	ptr->n = data;
	ptr->prev = NULL;
	ptr->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = ptr;
	*stack = ptr;
}


/**
 * queue_push - pushes an element to a stack
 * @queue: queue type
 * @data: node data
 *
 */

void queue_push(stack_t **queue, int data)
{
	stack_t *ptr1, *ptr2;

	ptr1 = malloc(sizeof(stack_t));
	if (ptr1 == NULL)
		failed_malloc();

	ptr1->n = data;
	ptr1->prev = NULL;
	ptr1->next = NULL;

	if (*queue == NULL)
		*queue = ptr1;
	else
	{
		ptr2 = *queue;
		while (ptr2->next)
			ptr2 = ptr2->next;
		ptr2->next = ptr1;
		ptr1->prev = ptr2;
	}
}


/**
 * stack_mode - switched mode to stack type
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */

void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	every.mode = 1;

}


/**
 * queue_mode - switched mode to queue type
 * @queue: stack type
 * @line_number: line number of monty file
 *
 */

void queue_mode(stack_t **queue, unsigned int line_number)
{
	(void)queue;
	(void)line_number;
	every.mode = 2;

}
