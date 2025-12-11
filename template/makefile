CC = gcc
WIN_CC = x86_64-w64-mingw32-gcc
MAC_CC = clang 
CFLAGS = -O3 -I./include -I./raygui-4.0/src -Wall

TARGET = main
WIN_TARGET = main.exe
MAC_TARGET = main_mac 
SOURCES = main.c


LIBS_LINUX = -L./lib/linux -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

LIBS_WIN = -L./lib/windows -lraylib -lopengl32 -lgdi32 -lwinmm -static

LIBS_MAC = -L./lib/macos/ -lraylib -framework CoreVideo -framework Cocoa -framework OpenGL -framework IOKit -lm


all: $(TARGET)

build-all: all windows macos

$(TARGET): $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) $(LIBS_LINUX) -o $(TARGET)

windows: $(SOURCES)
	$(WIN_CC) $(SOURCES) $(CFLAGS) $(LIBS_WIN) -o $(WIN_TARGET)

mac: $(SOURCES)
	$(MAC_CC) $(SOURCES) $(CFLAGS) $(LIBS_MAC) -o $(MAC_TARGET)

clean:
	rm -f $(TARGET) $(WIN_TARGET) $(MAC_TARGET)
