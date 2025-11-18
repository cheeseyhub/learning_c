cc= gcc
CFLAGS= -I./include -Wall
TARGET = main
SOURCES = main.c

# if separate build for windows and linux
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
    LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -lXi -lXrandr
else
    LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm
endif

$(TARGET): $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) $(LIBS) -o $(TARGET)







