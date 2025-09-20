# src/Makefile - builds static lib and client

CC = gcc
CFLAGS = -Wall -Wextra -I../include -g
OBJDIR = ../obj
BINDIR = ../bin
LIBDIR = ../lib

SRCS = mystrfunctions.c myfilefunctions.c
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
MAINOBJ = $(OBJDIR)/main.o

LIB = $(LIBDIR)/libmyutils.a
TARGET = $(BINDIR)/client_static

.PHONY: all clean dirs

all: dirs $(TARGET)

dirs:
	mkdir -p $(OBJDIR) $(BINDIR) $(LIBDIR)

# compile each .c (except main) into ../obj/%.o
$(OBJDIR)/%.o: %.c | dirs
	$(CC) $(CFLAGS) -c $< -o $@

# build static library
$(LIB): $(OBJS)
	ar rcs $@ $^
	ranlib $@

# compile main separately
$(MAINOBJ): main.c | dirs
	$(CC) $(CFLAGS) -c $< -o $@

# link client against static lib
$(TARGET): $(MAINOBJ) $(LIB)
	$(CC) $(CFLAGS) $(MAINOBJ) -L$(LIBDIR) -lmyutils -o $@

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(TARGET)
	rm -f $(LIB)
