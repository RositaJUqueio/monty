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
