/* Authors:  Rosita Uqueio, Israel Nanor */

#include "monty.h"

/**
 * prints_error_message - prints error message
 *  and exits
 * @message: pointer to string
 */
void prints_error_message(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(EXIT_FAILURE);
}

