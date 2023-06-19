CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SRCDIR = src
INCDIR = include
BUILDDIR = build
TARGET = seso

# Archivos fuente
SOURCES = $(wildcard $(SRCDIR)/*.c)
# Archivos objeto generados a partir de los archivos fuente
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))
# Dependencias de los archivos objeto
DEPS = $(wildcard $(INCDIR)/*.h)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(BUILDDIR)/*.o $(TARGET)
