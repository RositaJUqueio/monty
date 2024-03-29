/* Authors: Rosita Uqueio, Israel Nanor */
#include "monty.h"

/**
 * initialize_infos - initiazes global variables
 * @info: global program data
 * Returns: nothing
 */
void initialize_infos(info_t *info)
{
	info->fd = NULL;
	info->line_number = 0;
	info->stack = NULL;
	info->is_queue = 0;
}

/**
 * process_file - opens file,reads each line
 * and closes the file.
 * @info: global variable struct
 * @file_path: given file path
 */
void process_file(const char *file_path, info_t *info)
{
	/*Opens the file */

	info->fd = fopen(file_path, "r");

	if (info->fd == NULL)
	{
		char error[100];

		sprintf(error, "Error: Can't open file %s", file_path);
		prints_error_message(error);
	}

	while (fgets(info->line, sizeof(info->line), info->fd) != NULL)
	{
		info->line_number += 1;
		info->line[strcspn(info->line, "\n")] = '\0';

		line_parser(info, info->line);
		process_instructions(info);
		free_line_tokens(info);
	}
	free_all(info);
}
/**
 * line_parser - splits line into tokens
 * @info: global program data
 * @line: read line to split into tokens
 * Return: nothing
 */
void line_parser(info_t *info, char *line)
{
	int idx = 0, i = 0;
	char *tokens, line_cpy[MAX_LINE_LENGTH];
	char *delim = " \n\t\r";

	strcpy(line_cpy, line);
	tokens = strtok(line_cpy, delim);
	while (tokens != NULL)
	{
		tokens = strtok(NULL, delim);
		idx++;
	}

	info->line_tokens = malloc(sizeof(char *) * (idx + 1));
	if (info->line_tokens == NULL)
	{	free_all(info);
		prints_error_message("Error: malloc failed");
	}
	strcpy(line_cpy, line);
	tokens = strtok(line_cpy, delim);
	while (i < 2 && tokens != NULL)
	{
		info->line_tokens[i] = _strdup(tokens);
		tokens = strtok(NULL, delim);
		i++;
	}
	info->line_tokens[i] = NULL;

}

/**
 * process_instructions - handles instructions to be performed per opcode
 * @info: global program data
 * Return: nothing
 */
void process_instructions(info_t *info)
{
	int i = 0;

	instruction_t instructions[] = {
		{"push", push_func}, {"pchar", pchar_func},
		{"pall", pall_func}, {"pop", pop_func},
		{"pint", pint_func}, {"swap", swap_func},
		{"nop", nop_func}, {"sub", sub_func},
		{"add", add_func}, {"div", div_func},
		{"mul", mul_func}, {"pstr", pstr_func},
		{"rotl", rotl_func}, {"rotr", rotr_func},
		{"queue", nop_func}, {"stack", nop_func},
		{NULL, NULL}
	};

	if (!info->line_tokens[0])
		return;
	if (strcmp("mod", info->line_tokens[0]) == 0)
	{
		modu_func(&(info->stack), info->line_number);
		return;
	}

	if (info->line_tokens[0][0] == '#')
		strcpy(info->line_tokens[0], "nop");

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, info->line_tokens[0]) == 0)
		{
			instructions[i].f(&(info->stack), info->line_number);
			return;
		}
		i++;
	}
	free_all(info);
	prints_error_message_with_args("L%u: unknown instruction %s", info);
}

