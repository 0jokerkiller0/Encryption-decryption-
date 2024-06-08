#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 1024

void encrypt(char *str);
void decrypt(char *str);

int main() {
    char choice, s[MAX_SIZE];

    while (1) {
        printf("To encrypt, input 'e' or 'E'.\n");
        printf("To decrypt, input 'd' or 'D'.\n");
        printf("To exit, input any other letter.\n");
        printf("Your choice: ");
        scanf(" %c", &choice);

        if ((choice == 'e') || (choice == 'E')) {
            printf("Input text to encrypt: ");
            scanf("%s", s);
            encrypt(s);
        } else if ((choice == 'd') || (choice == 'D')) {
            printf("Input text to decrypt: ");
            scanf("%s", s);
            decrypt(s);
        } else
            break;
    }

    return 0;
}

void encrypt(char *str) {
    int n = 0;
    char *p = str, q[MAX_SIZE];

    while (*p) {
        if (islower(*p)) {
            if ((*p >= 'a') && (*p < 'x'))
                q[n] = toupper(*p + (char)3);
            else if (*p == 'x')
                q[n] = 'A';
            else if (*p == 'y')
                q[n] = 'B';
            else
                q[n] = 'C';
        } else {
            q[n] = *p;
        }

        n++;
        p++;
    }

    q[n++] = '\0';
    printf("Encrypted text: %s\n", q);
}

void decrypt(char *str) {
    int n = 0;
    char *p = str, q[MAX_SIZE];

    while (*p) {
        if (isupper(*p)) {
            if ((*p >= 'A') && (*p <= 'Z'))
                q[n] = 'A' + ((*p - 'A') - 3) % 26;
            else if ((*p >= 'a') && (*p <= 'z'))
                q[n] = 'a' + ((*p - 'a') - 3) % 26;
            else
                q[n] = *p;
        } else {
            q[n] = *p;
        }

        n++;
        p++;
    }

    q[n++] = '\0';
    printf("Decrypted text: %s\n", q);
}