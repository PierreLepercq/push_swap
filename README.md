*This project has been created as part of the 42 curriculum by <plepercq>*.

# Get Next Line

[Subject](https://cdn.intra.42.fr/pdf/pdf/188916/en.subject.pdf)

### Description

**Get Next Line** is a function written in C whose goal is to return, for a given file descriptor, its content line by line. Each call of the function returns either the next line from the file pointed to by the file descriptor, or NULL if an error occurs or if the offset met the end of the file.

This project introduces us to static variables. Static means they remain in memory even after exiting the function where they have been declared. Static variables are very useful to save an execution state or stash anything for a later function call.

Last but not least, as part of the "Get Next Line" functionalities, the buffer size in which the "read" system call puts its content, had to be defined by the user upon compilation, with the flag '-D BUFFER_SIZE = <42>'. If the buffer size is not defined by the user, it is defined by a default global variable, which I chose to set to 100.

### Instructions
You can test this function by adding a 'main.c' file at the root of the folder, and then compile it as follows :
'''
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c
./a.out
'''

Here you will find an exemple of 'main.c' file content:
'''
#include "get_next_line.h"
#include <fcntl.h>  // For open
#include <stdio.h>  // For printf
#include <stdlib.h> // For free
#include <unistd.h> // For read, write, close

int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open("./README.md", O_RDONLY);
	while (i < 70)
	{
		line = get_next_line(fd);
		printf("line [%i] : %s\n", i, line);
		if (line != NULL)
			free(line);
		i++;
	}
	close(fd);
}
'''

### Algorithm Explanations
For this project, i choosed to use the Turk Algorithm.

### Resources
Here you can find the resources which helped me during this project
 - [YT - push_swap : a performant sorting algorithm using 2 stacks (100-630 moves | 500-5470 moves)](https://www.youtube.com/watch?v=OaG81sDEpVk)
 - [YT - push_swap TUTORIAL!](https://www.youtube.com/watch?v=wRvipSG4Mmk)
