CC = gcc

CFLAGS = -Wall -g

LIBRARY = hw2.a

OBJS = hw2_str.o hw2_myprintf.o

all: $(LIBRARY)

$(LIBRARY): $(OBJS)
	ar rcs $(LIBRARY) $(OBJS)

hw2_str.o: hw2_str.c hw2.h
	$(CC) $(CFLAGS) -c hw2_str.c

hw2_myprintf.o: hw2_myprintf.c hw2.h
	$(CC) $(CFLAGS) -c hw2_myprintf.c

clean:
	rm -f $(OBJS) $(LIBRARY)