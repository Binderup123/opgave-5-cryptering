#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/crypto.h"

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage:\n");
        printf("  %s caesar <encrypt|decrypt> <shift> <text>\n", argv[0]);
        printf("  %s vigenere <encrypt|decrypt> <key> <text>\n", argv[0]);
        return 1;
    }

    char result[1024] = {0};

    if (strcmp(argv[1], "caesar") == 0) {
        int shift = atoi(argv[3]);
        const char *text = argv[4];
        if (strcmp(argv[2], "encrypt") == 0)
            caesar_encrypt(text, shift, result);
        else
            caesar_decrypt(text, shift, result);
    }
    else if (strcmp(argv[1], "vigenere") == 0) {
        const char *key = argv[3];
        const char *text = argv[4];
        if (strcmp(argv[2], "encrypt") == 0)
            vigenere_encrypt(text, key, result);
        else
            vigenere_decrypt(text, key, result);
    } else {
        printf("Invalid algorithm. Use 'caesar' or 'vigenere'.\n");
        return 1;
    }

    printf("Result: %s\n", result);
    return 0;
}
