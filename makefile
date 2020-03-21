.PHONY:clean

CC = gcc
CFLAGS = -Wall -g
TARGET = test.out
OBJS = clist.o cstack.o test.o

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c %.h
	$(CC) $(CFLAGS) -c $^ 

clean:
	rm -rf *.o $(TARGET)
