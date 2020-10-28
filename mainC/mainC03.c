int main()
{
	char s1[] = "vest";
	char s2[] = "uest";
	printf("%i", ft_strcmp(s1, s2));
	return (0);
}

int main(void)
{
	char s1[] = "tesT";
	char s2[] = "test";
	printf("%i", ft_strncmp(s1, s2, 3));
	return (0);
}

int main(void)
{
	char dest[20] = "Hello";
	char src[20] = "";
	char dest2[20] = "Hello";
	char src2[20] = "";
	printf("%s\n", ft_strcat(dest, src));
	printf("%s\n", strcat(dest2, src2));
	return (0);
}

int main(void)
{
	char dest[30] = "Hello";
	char src[] = "Word";
	char dest2[30] = "Hello";
	char src2[] = "Word";
	printf("dest = %s\n", ft_strncat(dest, src, 2));
	printf("dest = %s", strncat(dest2, src2, 2));
	return (0);
}

int main(void)
{
	char str[100] = "Hello World Wrld";
	char tofind[10] = "Wrldd";
	printf("%s\n", ft_strstr(str, tofind));
	printf("%s", strstr(str, tofind));
	return (0);
}

int main(void)
{
	char dest[30] = "Hello";
	char src[] = "World";
	char dest2[30] = "Hello";
	char strtest[] = "World";
	printf("dest = %s | Return function = %i\n", dest, ft_strlcat(dest, src, 30));
	printf("dest = %s | Return function = %lu\n", dest2, strlcat(dest2, strtest, 30));
	return (0);
}
