CC		:= gcc
CFLAGS	:= -O0 -g -Wall
BUILD	:= build
TARGET	:= program.elf
SRCDIR	:= src
HDRS	:= -Ihdr
SRCS	:= $(wildcard $(SRCDIR)/*.c)
OBJS	:= $(patsubst $(SRCDIR)/%.c,$(BUILD)/%.o,$(SRCS))
DEPS	:= $(patsubst $(SRCDIR)/%.c,$(BUILD)/%.d,$(SRCS))

.PHONY = all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(HDRS) -c $< -o $@

$(BUILD)/%.d: $(SRCDIR)/%.c | $(BUILD)
	$(CC) $(HDRS) -MM -MT $(BUILD)/$*.o $< > $@
	
include $(DEPS)

$(BUILD):
	mkdir build

clean:
	rm -rf \
	$(TARGET) \
	$(BUILD) \
	my_core.*
