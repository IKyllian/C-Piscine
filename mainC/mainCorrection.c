int main(void)
{
	int var = 78;
	int *ptr1 = &var;
	int **ptr2 = &ptr1;
	int ***ptr3 = &ptr2;
	int ****ptr4 = &ptr3;
	int *****ptr5 = &ptr4;
	int ******ptr6 = &ptr5;
	int *******ptr7 = &ptr6;
	int ********ptr8 = &ptr7;

	ft_ultimate_ft(&ptr8);
	printf("%i", var);
	return (0);
}



int main(void)
{
	int a = 84;
	int b = 6;
	int div = 0;
	int mod = 0;

	ft_div_mod(a, b, &div, &mod);
	printf("div : %i | mod : %i", div, mod);
	return(0);
}


int main(void)
{
	int a = 75;
	int b = 6;
	ft_ultimate_div_mod(&a, &b);
	printf("a = %i | b = %i", a, b);
	return (0);
}


int main()
{
	int tab[7] = {1, 2, 3, 4, 5, 6, 7};
	ft_rev_int_tab(tab, 7);
	int i = 0;
	while (i < 7)
	{
		printf("%i / ", tab[i]);
		i++;
	}
	return (0);
}


int main(void)
{
	int tab[5] = {50, 2, 89, 1, -6};
	ft_sort_int_tab(tab, 5);
	int i = 0;
	while(i < 5)
	{
		printf("%i / ", tab[i]);
		i++;
	}
	return (0);
}
