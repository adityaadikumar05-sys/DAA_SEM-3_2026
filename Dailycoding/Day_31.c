#include <stdio.h>
#include <string.h>

int same(int a[], int b[])
{
    for (int i = 0; i < 256; i++)
    {
        if (a[i] != b[i])
            return 0;
    }

    return 1;
}

int main()
{
    char str[] = "cbaebabacd";
    char pattern[] = "abc";

    int n = strlen(str);
    int m = strlen(pattern);

    if (m > n)
        return 0;

    int patternCount[256] = {0};
    int windowCount[256] = {0};

    for (int i = 0; i < m; i++)
    {
        patternCount[(unsigned char)pattern[i]]++;
        windowCount[(unsigned char)str[i]]++;
    }

    printf("Anagrams found at indices: ");

    for (int i = 0; i <= n - m; i++)
    {
        if (same(patternCount, windowCount))
            printf("%d ", i);

        if (i + m < n)
        {
            windowCount[(unsigned char)str[i]]--;
            windowCount[(unsigned char)str[i + m]]++;
        }
    }

    return 0;
}
