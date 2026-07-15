#include <stdio.h>

void reverse_string(char *str)
{
    int start = 0;
    int end = 0;

    while (str[end] != '\0')
    {
        end++;
    }

    end--; 

    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    char str[100];

    fgets(str, sizeof(str), stdin);

    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
        i++;
    }

    reverse_string(str);

    printf("Reversed String: %s\n", str);

    return 0;
}
