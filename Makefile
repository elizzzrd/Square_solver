CC = gcc

CFLAGS = -Wshadow -Winit-self -Wredundant-decls \
-Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code \
-Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum \
-Wswitch-default -Wmain -Wextra -Wall -g -pipe -fexceptions \
-Wcast-qual -Wconversion -Wempty-body -Wformat-security \
-Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers \
-Wpointer-arith -Wstack-usage=8192 -Wstrict-aliasing -Wtype-limits -Wwrite-strings \
-Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE -fdiagnostics-color=always

INCLUDES = -I headers

TARGET = square_solver

SRCS = $(wildcard source/*.c)
HEADERS = $(wildcard headers/*.h)
OBJS = $(SRCS:.c=.o)
OBJDIR := objs

SRCS_DIR = source

all: $(TARGET)

$(TARGET): $(OBJS) tests/tests.o tests/read_file.o
	@$(CC) $(OBJS) tests/tests.o tests/read_file.o -o $(TARGET)

%.o: %.c $(HEADERS)
	@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@



TEST_TARGET = test_program

TEST_SRCS = $(wildcard tests/*.c)
TEST_OBJS = $(TEST_SRCS:.c=.o)
TESTS_DIR = tests


tests: $(TEST_TARGET)
	

$(TEST_TARGET): $(TEST_OBJS) source/equation_solver.o source/floating_point_arithmetic.o 
	@$(CC) $(TEST_OBJS) source/equation_solver.o source/floating_point_arithmetic.o -o $(TEST_TARGET)


$(TESTS_DIR)/%.o: $(TESTS_DIR)/%.c $(HEADERS)
	@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@


clean:
	del $(SRCS_DIR)\*.o $(TESTS_DIR)\*.o 


check: tests
	./$(TEST_TARGET)


.PHONY: all tests check clean