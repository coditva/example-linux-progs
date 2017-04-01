/*
 * copy_system.c
 * Copy file1 to file2 as specified on the command line one block at a time
 * This assumes that input file is present and output file is not for simplicity
 */

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char c[1024];
    int in, out;
    int nread;

    if (argc != 3) {
        write (1, "Specify file names\n", 19);
    }

    /* Open files */
    in = open (argv[1], O_RDONLY);
    out = open (argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    /* Copy file to out file */
    while ((nread = read (in, c, sizeof(c))) > 0) {
        write (out, c, nread);
    }

    return 0;
}
