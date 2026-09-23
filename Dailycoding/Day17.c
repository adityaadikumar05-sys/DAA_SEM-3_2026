#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    // Array to store the last seen index of each ASCII character
    int last_index[256];
    for (int i = 0; i < 256; i++) {
        last_index[i] = -1;
    }

    int max_len = 0;
    int left = 0; // Left pointer of the sliding window

    for (int right = 0; s[right] != '\0'; right++) {
        unsigned char current_char = (unsigned char)s[right];

        // If the character was seen inside the current window, move the left pointer
        if (last_index[current_char] >= left) {
            left = last_index[current_char] + 1;
        }

        // Update the last seen position of the character
        last_index[current_char] = right;

        // Calculate the current window length
        int current_len = right - left + 1;
        if (current_len > max_len) {
            max_len = current_len;
        }
    }

    return max_len;
}

int main() {
    char s1[] = "abcabcbb";
    printf("Input: \"%s\" -> Output: %d\n", s1, lengthOfLongestSubstring(s1)); // 3 ("abc")

    char s2[] = "bbbbb";
    printf("Input: \"%s\" -> Output: %d\n", s2, lengthOfLongestSubstring(s2)); // 1 ("b")

    char s3[] = "pwwkew";
    printf("Input: \"%s\" -> Output: %d\n", s3, lengthOfLongestSubstring(s3)); // 3 ("wke")

    return 0;
}