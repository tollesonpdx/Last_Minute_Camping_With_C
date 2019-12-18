CC = gcc

all: 1.out 2.out 3.out 4.out 5.out 6.out

1.out: 1.c
	$(CC) $^ -o $@ -lm -l sqlite3

2.out: 2.c
	$(CC) $^ -o $@ -lm -l sqlite3

3.out: 3.c
	$(CC) $^ -o $@ -lm -l sqlite3

4.out: 4.c
	$(CC) $^ -o $@ -lm -l sqlite3

5.out: 5.c
	$(CC) $^ -o $@ -lm -l sqlite3

6.out: 6.c
	$(CC) $^ -o $@ -lm -l sqlite3

.c.o:
	$(CC) $(CFLAGS) -g -Wall -c $<

clean:
	rm -f *.out *.o *.db core
