#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_special(char c) {
    return (c == '@' || c == '#' || c == '%' || c == '&' || c == '?');
}

void check_password(const char *s) {
    int n = strlen(s);

    // Condition 5: Length must be at least 10
    if (n < 10) {
        printf("NO\n");
        return;
    }

    bool has_lower = false;
    bool has_upper_inside = false;
    bool has_digit_inside = false;
    bool has_special_inside = false;

    for (int i = 0; i < n; i++) {
        // Condition 1: At least one lowercase letter anywhere
        if (s[i] >= 'a' && s[i] <= 'z') {
            has_lower = true;
        }

        // Conditions 2, 3, and 4: Must be strictly inside (not first or last character)
        if (i > 0 && i < n - 1) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                has_upper_inside = true;
            } else if (s[i] >= '0' && s[i] <= '9') {
                has_digit_inside = true;
            } else if (is_special(s[i])) {
                has_special_inside = true;
            }
        }
    }

    if (has_lower && has_upper_inside && has_digit_inside && has_special_inside) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        char s[10005];
        scanf("%s", s);
        check_password(s);
    }

    return 0;
}