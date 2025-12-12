CC = gcc
C_FLAGS = -O2 -lm -lpthread -ldl 

TARGET = main
SOURCES = main.c 
LIB_OBJECT = sqlite3.o 

all: $(TARGET)

$(LIB_OBJECT): sqlite3.c
	$(CC) -c sqlite3.c -o $@ $(C_FLAGS)

$(TARGET): $(SOURCES) $(LIB_OBJECT)
	$(CC) $(SOURCES) $(LIB_OBJECT) -o $(TARGET) $(C_FLAGS)

clean:
	rm -f $(TARGET) *.o
