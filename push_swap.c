#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *stack_a;
    char *str;
    char **split;
    int count;

    if (argc == 1)
        return (0);
    count = 0;
    str = ft_strdup("");
    while (++count < argc)
        str = ft_strjoin(str, argv[count]);
    split = ft_split(str, ' ');
    printf("%s", split[1]);
    printf("%s", split[2]);
    
}