# src/Makefile - builds static and dynamic libs + clients

CC = gcc
CFLAGS = -Wall -Wextra -I../include -g
OBJDIR = ../obj
BINDIR = ../bin
LIBDIR = ../lib

UTIL_SRCS = mystrfunctions.c myfilefunctions.c
UTIL_OBJS = $(UTIL_SRCS:%.c=$(OBJDIR)/%.o)
MAINOBJ = $(OBJDIR)/main.o

LIB_STATIC = $(LIBDIR)/libmyutils.a
LIB_DYNAMIC = $(LIBDIR)/libmyutils.so
TARGET_STATIC = $(BINDIR)/client_static
TARGET_DYNAMIC = $(BINDIR)/client_dynamic

.PHONY: all clean dirs

all: $(TARGET_STATIC) $(TARGET_DYNAMIC)

# compile object files normally (for static lib)
$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# static library
$(LIB_STATIC): $(UTIL_OBJS)
	ar rcs $@ $^
	ranlib $@

# dynamic library (requires -fPIC)
$(LIB_DYNAMIC): $(UTIL_SRCS)
	$(CC) $(CFLAGS) -fPIC -c mystrfunctions.c -o $(OBJDIR)/mystrfunctions.o
	$(CC) $(CFLAGS) -fPIC -c myfilefunctions.c -o $(OBJDIR)/myfilefunctions.o
	$(CC) -shared -o $@ $(OBJDIR)/mystrfunctions.o $(OBJDIR)/myfilefunctions.o

# compile main
$(MAINOBJ): main.c
	$(CC) $(CFLAGS) -c $< -o $@

# link static client
$(TARGET_STATIC): $(MAINOBJ) $(LIB_STATIC)
	$(CC) $(CFLAGS) $(MAINOBJ) -L$(LIBDIR) -lmyutils -o $@

# link dynamic client
$(TARGET_DYNAMIC): $(MAINOBJ) $(LIB_DYNAMIC)
	$(CC) $(CFLAGS) $(MAINOBJ) -L$(LIBDIR) -lmyutils -o $@

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(TARGET_STATIC) $(TARGET_DYNAMIC)
	rm -f $(LIB_STATIC) $(LIB_DYNAMIC)
