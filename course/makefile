# Compiler settings
CC = g++
CXXFLAGS = -Iinclude -Wall -Wextra -pedantic

# Directories for source files and object files
SRCDIRS = array df
OBJDIR = obj
EXECUTABLE = $(OBJDIR)/heyyo

# Gather all source files from specified directories
SOURCES = EDA.cpp $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))
OBJECTS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SOURCES))

# Temporary files and plots that need to be deleted
TEMPFILES = temp_data.txt
PLOT_DIR = plots

# Default target to build the executable
all: $(EXECUTABLE)
	@echo "Build complete. Executable: $(EXECUTABLE)"

# Target to run the executable
run: all
	time ./$(EXECUTABLE)

# Link object files to create the executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
	@echo "Linking complete. Created executable: $@"

# Compile source files into object files
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@mkdir -p $(@D)
	$(CC) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

# Ensure the object directory exists
$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "Created directory: $(OBJDIR)"

# Git operations for version control
branch?=main
message?=$(shell date '+%d-%m-%Y %H:%M:%S')
git:
	git add .
	git commit -m "$(message)"
	git push origin $(branch)

push:
	git push origin $(branch)

# Clean up build artifacts
clean:
	rm -rf $(OBJDIR) $(PLOT_DIR)/* $(TEMPFILES)
	@echo "Cleaned up generated files."

# Declare phony targets
.PHONY: all run git push clean