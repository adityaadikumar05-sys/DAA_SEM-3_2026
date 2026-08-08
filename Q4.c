// 4. Write a program to check whether a given string is a palindrome. Ignore spaces and differences between uppercase and lowercase letters.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void isPalindrome(char str[]) {
    char clean_str[strlen(str) + 1];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            clean_str[j++] = tolower(str[i]);
        }
    }
    clean_str[j] = '\0';

    int left = 0;
    int right = j - 1;
    int palindrome = 1;

    while (right > left) {
        if (clean_str[left++] != clean_str[right--]) {
            palindrome = 0;
            break;
        }
    }

    if (palindrome) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }
}

int main() {
    isPalindrome("A man, a plan, a canal: Panama");
    isPalindrome("race a car");
    isPalindrome("No 'x' in Nixon");
    return 0;
}
