# Variables
GLIBC_INSTALL=$(shell pwd)/../glibc-install
# Install dir dont have gcc
CC=gcc
CFLAGS=-g -O0 -Wall -I$(GLIBC_INSTALL)/include  -static -static-libgcc -static-libstdc++
LDFLAGS=-L$(GLIBC_INSTALL)/lib
LDLIBS=-lm

# Targets
.PHONY: all clean


# Source files
SRCS = a.c
OBJS = $(SRCS:.c=.o)
TARGET = executable

# Build rule
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

pthread: pthread.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

pthread_mutex: pthread_mutex.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

pthread_spinlock: pthread_spinlock.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

# Compile rule
%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
