CC		:= gcc
CFLAGS	:= -O0 -g -Wall
TARGET	:= program.elf
HDRS	:= -I.
SRCS	:= $(wildcard *.c)
OBJS	:= $(patsubst %.c,%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	gcc -c $< -o $@

clean:
	$(RM) \
	$(TARGET) \
	$(OBJS)
