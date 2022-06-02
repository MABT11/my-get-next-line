#ifndef __GET_NEXT_LINE_H__
#define __GET_NEXT_LINE_H__

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*edit_static(char *buffer);
char	*read_until_token(char *buffer);
char	*read_to_buffer(int fd, char *buffer);
char	*get_next_line(int fd);
#endif
