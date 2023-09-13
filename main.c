/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:05:14 by aradix            #+#    #+#             */
/*   Updated: 2023/09/12 23:39:12 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <stdio.h>
#include  <string.h>
#include <stddef.h>
#include <stdlib.h>
 #include <string.h>
#include <bsd/string.h>



int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strstr(char *str, char *to_find);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);


void	test_strcmp()
{
	int	a;
	int b;

	char s[] = "aalut";
	char g[] = "ac";

	a = ft_strcmp(s, g);
	b = strcmp(s, g);
	printf(" %d  ---  %d \n", a, b);
}

void	test_strncmp()
{
	int a;
	int b;

	a = ft_strncmp("salut", "salut", 5);
	b = strncmp("salut", "salut", 5);
	printf(" %d  ---  %d \n", a, b);

	a = ft_strncmp("salut", "sblut", 2);
	b = strncmp("salut", "sblut", 2);
	printf(" %d  ---  %d \n", a, b);

	a = ft_strncmp("salut", "salut", 20);
	b = strncmp("salut", "salut", 20);
	printf(" %d  ---  %d \n", a, b);

	a = ft_strncmp("salut", "salut", 0);
	b = strncmp("salut", "salut", 0);
	printf(" %d  ---  %d \n", a, b);

	a = ft_strncmp("salut", "salux", 5);
	b = strncmp("salut", "salux", 5);
	printf(" %d  ---  %d \n", a, b);
	
}

void	test_strcat()
{
	char src[] = "salut";
	char dest[60] = "ca va#include <stddef.h> ?";

//	ft_strcat(dest, src);
	strcat(dest, src);

	printf("%s\n", dest);
}

void	test_strncat()
{
	char src[] = "salut";
	char dest[60] = "ca va ?";

	ft_strncat(dest, src, 20);

	printf("%s\n", dest);
}

void	test_strstr()
{
	char *str;
	str = malloc(sizeof(int) * 10);
	strcpy(str, "salut ca valol mdr aa");
	str = strstr(str, "salut");
	printf("%s\n", str);
}

void	test_strlcat()
{
	char src[] = "salut";
	char dest[60] = "ca va ?";

	unsigned int i = ft_strlcat(dest, src, 10);



	printf("%s---%d\n", dest, i);
}

int	main()
{
	//test_strcmp();
	//test_strncmp();
	//test_strcat();
	//test_strncat();
	//test_strstr();
	test_strlcat();
	return (0);
}
