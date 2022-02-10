/// JGGHACK
/// AUTOR - DARIUSZ SURDEL
/// GRUPA 14
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char pass[20];
    while(scanf("%s", pass) != EOF)
    {
        for(int i = 0; i < 20; i += 2)
            {
                printf("%c", ((int)pass[i] - 65 + (((int)pass[i+1] - 65) * 16)));
            }
            puts("\n");
    }
    return 0;
}
