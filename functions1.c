#include "monty.h"


/**
 * addto_stack - Adds a node to stack.
 * @node: Pointer to the new node.
 * @line_num: The line number of the opcode.
 */
void addto_stack(stack_t **node, __attribute__((unused))unsigned int line_num)
{
	stack_t *tmp;

	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node;
		return;
	}
	tmp = head;
	head = *node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * p_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_num: line number of  the opcode.
 */
void p_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	(void) line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_t - Adds a node to the stack.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_num: The line number of the opcode.
 */
void pop_t(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		error_2(7, line_num);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_t - Prints the top node of the stack.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_num: The line number of of the opcode.
 */
void print_t(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		error_2(6, line_num);
	printf("%d\n", (*stack)->n);
}
