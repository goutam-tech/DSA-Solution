#include <stdio.h>

int main()
{
    int n, x = 0;
    char s[10];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        if (s[1] == '+' || s[2] == '+')
            x++;
        else
            x--;
    }

    printf("%d\n", x);
    return 0;
}