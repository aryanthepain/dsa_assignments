# make/ make all- to create executables
# make run- to run program

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -Wall -Wextra -pedantic

# target name
TARGET = matrix_multiplication
SRC = $(TARGET).cpp
OBJ = $(TARGET).o

# Default rule
all: $(TARGET)
	@echo "Build complete. Executable: $(TARGET)"
	@echo "'make run' to run program"

# Link the executable
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
	@echo "Linking complete. Created executable: $@"

# Compile source files to object files
%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

# run programs
run: $(TARGET)
	./$(TARGET)

#to add to github repo
#make git m="message" b="your-branch(main by defualt)"
b?=main
m?=$(shell date '+%Y-%m-%d %H:%M:%S')
git: 
	git add .
	git commit -m "$(m)"
	git push origin $(b)

push:
	git push origin $(b)

# Clean up generated files
clean:
	rm -rf $(OBJ) $(TARGET)
	@echo "Cleaned up generated files."

# Phony targets
.PHONY: all clean
