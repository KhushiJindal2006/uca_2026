#include <stdio.h>
#include <string.h>

const char base64[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void encodeBase64(char input[]) {

    int len = strlen(input);

    for (int i = 0; i < len; i += 3) {

        unsigned char b1 = input[i];
        unsigned char b2 = 0;
        unsigned char b3 = 0;

        if (i + 1 < len)
            b2 = input[i + 1];

        if (i + 2 < len)
            b3 = input[i + 2];

        int index1 = b1 >> 2;

        int index2 = ((b1 & 3) << 4) | (b2 >> 4);

        int index3 = ((b2 & 15) << 2) | (b3 >> 6);

        int index4 = b3 & 63;

        printf("%c", base64[index1]);
        printf("%c", base64[index2]);

        if (i + 1 < len)
            printf("%c", base64[index3]);
        else
            printf("=");

        if (i + 2 < len)
            printf("%c", base64[index4]);
        else
            printf("=");
    }

    printf("\n");
}


int getBase64Value(char c) {

    if (c >= 'A' && c <= 'Z')
        return c - 'A';

    if (c >= 'a' && c <= 'z')
        return c - 'a' + 26;

    if (c >= '0' && c <= '9')
        return c - '0' + 52;

    if (c == '+')
        return 62;

    if (c == '/')
        return 63;

    return -1;
}


void decodeBase64(char input[]) {

    int len = strlen(input);

    for (int i = 0; i < len; i += 4) {

        int v1 = getBase64Value(input[i]);
        int v2 = getBase64Value(input[i + 1]);

        int v3 = 0;
        int v4 = 0;

        if (input[i + 2] != '=')
            v3 = getBase64Value(input[i + 2]);

        if (input[i + 3] != '=')
            v4 = getBase64Value(input[i + 3]);


        unsigned char b1 = (v1 << 2) | (v2 >> 4);

        unsigned char b2 = ((v2 & 15) << 4) | (v3 >> 2);

        unsigned char b3 = ((v3 & 3) << 6) | v4;

        printf("%c", b1);

        if (input[i + 2] != '=')
            printf("%c", b2);

        if (input[i + 3] != '=')
            printf("%c", b3);
    }

    printf("\n");
}



int main() {

    char input[1000];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    printf("Base64: ");
    encodeBase64(input);

    printf("Enter Base64 string to decode: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    printf("Decoded: ");
    decodeBase64(input);

    return 0;
}
