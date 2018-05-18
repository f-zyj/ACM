#include <stdio.h>

char s[5];

int main()
{
    while (scanf("%s", s) != EOF)
    {
        int i, j;
        for (i = 0; i < 3; i++)
        {
            for (j = i + 1; j < 3; j++)
            {
                if (s[i] > s[j])
                {
                    char t = s[i];
                    s[i] = s[j];
                    s[j] = t;
                }
            }
        }
        
        for (i = 0; i < 2; i++)
        {
            printf("%c ", s[i]);
        }
        printf("%c\n", s[2]);
    }
    
    return 0;
}
