# Variables
CC = gcc
RM := rm -rf
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall -Wextra $(DEBUG)
LIBS := -lm
SRC := main.c
PROF_O := gmon.out
DEPS := tads.h libs.h
OBJS := main.o
DEBUG := -g -pg
NAME := main
NAME_TAR := main_test.tar

# All Target
all: $(NAME)

# Tool invocations
$(NAME): $(OBJS)
	@echo 'Building target: $@'
	$(CC)  -o $(NAME) $(OBJS) $(LIBS) $(LFLAGS)
	@echo 'Finished building target: $@'
	@echo ' '

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(SRC)

# Other Targets
clean:
	-@echo ' '
	-@echo 'Cleaning targets: $(OBJS) $(NAME) $(PROF_O) $(NAME_TAR)'
	-$(RM) $(OBJS) $(NAME) $(PROF_O) $(NAME_TAR)
	@echo 'Finished cleaning targets'
	-@echo ' '

tar:
	@echo ' '
	@echo 'Building compressed tar file: $(NAME_TAR)'
	tar cfv $(NAME_TAR) $(SRC) $(DEPS) makefile
	@echo ' '

.PHONY: all clean
.SECONDARY:

