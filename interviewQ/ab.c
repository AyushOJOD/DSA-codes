#include <stdio.h>
#include <regex.h>

int main() {
    int t;
    scanf("%d", &t);
    regex_t regex;
    regcomp(&regex, "^0*10*$", REG_EXTENDED);

    while (t--) {
        char s[512];  // Buffer size for binary strings
        scanf("%511s", s);  // Limit input to avoid buffer overflow
        printf("%s\n", regexec(&regex, s, 0, NULL, 0) == 0 ? "True" : "False");
    }

    regfree(&regex);  // Free the compiled regex
    return 0;
}
