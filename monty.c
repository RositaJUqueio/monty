/* Authors:  Rosita Uqueio & Israel Nanor */
#include "monty.h"

/**
 * main - Program entry point
 * @argc: umber of command line arguments
 * @argv: pointer to string array
 * containing command line arguments
 *
 * Return: 0 at success
 */
int main(int argc, char *argv[])
{
	/*Checks if file name is provided*/
	if (argc != 2)
		prints_error_message("USAGE: monty file");

	initialize_infos(&info);
	/*calling function to process file */
	process_file(argv[1], &info);

	return (0);
}

/**
 * free_all - frees malloced variables before exits
 * @info: struct for global varibles
 */
void free_all(info_t *info)
{
	int i = 0;

	while (info->line_tokens[i] != NULL)
	{
		free(info->line_tokens[i]);	
		i++;
	}
	free(info->line_tokens);
	info->line_tokens = NULL;

	free_dlistint(info->stack);
	fclose(info->fd);
}
