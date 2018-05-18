#include <stdio.h>
#include <string.h>

void foo(char *bar)
{
    char c[12];

    memcpy(c, bar, strlen(bar));    //no bounds checking
    return ;
}

int main(int argc, char *argv[])
{
    foo(argv[1]);
    return 0;
}
