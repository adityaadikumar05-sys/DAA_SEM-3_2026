#include <stdio.h>
#include <string.h>

int main() {
    char password[50] = "";

    while (strcmp(password, "secure123") != 0) {
        printf("Enter password: ");
        scanf("%s", password);
    }

    printf("Login successful!\n");

    return 0;
}