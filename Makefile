SOURCE_DIR = src
BUILD_DIR = build
INCLUDE = include

CC = g++
CFLAGS = -I$(INCLUDE)
DEPS = $(INCLUDE)

SRC = $(wildcard $(SOURCE_DIR)/*.cpp)
OBJ = $(patsubst $(SOURCE_DIR)/%.cpp, $(BUILD_DIR)/%.o ,$(SRC))
TARGET = pid_controller

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@


$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $^ -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm $(OBJ)
