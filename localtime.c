#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct tm *tm_ptr;
    time_t the_time;

    (void) time(&the_time);
    tm_ptr = localtime(&the_time);

    printf("Raw time is %ld\n", the_time);
    printf("gmtime gives:\n");
    printf("date: %02d/%02d/%02d\n",
            tm_ptr->tm_year, tm_ptr->tm_mon + 1, tm_ptr->tm_mday);
    printf("time: %02d:%02d:%02d\n",
            tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);
    printf("The date is: %s\n", ctime(&the_time));

    return 0;
}
