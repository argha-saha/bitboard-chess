# Compiler
CXX = g++

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Compiler flags
CXXFLAGS = -std=c++17 `pkg-config --cflags sdl3` -I$(INC_DIR)
LDFLAGS = `pkg-config --libs sdl3`

# Target executable
TARGET = chess

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Make sure the build directory exists
$(shell mkdir -p $(BUILD_DIR))

# Default target
all: $(TARGET)

# Compile the program
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(TARGET) $(BUILD_DIR)/*.o
	rmdir $(BUILD_DIR) 2>/dev/null || true

# Phony targets
.PHONY: all clean