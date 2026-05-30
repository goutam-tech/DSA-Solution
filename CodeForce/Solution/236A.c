#include <stdio.h>
#include <string.h>

int main()
{
    char s[105];
    scanf("%s", s);

    int seen[26] = {0};

    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        seen[s[i] - 'a'] = 1;
    }

    int distinct = 0;
    for (int i = 0; i < 26; i++)
    {
        distinct += seen[i];
    }

    if (distinct % 2 == 0)
        printf("CHAT WITH HER!\n");
    else
        printf("IGNORE HIM!\n");

    return 0;
}