//!@file

#include <stdio.h>
#include <stdlib.h>
#include "my header.h"

/*!
@brief This program gets line from a file,
sorts them lexicographically and writes them into a file.
*/


int main()
{

    char lines[NLINES][NCHARS] = {};
    char *pointer[NLINES] = {};

    int length = 0;

    char *file_from = "read me.txt";
    char *file_to = "write to me.txt";

    length = ReadFile (file_from, lines);

    int i;
    for (i = 0; i < length; i++)
        pointer[i] = lines[i];

    Qsort (0, length - 1, pointer);

    WriteFile (file_to, length, pointer);

    return 0;
}
