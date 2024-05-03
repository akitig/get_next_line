#include "get_next_line.h"
#include <fcntl.h>
#include <libgen.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

char	*get_next_line(int fd);
int	main(void)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open("test1.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
	return (0);
}

/*
void	end(void)__attribute__((destructor));
void	end(void)
{
	system("leaks a.out");
}
*/
