CC = gcc
CFLAGS = -Wall -Wextra -I../include -g

OBJDIR = ../obj
BINDIR = ../bin
TARGET = $(BINDIR)/client

SRCS = mystrfunctions.c myfilefunctions.c main.c
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

.PHONY: all clean

all: $(TARGET)

# build target by linking objects
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# rule to build any .o from its .c
$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
