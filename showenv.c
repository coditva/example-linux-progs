#include <stdlib.h>
#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[])
{
    char **env = environ;

    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}
