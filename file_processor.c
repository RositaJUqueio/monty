/* Authors: Rosita Uqueio, Israel Nanor */
#include "monty.h"

void initialize_infos(info_t *info)
{
	info->fd = NULL;
	info->line_number = 0;
	info->stack = NULL;
}

/**
 * process_file - opens file,reads each line
 * and closes the file.
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
		/*printf("%s\n", info->line);*/
		line_parser(info, info->line);
		process_instructions(info);
	}	
	/*we need to add code to read each line of code*/
	fclose(info->fd);
}

void line_parser(info_t *info, char *line)
{
	int idx = 0, i = 0;
	char *tokens, *line_cpy;
	char *delim = " $\t\n\r";

	line_cpy = malloc(sizeof(strlen(line)));
	if (line_cpy == NULL)
		prints_error_message("Error: malloc failed");

	strcpy(line_cpy, line);
	tokens = strtok(line_cpy, delim);
	while (tokens != NULL)
	{
		tokens = strtok(NULL, delim);
		idx++;
	}

	info->line_tokens = malloc(sizeof(char) * (idx + 1));
	if (info->line_tokens== NULL)
	{
		prints_error_message("Error: malloc failed");
	}
	strcpy(line_cpy, line);
	tokens = strtok(line_cpy, delim);
	while (tokens != NULL)
	{
		info->line_tokens[i] = tokens;
		tokens = strtok(NULL, delim);
		i++;
	}
	info->line_tokens[i] = NULL;

}

void process_instructions(info_t *info)
{
	int i = 0;
	char error[100];

	instruction_t instructions[] = {
		{"push", push_func},
		{"pall", pall_func},
		{NULL, NULL}
	};

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, info->line_tokens[0]) == 0)
		{
	   		 instructions[i].f(&(info->stack), info->line_number);
	   		 return;
		}
		i++;
	}

	sprintf(error, "L%u: unknown instruction %s", info->line_number, info->line_tokens[0]);
        prints_error_message(error);
	/*exit(EXIT_FAILURE)*/;

}
