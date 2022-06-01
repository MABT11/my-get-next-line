#include "get_next_line.h"
// #define BUFFER_SIZE 2

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if(s[i] == (char)c)
			return (s + i);
		i++;
	}
	if (s[i] == c)
		return (s + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[i - ft_strlen(s1)])
	{
		s3[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	s3[i] = '\0';
	return (s3);
}
char *read_to_buffer(int fd, char *buffer)
{
	char	*string;
	int		i;

	if(!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if(!buffer)
			return NULL;
	}
	string = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
	string = (char *)malloc(sizeof(char) * (i + 2));
	if(!string)
		return NULL;
	string[0] = 0;
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
	temp = (char*)malloc(sizeof(char)*(ft_strlen(buffer)-i+1));
	if(!temp)
		return (NULL);
	temp[0] = 0;
	j = 0;
	i++;
	while(buffer[i] && i<ft_strlen(buffer))
	{
		temp[j++] = buffer[i++];
	}
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
		return NULL;
	string = read_until_token(buffer);
	if(!string)
		return NULL;
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