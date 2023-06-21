/* Authors: Rosita Uqueio, Israel Nanor */
#include "monty.h"

void initialize_infos()
{
	info->fd = NULL;
	info->line = NULL;
}

/**
 * process_file - opens file,reads each line
 * and closes the file.
 * @file_path: given file path
 */
void process_file(const char *file_path)
{
	/*Opens the file */
	size_t buflen;
	info->fd = fopen(file_path, "r");

	if (info->fd == NULL)
	{
		char error[100];

		sprintf(error, "Error: Can't open file %s", file_path);
		prints_error_message(error);
	}

	while (getline(&(info->line), &buflen, info->fd) != -1)
	{
		printf("%s\n", info->line);
	}	
	/*we need to add code to read each line of code*/
	fclose(info->fd);
}
