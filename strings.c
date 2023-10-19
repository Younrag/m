#include "monty.h"

/**
 * p_char - Prints the Ascii value.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_num: The line number of of the opcode.
 */
void p_char(stack_t **stack, unsigned int line_num)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		error_s(11, line_num);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		error_s(10, line_num);
	printf("%c\n", ascii);
}

/**
 * p_str - Prints a string.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_num: The line number of of the opcode.
 */
void p_str(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rot_to_bot - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_num: The line number of of the opcode.
 */
void rot_to_bot(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rot_to_top - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_num: The line number of of the opcode.
 */
void rot_to_top(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
