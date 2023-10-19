#include "monty.h"

/**
 * open_f - opens a file
 * @f_name: the file namepath
 * Return: void
 */

void open_f(char *f_name)
{
	FILE *fd = fopen(f_name, "r");

	if (f_name == NULL || fd == NULL)
		error_1(2, f_name);

	read_f(fd);
	fclose(fd);
}


/**
 * read_f - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_f(FILE *fd)
{
	int line_num, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buffer, &len, fd) != -1; line_num++)
	{
		format = sep_line(buffer, line_num, format);
	}
	free(buffer);
}


/**
 * sep_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_num: line number
 * @format: storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int sep_line(char *buffer, int line_num, int format)
{
	char *op, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		error_1(4);

	op = strtok(buffer, delim);
	if (op == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(op, "stack") == 0)
		return (0);
	if (strcmp(op, "queue") == 0)
		return (1);

	find_f(op, value, line_num, format);
	return (format);
}

/**
 * find_f - find the appropriate function for the opcode
 * @op: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @line_num: line number
 * Return: void
 */
void find_f(char *op, char *value, int line_num, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", addto_stack},
		{"pall", p_stack},
		{"pint", print_t},
		{"pop", pop_t},
		{"nop", nop},
		{"swap", swap},
		{"add", add_n},
		{"sub", sub_n},
		{"div", div_n},
		{"mul", mul_n},
		{"mod", mod_n},
		{"pchar", p_char},
		{"pstr", p_str},
		{"rotl", rot_to_bot},
		{"rotr", rot_to_top},
		{NULL, NULL}
	};

	if (op[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(op, func_list[i].opcode) == 0)
		{
			call_f(func_list[i].f, op, value, line_num, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error_1(3, line_num, op);
}


/**
 * call_f - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @value: string representing a numeric value.
 * @line_num: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_f(op_func func, char *op, char *value, int line_num, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			error_1(5, line_num);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				error_1(5, line_num);
		}
		node = create_n(atoi(value) * flag);
		if (format == 0)
			func(&node, line_num);
		if (format == 1)
			addto_queue(&node, line_num);
	}
	else
		func(&head, line_num);
}
