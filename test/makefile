CC = gcc

OBJS = *.c

all: test_sqlite test_libcurl test_cJSON test_haversine test_wrapField test_libxml test_WcJSON


test_sqlite: test_sqlite.o
	$(CC) $^ -o $@ -lm -lsqlite3
	
test_sqlite.o: test_sqlite.c
	$(CC) -c $< -o $@ -lm -lsqlite3

test_libcurl: test_libcurl.o
	$(CC) $^ -o $@ -lm -lcurl
	
test_libcurl.o: test_libcurl.c
	$(CC) -c $< -o $@ -lm -lcurl

test_cJSON: test_cJSON.o cJSON.o
	$(CC) $^ -o $@
	
test_cJSON.o: test_cJSON.c cJSON.c
	$(CC) -c $< -o $@

test_WcJSON: test_WcJSON.o cJSON.o
	$(CC) $^ -o $@
	
test_WcJSON.o: test_WcJSON.c cJSON.c
	$(CC) -c $< -o $@

test_haversine: test_haversine.o
	$(CC) $^ -o $@ -lm
	
test_haversine.o: test_haversine.c
	$(CC) -c $< -o $@ -lm

test_wrapField: test_wrapField.o
	$(CC) $^ -o $@
	
test_wrapField.o: test_wrapField.c
	$(CC) -c $< -o $@ 

test_libxml: test_libxml.o
	$(CC) $^ -o $@ -I/usr/include/libxml2 -lxml2
	
test_libxml.o: test_libxml.c
	$(CC) -c $< -o $@ -I/usr/include/libxml2 -lxml2

.c.o:
	$(CC) $(CFLAGS) -g -Wall -c $<

clean:
	rm -f a.out test_sqlite test_libcurl test_cJSON test_haversine test_wrapField test_libxml test_WcJSON *.o *.db core
