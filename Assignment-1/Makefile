# make/ make all- to create executables
# make first- run first program
# make second- run second program

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -Wall -Wextra -pedantic

# target name
TARGET1 = 230150003_1_aryan_gupta
TARGET2 = 230150003_2_aryan_gupta

SRC1 = $(TARGET1).cpp
SRC2 = $(TARGET2).cpp

OBJ1 = $(TARGET1).o
OBJ2 = $(TARGET2).o

# Default rule
all: $(TARGET1) $(TARGET2)
	@echo "Build complete. Executable: $(TARGET1), $(TARGET2)"
	@echo "'make first' to run first question"
	@echo "'make second' to run second question"

# Link the executable
$(TARGET1): $(OBJ1)
	$(CXX) -o $@ $(OBJ1)
	@echo "Linking complete. Created executable: $@"

$(TARGET1): $(OBJ1)
	$(CXX) -o $@ $(OBJ1)
	@echo "Linking complete. Created executable: $@"

# Compile source files to object files
%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

# run programs
first: $(TARGET1)
	./$(TARGET1)

second: $(TARGET2)
	./$(TARGET2)

# Clean up generated files
clean:
	rm -rf $(OBJ1) $(OBJ2) $(TARGET1) $(TARGET2)
	@echo "Cleaned up generated files."

# Phony targets
.PHONY: all clean
