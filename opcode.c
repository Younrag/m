#include "monty.h"

/**
 * mul_n - Mul the top two elements of the stack.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_num: The line number of of the opcode.
 */
void mul_n(stack_t **stack, unsigned int line_num)
{
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_2(8, line_num, "mul");

	(*stack) = (*stack)->next;
	mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_n - Mod the top two elements of the stack.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_num: The line number of of the opcode.
 */
void mod_n(stack_t **stack, unsigned int line_num)
{
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		error_2(8, line_num, "mod");


	if ((*stack)->n == 0)
		error_2(9, line_num);
	(*stack) = (*stack)->next;
	mod = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
