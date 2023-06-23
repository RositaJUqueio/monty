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

/**
 * prints_error_message_with_args - prints error message
 *  and exits
 * @message: pointer to string
 * @info: struct for global variables
 */
void prints_error_message_with_args(const char *message, info_t *info)
{
	char error[100];

	sprintf(error, message, info->line_number, info->line_tokens[0]);
	prints_error_message(error);
}

/**
 * _isdigit - defines if string passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *s)
{
	unsigned int i;

	if (s[0] == '-')
		i = 1;
	else
		i = 0;

	for (; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: a copy of the string
 */
char *_strdup(const char *str)
{
	size_t len = strlen(str) + 1;
	char *new_str = malloc(len);

	if (new_str == NULL)
		return (NULL);
	memcpy(new_str, str, len);
	return (new_str);
}

