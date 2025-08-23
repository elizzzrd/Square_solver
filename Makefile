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

TARGET = program

SRCS = $(wildcard source/*.c)
HEADERS = $(wildcard headers/*.h)
OBJS = $(SRCS:.c=.o)

SRCS_DIR = source

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	del $(SRCS_DIR)\*.o


# TODO: separate target for tests
# TODO: separate PHONY: check, which runs test
# NOTE:
# tests: tests.o solver.o
# 	...
#
# check: tests
# 	./tests
