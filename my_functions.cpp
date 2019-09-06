#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "my header.h"

/*!
@brief This function writes lines to a file from an
array of string with a pointer *pointer.

@param[in] *file Is a pointer to a file to write the text to.
@param[in] num Is an amount of the array that is written.
@param[in] *pointer[NLINES] Is a pointer to an array of char with NLINES lines.
The function writes strings from this array to the file.

\return It returns 1 if everything is alright and returns 0 if something went wrong.

*/

int WriteFile (char *file, int num, char *pointer[NLINES])
{
    assert (file);
    assert (isfinite(num));
    assert (num);
    assert (pointer[NLINES]);

    FILE* f = fopen (file, "w");
    if (!f)
    {
        printf ("This file - %s - doesn't exist!\n", file);
        return 1;
    }

    int i;
    for (i = 0; i < num; i++)
        fputs (pointer[i],f);
    fclose (f);

    return 0;

}

/*!
@brief This function reads lines from a file to an
array of string lines.

@param[in] *file Is a pointer to a file to read the text from.
@param[in] lines[NLINES][NCHARS] The function reads lines from this file to the array.

\return It returns 0 if everything is alright and returns 1 if something went wrong.

*/

int ReadFile (char *file, char lines[NLINES][NCHARS])
{
    assert (file);
    assert (lines[NCHARS]);

    FILE* f = fopen (file, "r");
    if (!f)
    {
        printf ("This file - %s - doesn't exist!\n", file);
        return 1;
    }

    char c;
    int mline = 0;
    int mchar = 0;
    while (fgets (lines[mline++], NLINES, f))
        ;
    fclose (f);

    return mline - 1;
}

/*!
@brief This function sorts quick elements of the array.

@param[in] left The left bound of the part of the array needs sorting.
@param[in] right The right bound of the part of the array needs sorting.
@param[in] *pointer[NLINES] The array which elements need sorting.

*/

void Qsort (int left, int right, char *pointer[NLINES])
    {
        assert (pointer[NLINES]);

        if (left >= right)
            return;

        int mid = (left + right) / 2;
        Swap (pointer, left, mid);

        int last = left;
        int i;
        for (i = left; i <= right; i++)
            if (Is_Larger_Str (pointer[left], pointer[i]) > 0)
               Swap (pointer, i, ++last);

        Swap (pointer, left, last);

        Qsort (left, last -  1, pointer);
        Qsort (last + 1, right, pointer);

    }


/*!
@brief This function returns a little letter, if the letter was capital,
and else it returns this very symbol.

@param[in] char c The char needs checking if the letter is capital.
@param[out] The function returns the decapitallated symbol.

*/

char Down (char c)
{

    if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
    else return c;
}

/*!
@brief This function compares two strings lexicographically.

@param[in] *str1 The pointer to the first string needs comparing
@param[in] *str2 The pointer to the second string needs comparing

\return The function returns an integer number.
If the first line is longer than the second one it returns a number that is more than 0;
if the second line is longer than the first one it returns a number that is less than 0;
if the lines are equal the function returns 0.

*/

int Is_Larger_Str (char *str1, char *str2)
    {
        assert (str1);
        assert (str2);

        while (Down (*str1) && Down (*str2)&&(Down (*str1) == Down (*str2)) )
        {
            *str1++;
            *str2++;
        }
        return Down (*str1) - Down (*str2);
    }

/*!
@brief This function changes two elements to each other of the array arr[] with indexes a and b.

param[in] *arr[] The array which elements need changing with each other.
param[in] a The first index.
param[in] a The second index.

*/

void Swap (char *arr[], int a, int b)
    {
        assert (arr);
        char *temp;
        temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
