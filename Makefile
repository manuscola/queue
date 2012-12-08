CC=gcc
CFLAGS=-Wall
TARGET=test
default:$(TARGET)
SOURCE=queue.c queue_test.c

all : $(TARGET)

%o:%c 
	$(CC)  $(CFLAGS) -o $@ -c $< 

$(TARGET) : queue.o queue_test.o
	$(CC) -o $@  $^

.PHONY: all clean
clean:
	rm -rf *.o
	rm -rf $(TARGET)

