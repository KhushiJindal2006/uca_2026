#include <stdio.h>

int find_substring(const char *haystack, const char *needle)
{
    int i, j;

    for (i = 0; haystack[i] != '\0'; i++)
    {
        for (j = 0; needle[j] != '\0'; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                break;
            }
        }

        if (needle[j] == '\0')
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    char haystack[100], needle[100];

    printf("Enter main string: ");
    fgets(haystack, sizeof(haystack), stdin);

    printf("Enter substring: ");
    fgets(needle, sizeof(needle), stdin);

    for (int i = 0; haystack[i] != '\0'; i++)
    {
        if (haystack[i] == '\n')
        {
            haystack[i] = '\0';
            break;
        }
    }

    for (int i = 0; needle[i] != '\0'; i++)
    {
        if (needle[i] == '\n')
        {
            needle[i] = '\0';
            break;
        }
    }

    int index = find_substring(haystack, needle);

    printf("Index = %d\n", index);

    return 0;
}
