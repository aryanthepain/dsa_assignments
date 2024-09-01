# make/ make all- to create executables
# make run- to run program

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -Wall -Wextra -pedantic

# target name
TARGET = hi
TARGET1 = stl
SRC = $(TARGET).cpp
SRC1 = $(TARGET1).cpp
OBJ = $(TARGET).o
OBJ1 = $(TARGET1).o

N=1000000000

# Default rule
all: $(TARGET) $(TARGET1)
	@echo "Build complete. Executable: $(TARGET)"
	@echo "Build complete. Executable: $(TARGET1)"
	@echo "'make run' to run first program"

# Link the executable
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
	@echo "Linking complete. Created executable: $@"
	
$(TARGET1): $(OBJ1)
	$(CXX) -o $@ $(OBJ1)
	@echo "Linking complete. Created executable: $@"

# Compile source files to object files
%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

# run programs
run: $(TARGET)
	./$(TARGET)
	
first: $(TARGET1)
	./$(TARGET1)

#time the functions
time: $(TARGET)
	@time -v ./$(TARGET) $(N)

stltime: $(TARGET1)
	@time -v ./$(TARGET1) $(N)

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
	rm -rf $(OBJ) $(TARGET) $(OBJ1) $(TARGET1)
	@echo "Cleaned up generated files."

# Phony targets
.PHONY: all clean
