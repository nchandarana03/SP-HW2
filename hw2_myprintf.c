#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int myprintf(const char *format, ...) {
    va_list args;
    int numof_chars_printed = 0;
    int temp_char_count = 0;
    const char *iterator;
    char ch;
    int int_val;
    char *str;

    va_start(args, format);
    
    for (iterator = format; *iterator != '\0'; iterator++) {
        if (*iterator == '%') {
            iterator++;
            
            if (*iterator == 'c') {
                ch = (char) va_arg(args, int);
                temp_char_count = printf("%c", ch);
                numof_chars_printed += temp_char_count;
            }
            else if (*iterator == 'd') {
                int_val = va_arg(args, int);
                temp_char_count = printf("%d", int_val);
                numof_chars_printed += temp_char_count;
            }
            else if (*iterator >= '1' && *iterator <= '9') {
                int width = *iterator - '0';
                iterator++;  
                
                if (*iterator == 'd') {
                    int_val = va_arg(args, int);
                    temp_char_count = printf("%0*d", width, int_val);  
                    numof_chars_printed += temp_char_count;
                } else {
                    va_end(args);
                    printf("Error: Unsupported format specifier.\n");
                    return -1;
                }
            }
            else if (*iterator == 's') {
                str = va_arg(args, char *);
                temp_char_count = printf("%s", str);
                numof_chars_printed += temp_char_count;
            } else {
                va_end(args);
                printf("Error: Format not recognized.\n");
                return -1;
            }
        } else {
            temp_char_count = printf("%c", *iterator);
            numof_chars_printed += temp_char_count;
        }
    }

    printf("\nArgument list:\n");
    va_start(args, format);

    for (iterator = format; *iterator != '\0'; iterator++) {
        if (*iterator == '%') {
            iterator++;
            
            if (*iterator == 'c') {
                ch = (char) va_arg(args, int);
                printf("Char --> %c\n", ch);
            }
            else if (*iterator == 'd' || (*iterator >= '1' && *iterator <= '9' && iterator[1] == 'd')) {
                int_val = va_arg(args, int);
                printf("Integer --> %d\n", int_val);
            }
            else if (*iterator == 's') {
                str = va_arg(args, char *);
                printf("String --> %s\n", str);
            }
        }
    }

    va_end(args);
    return numof_chars_printed;
}

// Code 
// int main() {
//     int r = myprintf("This is CS%c%5d%s", '-', 551, " Systems Programming.\n");
//     printf("Return value: %d\n", r);
//     return 0;
// }
