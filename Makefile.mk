CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = case_study
OBJS = case_study_mainfile.o functions.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

case_study_mainfile.o: case_study_mainfile.c student.h
	$(CC) $(CFLAGS) -c case_study_mainfile.c

functions.o: functions.c student.h
	$(CC) $(CFLAGS) -c functions.c

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: clean
