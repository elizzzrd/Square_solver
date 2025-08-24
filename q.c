#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*program_t)();

const char *options[] = {
	"-help",
	"-tests",
	"-solve"
}; 

char getchoice(char *choice);

int main(int argc, char *argv[])
{
    char *option = argv[1];
    printf("%s\n", option);

	//program_t program_todo;
	char choice = getchoice(option);

    printf("%c", choice);

    return 0;
}

char getchoice(char *choice)
{
	size_t index = sizeof(options)/ sizeof(options[0]);
	for (size_t i = 0; i < index; i++)
	{
		if (strcmp(options[i], choice) == 0)
		{
			return (options[i][1]);
		}
	}

    printf("Sorry, you command has not been found.\n");
	return ('n');
}
