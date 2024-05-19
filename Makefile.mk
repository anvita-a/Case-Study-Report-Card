# Compiler
CC = /usr/bin/gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Target executable
TARGET = case_study

# Object files
OBJS = case_study_mainfile.o functions.o

# Default target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Object file dependencies
case_study_mainfile.o: case_study_mainfile.c student.h
	$(CC) $(CFLAGS) -c case_study_mainfile.c

functions.o: functions.c student.h
	$(CC) $(CFLAGS) -c functions.c

# Clean target
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: clean
