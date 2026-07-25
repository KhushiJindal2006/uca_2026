#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    int c, next;

    while ((c = fgetc(fp)) != EOF) {

        if (c == '"') {
            putchar(c);

            while ((c = fgetc(fp)) != EOF) {
                putchar(c);

                if (c == '\\') {
                    c = fgetc(fp);
                    if (c != EOF)
                        putchar(c);
                } else if (c == '"') {
                    break;
                }
            }
        }

        else if (c == '\'') {
            putchar(c);

            while ((c = fgetc(fp)) != EOF) {
                putchar(c);

                if (c == '\\') {
                    c = fgetc(fp);
                    if (c != EOF)
                        putchar(c);
                } else if (c == '\'') {
                    break;
                }
            }
        }

        else if (c == '/') {

            next = fgetc(fp);

            if (next == '/') {
                while ((c = fgetc(fp)) != EOF && c != '\n');
                if (c == '\n')
                    putchar('\n');
            }

            else if (next == '*') {
                int prev = 0;

                while ((c = fgetc(fp)) != EOF) {
                    if (prev == '*' && c == '/')
                        break;
                    prev = c;
                }
            }

            else {
                putchar(c);

                if (next != EOF)
                    ungetc(next, fp);
            }
        }

        else {
            putchar(c);
        }
    }

    fclose(fp);
    return 0;
}
