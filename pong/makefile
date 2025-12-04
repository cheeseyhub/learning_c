CC = gcc
WIN_CC = x86_64-w64-mingw32-gcc
CFLAGS = -I./include -I./raygui-4.0/src -Wall
TARGET = main
WIN_TARGET = main.exe
SOURCES = main.c

# Linux libraries
LIBS_LINUX = -L./lib/linux -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Windows libraries
LIBS_WIN = -L./lib/windows -lraylib -lopengl32 -lgdi32 -lwinmm -static

# Default target for Linux
all: $(TARGET)

build-all: all windows

$(TARGET): $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) $(LIBS_LINUX) -o $(TARGET)

# Target for Windows
windows: $(SOURCES)
	$(WIN_CC) $(SOURCES) $(CFLAGS) $(LIBS_WIN) -o $(WIN_TARGET)

clean:
	rm -f $(TARGET) $(WIN_TARGET)
