#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_list
{
    char            *content;
    struct s_list   *next;
}               t_list; 

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *s);
char	**ft_split(char *s, char c);