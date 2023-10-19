#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_num: The line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}


/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_num: The line number of of the opcode.
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_2(8, line_num, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_n - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_num: The line number of of the opcode.
 */
void add_n(stack_t **stack, unsigned int line_num)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_2(8, line_num, "add");

	(*stack) = (*stack)->next;
	add = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_n - Subbs the top two elements of the stack.
 * @stack: Pointer to a pointer node of the stack.
 * @line_num: The line number of of the opcode.
 */
void sub_n(stack_t **stack, unsigned int line_num)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		error_2(8, line_num, "sub");


	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_n - Div the top two elements of the stack.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_num: The line number of of the opcode.
 */
void div_n(stack_t **stack, unsigned int line_num)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_2(8, line_num, "div");

	if ((*stack)->n == 0)
		error_2(9, line_num);
	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
