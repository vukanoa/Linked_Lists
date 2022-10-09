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
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) \
	$(TARGET) \
	$(OBJS) \
	.*.swp \
	.*.un~ \
	my_core.*
