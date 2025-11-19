cc= gcc
CFLAGS= -I./include -Wall
TARGET = main
SOURCES = main.c

# Comment out the line which is not desired
#
# These libs are for linux systems 
#
LIBS = -L./libs/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# These libs are for windows systems 
#
#LIBS = -L./libs/ -lraylib -lopengl32 -lgdi32 -lwinmm

$(TARGET): $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) $(LIBS) -o $(TARGET)







