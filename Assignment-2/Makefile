# make/ make all- to create executables
# make run- to run program

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -Wall -Wextra -pedantic

# target name
TARGET = hi
SRC = $(TARGET1).cpp
OBJ = $(TARGET1).o

# Default rule
all: $(TARGET1)
	@echo "Build complete. Executable: $(TARGET1)"
	@echo "'make run' to run program"
#	@echo "'make second' to run second question"

# Link the executable
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
	@echo "Linking complete. Created executable: $@"

# Compile source files to object files
%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

# run programs
run: $(TARGET1)
	./$(TARGET1)

# second: $(TARGET2)
#	 ./$(TARGET2)

# Clean up generated files
clean:
	rm -rf $(OBJ) $(TARGET)
	@echo "Cleaned up generated files."

# Phony targets
.PHONY: all clean
