#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	if(argc < 2){
	   return 1;
	}
 if(strcmp(argv[1], "--add") == 0){
    if(argc < 3)
    {
        return 1;
    }

    int fd = open("audit.log", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if(fd < 0)
    {
        return 1;
    }

    write(fd, argv[2], strlen(argv[2]));
    write(fd, "\n", 1);

    close(fd);

    return 0;
}
if(strcmp(argv[1], "--view") == 0)
{
    int fd = open("audit.log", O_RDONLY);

    if(fd < 0)
    {
        return 1;
    }

    char ch;
    int line = 1;
    char num[10];

    num[0] = line + '0';
    num[1] = ':';
    num[2] = ' ';
    write(1, num, 3);

    while(read(fd, &ch, 1) > 0)
    {
        write(1, &ch, 1);

        if(ch == '\n')
        {
            if(read(fd, &ch, 1) > 0)
            {
                line++;

                int temp = line;
                int len = 0;
                char digits[10];

                while(temp > 0)
                {
                    digits[len++] = (temp % 10) + '0';
                    temp /= 10;
                }

                for(int i = len - 1; i >= 0; i--)
                    write(1, &digits[i], 1);

                write(1, ": ", 2);
                write(1, &ch, 1);
            }
        }
    }

    close(fd);
    return 0;
}


}
