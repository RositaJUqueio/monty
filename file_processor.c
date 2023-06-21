/* Authors: Rosita Uqueio, Israel Nanor */

#include "monty.h"
/**
 * process_file -
 *
 */
void process_file(const char *file_path)
{
    /*Opens the file */
    FILE *file = fopen(file_path, "r");
    if (file == NULL)
    {
        char error[100];
        sprintf(error, "Error: Can't open file %s", file_path);
        prints_error_message(error);
    }
    /*we need to add code to read each line of code*/
    fclose(file);
}
