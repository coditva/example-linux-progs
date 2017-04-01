/*
 * copy_stdio.c
 * Copy file1 to file2 as specified on the command line
 * This assumes that input file is present and output file is not for simplicity
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char c;
    FILE *in, *out;

    if (argc != 3) {
        printf ("Specify file names\n");
    }

    /* Open files */
    in = fopen (argv[1], "r");
    out = fopen (argv[2], "w");

    /* Copy file to out file */
    while ((c = fgetc(in)) != EOF) {
        fputc(c, out);
    }

    return 0;
}
