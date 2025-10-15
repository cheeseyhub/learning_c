CC = cc
CFLAGS = -Wall
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
TARGET = test
SOURCE = test.c

# Primary target: 'test' depends on 'test.c'
# The command runs the compiler with flags, specifies the output file (-o $(TARGET)), 
# and links the necessary Raylib libraries.
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET) $(LIBS)

# Phony target: A command that is not a file
.PHONY: clean

# Removes the compiled binary
clean:
	rm -f $(TARGET)

