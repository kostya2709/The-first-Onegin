#ifndef MY_HEADER_H_INCLUDED
#define MY_HEADER_H_INCLUDED

const int NLINES = 100;
const int NCHARS = 100;

int ReadFile (char *file, char lines[NLINES][NCHARS]);

void Qsort (int left, int right, char *pointer[NLINES]);

int Is_Larger_Str(char *str1, char *str2);

void Swap (char *arr[], int a, int b);

char Down (char c);

int WriteFile (char *file, int num, char *pointer[NLINES]);


#endif // MY_HEADER_H_INCLUDED
