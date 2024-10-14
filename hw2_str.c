#include <stdio.h>
#include <ctype.h>
#include <string.h>
// #include "hw2.h"

int is_vowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void convert_case(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_vowel(str[i])) {
            str[i] = toupper(str[i]);
        } else {
            str[i] = tolower(str[i]);
        }
    }
}

int count_substr(const char *str, const char *substr) {
    int count = 0;
    int len = strlen(substr);
    
    // Traverse the string
    for (int i = 0; str[i] != '\0'; i++) {
        // Check for substring occurrence
        if (strncasecmp(&str[i], substr, len) == 0) {
            count++;
            i += len - 1; // Allow overlapping
        }
    }
    
    return count;
}

int str_interleave(char *str1, char *str2, char *substr) {
    if (str1 == NULL || str2 == NULL || substr == NULL) {
        printf("Invalid input\n");
        return -1;
    }

    printf("str1 %s\n", str1);
    printf("str2 %s\n", str2);

    // Find length of interleaved string
    int len1 = strlen(str1), len2 = strlen(str2);
    int max_len = len1 + len2;
    
    char newstr[max_len + 1]; // +1 for null-terminator
    int index = 0;

    // Interleave characters
    for (int i = 0; i < max_len; i++) {
        if (i < len1) newstr[index++] = str1[i];
        if (i < len2) newstr[index++] = str2[i];
    }
    newstr[index] = '\0';

    // Convert vowels to uppercase and consonants to lowercase
    convert_case(newstr);

    // Print manipulated new string
    printf("newstr %s\n", newstr);

    // Print substr
    printf("substr %s\n", substr);

    // Count occurrences of substr in newstr
    int occurrences = count_substr(newstr, substr);
    printf("occurrences %d\n", occurrences);

    return 0;
}


// Test the function
// int main() {
//     str_interleave("Rendell", "Padu", "d");
//     return 0;
// }
