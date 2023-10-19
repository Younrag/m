#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_f(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_n - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_n(int n)
{
	stack_t *nd;

	nd = malloc(sizeof(stack_t));
	if (nd == NULL)
		error_1(4);
	nd->next = NULL;
	nd->prev = NULL;
	nd->n = n;
	return (nd);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * addto_queue - Adds a node to the queue.
 * @new_n: Pointer to the new node.
 * @line_num: line number of the opcode.
 */
void addto_queue(stack_t **new_n, __attribute__((unused))unsigned int line_num)
{
	stack_t *tmp;

	if (new_n == NULL || *new_n == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_n;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_n;
	(*new_n)->prev = tmp;

}
