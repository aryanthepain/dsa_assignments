# Compiler
CC = g++

# Compiler flags
CXXFLAGS = -Iinclude -Wall -Wextra -pedantic

# Source and object files
SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))
OBJ_NAME = tree

# Default rule
all: $(OBJ_NAME)
	@echo "Build complete. Executable: $(OBJ_NAME)"

run: all
	./${OBJ_NAME}

# Link the executable
$(OBJ_NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
	@echo "Linking complete. Created executable: $@"

# Compile source files to object files
%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

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
	rm -rf $(OBJECTS) $(OBJ_NAME)
	@echo "Cleaned up generated files."

# Phony targets
.PHONY: all clean
