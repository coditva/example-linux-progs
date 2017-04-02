#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char name[256];
    struct utsname uts;

    if (gethostname(name, 255) != 0 || uname(&uts) < 0) {
        fprintf(stderr, "Could not get host information\n");
        exit(1);
    }

    printf("Computer name is %s\n", name);
    printf("System is %s on %s hardware\n", uts.sysname, uts.machine);
    printf("Nodename is %s\n", uts.nodename);
    printf("Version is %s, %s\n", uts.release, uts.version);
    return 0;
}
