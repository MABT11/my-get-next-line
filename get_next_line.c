#include "get_next_line.h"
// #define BUFFER_SIZE 20
/*
char *read_to_buffer(int fd, char *buffer)
{
	char	*string;
	int		j;

	string = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!string)
		return (NULL);
	j = 1;
	while (!ft_strchr(buffer, '\n') && j != 0)
	{
		j = read(fd, string, BUFFER_SIZE);
		if (j == -1)
		{
			free(string);
			return (NULL);
		}
		string[j] = '\0';
		buffer = ft_strjoin(buffer,string);
	}
	free(string);
	return (buffer);
}
char *read_until_token(char *buffer)
{
		int		i;
	char	*s;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	s = (char *)ft_calloc(sizeof(char), (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		s[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		s[i] = buffer[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char *edit_static(char *buffer)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	s = (char *)ft_calloc(sizeof(char), (ft_strlen(buffer) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (buffer[i])
		s[c++] = buffer[i++];
	s[c] = '\0';
	free(buffer);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*string;

	//guards
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = read_to_buffer(fd,buffer);
	if(!buffer)
		return (NULL);
	string = read_until_token(buffer);
	// if(!string)
	// 	return (NULL);
	buffer = edit_static(buffer);
	return (string);
}*/
/*edited code*/
char	*ft_strjoin(char *s1, char *s2)
{
	char *s3;
	int i;
	int j;

	if(!s1)
	{
		s1 = ft_calloc(1,sizeof(char));
		s1[0] = 0;
	}
	s3 = ft_calloc(ft_strlen(s1)+ft_strlen(s2)+1, sizeof(char));
	if(!s3|| !s1 || !s2)
		return NULL;
	i = -1;
	while(s1[++i])
		s3[i]=s1[i];
	j=0;
	while(s2[j])
		s3[i++] = s2[j++];
	s3[i]=0;
	free(s1);
	return s3;
}
char *ft_read(int fd,char *s)
{
	char *readn;
	int n_bytes;

	readn = ft_calloc(BUFFER_SIZE+1,sizeof(char));
	if(!readn)
		return NULL;
	n_bytes = 1;
	while(n_bytes != 0 &&!ft_strchr(readn,'\n'))
	{
		n_bytes = read(fd, readn, BUFFER_SIZE);
		if(n_bytes == -1)
		{
			free(readn);
			return NULL;
		}
		readn[n_bytes] = 0;
		s = ft_strjoin(s,readn);
	}
	free(readn);
	return s;
}
char *ft_read_line(char *s)
{
	char *line;
	int i;
	
	i = 0;
	if (!s[i])
		return (NULL);
	while(s[i] && s[i]!='\n')
		i++;
	line = ft_calloc(i+2,sizeof(char));
	if(!line)
		return NULL;
	i = 0;
	while(s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if(s[i]== '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = 0;
	return line;
}
char *ft_edit_static(char *s)
{
	char *temp;
	int i;
	int j;

	i =0;
	while(s[i] && s[i]!='\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	temp = ft_calloc(ft_strlen(s)-i+1,sizeof(char));
	if(!temp)
		return NULL;
	j = 0;
	i++;
	while(s[i])
		temp[j++] = s[i++];
	temp[j]=0;
	free(s);
	return temp;
}
char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	line = ft_read_line(save);
	save = ft_edit_static(save);
	return (line);
}
