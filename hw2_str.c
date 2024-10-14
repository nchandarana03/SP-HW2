#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "hw2.h"

int check_vowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void modify_case(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (check_vowel(str[i])) {
            str[i] = toupper(str[i]);
        } else {
            str[i] = tolower(str[i]);
        }
    }
}

int count_occurences(const char *str, const char *substr) {
    int count = 0;
    int len = strlen(substr);
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (strncasecmp(&str[i], substr, len) == 0) {
            count++;
            i += len - 1; 
        }
    }
    
    return count;
}

int str_interleave(char *str1, char *str2, char *substr) {
    if (str1 == NULL || str2 == NULL || substr == NULL) {
        printf("Please try again, unacceptable input.\n");
        return -1;
    }

    printf("str1 %s\n", str1);
    printf("str2 %s\n", str2);

    // Find length of interleaved string
    int len1 = strlen(str1), len2 = strlen(str2);
    int max_len = len1 + len2;
    
    char newstr[max_len + 1]; 
    int idx = 0;

    // Interleave characters
    for (int i = 0; i < max_len; i++) {
        if (i < len1) newstr[idx++] = str1[i];
        if (i < len2) newstr[idx++] = str2[i];
    }
    newstr[idx] = '\0';

    // Convert vowels to uppercase and consonants to lowercase
    modify_case(newstr);

    // Print manipulated new string
    printf("newstr %s\n", newstr);

    // Print substr
    printf("substr %s\n", substr);

    // Count occurrences of substr in newstr
    int occurrences = count_occurences(newstr, substr);
    printf("occurrences %d\n", occurrences);

    return 0;
}

// Test the code
int main() {
    str_interleave("Hello", "World", "eO");
    return 0;
}
