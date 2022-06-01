#include "get_next_line.h"
#define BUFFER_SIZE 2

char *read_to_buffer(int fd, char *buffer)
{
	char	*string;
	int		i;

	if(!buffer)
	{
		buffer = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if(!buffer)
			return NULL;
	}
	string = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if(!string)
		return NULL;
	i = 1;
	while(i > 0)
	{
		i = read(fd, string, BUFFER_SIZE);
		if(i == -1)
		{
			free(string);
			return NULL;
		}
		string[BUFFER_SIZE] = 0;
		buffer = ft_strjoin(buffer, string);
		if(ft_strchr(string,'\n'))
			break;
	}
	free(string);
	return (buffer);
}
char *read_until_token(char *buffer)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	while(buffer[i] && buffer[i]!='\n')
		i++;
	string = (char *)ft_calloc(sizeof(char), (i + 2));
	if(!string)
		return NULL;
	j = i;
	i = 0;
	while(buffer[i] && i<=j)
	{
		string[i] = buffer[i];
		i++;
	}
	string[i] = 0;
	return (string);
}
char *edit_static(char *buffer)
{
	char	*temp;
	size_t	i;
	int		j;

	i = 0;
	while(buffer[i] && buffer[i]!='\n')
		i++;
	temp = (char*)ft_calloc(sizeof(char), (ft_strlen(buffer) - i + 1));
	if(!temp)
		return (NULL);
	j = 0;
	i++;
	while(buffer[i] && i < ft_strlen(buffer))
		temp[j++] = buffer[i++];
	free(buffer);
	temp[i] = 0;
	return (temp);
}
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*string;
	int j;

	j = 1;
	//guards
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = read_to_buffer(fd,buffer);
	if(!buffer)
		return (NULL);
	string = read_until_token(buffer);
	if(!string)
		return (NULL);
	buffer = edit_static(buffer);
	return (string);
}

int main()
{
    int fd = open("foo.txt", O_RDONLY);
	char *b;
	// for(int i = 0; i <7; i++)
	// {
		b = get_next_line(fd);
		printf("%s", b);
	// }
	free(b);
		b = get_next_line(fd);
		printf("%s", b);
	// }
	free(b);	b = get_next_line(fd);
		printf("%s", b);
	// }
	free(b);	b = get_next_line(fd);
		printf("%s", b);
	// }
	free(b);	b = get_next_line(fd);
		printf("%s", b);
	// }
	free(b);
	close(fd);
}