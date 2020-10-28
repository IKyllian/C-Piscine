int		main (void)
{
//	char str1[] = "Hello";
//	char str2[] = "World";
//	char str3[] = "Ceci";
//	char str4[] = "Est";
//	char str5[] = "Un";
//	char str6[] = "Test";
	char str7[] = " ";
	char *str[] = {str7};
	char *sep = ",";
	printf("%s", ft_strjoin(1, str, sep));
	return (0);
}

int main()
{
	int min = 0;
	int max = 10;
	int *tab = ft_range(min, max);
	int i = 0;
	while (i < (max - min) && tab != NULL)
	{
		printf("%i\n", tab[i]);
		i++;
	}
}

int		main(void)
{
	char str[] = "Ceci e,st un te,st";
	char charset[] = ",";
	char **final_str = ft_split(str, charset);
	int i = 0;
	while (final_str[i] != 0)
	{
		printf("%s\n", final_str[i]);
		i++;
	}
}
