# Makefile for Player_Data project

CC = gcc
CFLAGS = -I./include
SRCDIR = src
BUILDDIR = build
TARGET = $(BUILDDIR)/player_data

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
    $(CC) $(OBJECTS) -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(BUILDDIR)/*.o $(TARGET)

.PHONY: all clean
