#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
// Mezo Sandoval Claudia 3CV4
void sortString(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len-1; i++) {
        for(int j = i+1; j < len; j++) {
            if(str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

bool haveSameChars(const char* s1, const char* s2) {
    int len = strlen(s1);
    if(len != strlen(s2)) return false;

    char* temp1 = strdup(s1);
    char* temp2 = strdup(s2);

    sortString(temp1);
    sortString(temp2);

    bool result = strcmp(temp1, temp2) == 0;

    free(temp1);
    free(temp2);

    return result;
}

bool isScramble(const char* s1, const char* s2) {
    if(strcmp(s1, s2) == 0) return true;

    if(!haveSameChars(s1, s2)) return false;

    int n = strlen(s1);
    for(int i = 1; i < n; i++) {
        char left1[i+1], right1[n - i + 1];
        char left2[i+1], right2[n - i + 1];
        char left2_swap[i+1], right2_swap[n - i + 1];

        strncpy(left1, s1, i);
        left1[i] = '\0';
        strcpy(right1, s1 + i);

        strncpy(left2, s2, i);
        left2[i] = '\0';
        strcpy(right2, s2 + i);

        strncpy(left2_swap, s2 + n - i, i);
        left2_swap[i] = '\0';
        strcpy(right2_swap, s2);
        right2_swap[n - i] = '\0';

        if(isScramble(left1, left2) && isScramble(right1, right2))
            return true;

        if(isScramble(left1, left2_swap) && isScramble(right1, right2_swap))
            return true;
    }

    return false;
}

int main() {
    char s1[31], s2[31];

    printf("Ingrese s1: ");
    scanf("%30s", s1);
    printf("Ingrese s2: ");
    scanf("%30s", s2);

    bool resultado = isScramble(s1, s2);

    printf("Input: s1 = \"%s\", s2 = \"%s\"\n", s1, s2);
    printf("Output: %s\n", resultado ? "true" : "false");

    return 0;
}

