# \file
# \brief Makefile for building the project
# 
# This Makefile compiles the source files located in the specified directories,
# links them into an executable, and provides targets for running the executable,
# cleaning up build artifacts, and performing Git operations.

# Compiler settings
CC = g++
CXXFLAGS = -Iinclude -Wall -Wextra -pedantic

# \brief Directories for source files and object files
# \var SRCDIRS
# Directories containing source files
SRCDIRS = array df

# \var OBJDIR
# Directory for storing object files
OBJDIR = obj

# \var EXECUTABLE
# The name of the final executable
EXECUTABLE = $(OBJDIR)/heyyo

# \brief Gather all source files from specified directories
# \var SOURCES
# List of source files to be compiled
SOURCES = EDA.cpp $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))

# \var OBJECTS
# List of object files generated from the source files
OBJECTS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SOURCES))

# \brief Temporary files and plots that need to be deleted
# \var TEMPFILES
# List of temporary files to be cleaned
TEMPFILES = temp_data.txt

# \var PLOT_DIR
# Directory for storing plot files
PLOT_DIR = plots

# \brief Default target to build the executable
all: $(EXECUTABLE)
	@echo "Build complete. Executable: $(EXECUTABLE)"

# \brief Target to run the executable
run: all
	time ./$(EXECUTABLE)

# \brief Link object files to create the executable
# \param $(EXECUTABLE) The name of the executable to create
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
	@echo "Linking complete. Created executable: $@"

# \brief Compile source files into object files
# \param $(OBJDIR)/%.o The object file to be created
# \param %.cpp The source file to compile
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@mkdir -p $(@D)
	$(CC) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

# \brief Ensure the object directory exists
$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "Created directory: $(OBJDIR)"

# \brief Git operations for version control
# \var branch
# The branch to push changes to (default: main)
branch?=main

# \var message
# The commit message (default: current date and time)
message?=$(shell date '+%d-%m-%Y %H:%M:%S')

# \brief Perform Git operations: add, commit, and push
git:
	git add .
	git commit -m "$(message)"
	git push origin $(branch)

# \brief Push changes to the remote Git repository
push:
	git push origin $(branch)

# \brief Clean up build artifacts
clean:
	rm -rf $(OBJDIR) $(PLOT_DIR)/* $(TEMPFILES)
	@echo "Cleaned up generated files."

# \brief Declare phony targets
.PHONY: all run git push clean