#include <unistd.h>


void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);

}
void    ft_last_word(char *str)
{
    int i;

    i = ft_strlen(str) - 1;
    while (str[i] == ' ' || str[i] == '\t')
       i--;
	while (str[i] != ' ' && str[i] != '\t')
		i--;
	while(str[++i] != ' ' && str[i] != '\t')
		ft_putchar(str[i]);
}

void    ft_first_word(char *str)
{
    int i;

    i = 0;
    while (!str[i] && (str[i] == ' ' || str[i] == '\t'))
       i++;
	while (str[i] != ' ' && str[i] != '\t')
		ft_putchar(str[i++]);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_first_word(argv[1]);
    }
    write(1, "\n", 1);
    return (0);
}
