#ifndef HW2_H
#define HW2_H

int myprintf(const char *format, ...);

// Redirecting printf calls => myprintf
#define printf myprintf

// Define the MYMSG macro
#define MYMSG(format, ...) { \
    myprintf("Original message--> %s:%d: " format, __FILE__, __LINE__, __VA_ARGS__); \
    }

#endif // HW2_H