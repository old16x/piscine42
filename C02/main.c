#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <bsd/string.h>

char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_str_is_alpha(char *str);
int		ft_str_is_numeric(char *str);
int		ft_str_is_lowercase(char *str);
int		ft_str_is_uppercase(char *str);
int		ft_str_is_printable(char *str);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
void	ft_putstr_non_printable(char *str);
void	*ft_print_memory(void *addr, unsigned int size);

void	test_strcpy()
{
	char	destA[9];
	char	destB[9];

	ft_strcpy(destA, "salut !!");
	strcpy(destB, "salut !!");
	printf(">%s<\n", destA);
	printf(">%s<\n", destB);
}

void	test_strncpy()
{
	char	destA[11];
	char	destB[11];
	ft_strncpy(destA, "salut !!", 11);
	strncpy(destB, "salut !!", 11);
	printf(">%s<\n", destA);
	printf(">%s<\n", destB);

	char	destC[] = "ooooefg";
	char	destD[] = "ooooefg";
	ft_strncpy(destC, "abcd", 4);
	strncpy(destD, "abcd", 4);
	printf(">%s<\n", destC);
	printf(">%s<\n", destD);
}

void	test_str_is_alpha()
{
	int ret = ft_str_is_alpha("salutcava");
	printf("%d\n", ret);
	ret = ft_str_is_alpha("salUT42Ca va");
	printf("%d\n", ret);
}

void	test_str_is_numeric()
{
	int ret = ft_str_is_numeric("0123456789");
	printf("%d\n", ret);
	ret = ft_str_is_numeric("0123456 789");
	printf("%d\n", ret);
}

void test_str_is_lowercase()
{
	int ret = ft_str_is_lowercase("salut");
	printf("%d\n", ret);
	ret = ft_str_is_lowercase("saLut");
	printf("%d\n", ret);
}

void test_str_is_uppercase()
{
	int ret = ft_str_is_uppercase("SALUT");
	printf("%d\n", ret);
	ret = ft_str_is_uppercase("SAlUT");
	printf("%d\n", ret);
}

void test_str_is_printable()
{
	int ret = ft_str_is_printable("aaa 42 @#$---=]");
	printf("%d\n", ret);
	ret = ft_str_is_printable("->\n");
	printf("%d\n", ret);

}

void	test_strupcase()
{
	char s[] = "aAzZ salut";
	ft_strupcase(s);
	printf("%s\n", s);
}

void	test_strlowercase()
{
	char s[] = "aAzZ salut";
	ft_strlowcase(s);
	printf("%s\n", s);
}

void	test_strcapitalize()
{
	char s[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	ft_strcapitalize(s);
	printf("%s\n", s);
}

void	test_strlcpy()
{
	char	destA[11];
	ft_strlcpy(destA, "salut !!", 11);
	printf(">%s<\n", destA);

}

void	test_putstr_non_printable()
{
	ft_putstr_non_printable("Coucou\ntu vas bien \r?");
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

void	test_print_memory()
{
	char s[] = "Bonjour les aminches...c. est fou.tout.ce qu on peut faire avec...print_memory....lol.lol. .";
	ft_print_memory(s, ft_strlen(s));
}

int		main()
{
	//test_strcpy();
	//test_strncpy();
	//test_str_is_alpha();
	//test_str_is_numeric();
	//test_str_is_lowercase();
	//test_str_is_uppercase();
	//test_str_is_printable();
	//test_strupcase();
	//test_strlowercase();
	//test_strcapitalize();
	//test_strlcpy();
	//test_putstr_non_printable();
	//test_print_memory();
	return (0);
}
