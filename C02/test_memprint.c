#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strcpy(char *dest, const char *src);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
void	ft_putstr_non_printable(char *str);
void	*ft_print_memory(void *addr, unsigned int size);

int	main()
{
	/*
	char	lines[] =	"Bonjour les amin"
						"ches\x09\n\x09 c est fo "
						"u.tout.ce qu on "
						"peut faire avec."
						"..print_memory.."
						"lol. ";
	*/
	char	lines[] =
		"\x42\x6f\x6e\x6a\x6f\x75\x72\x20\x6c\x65\x73\x20\x61\x6d\x69\x6e"
		"\x63\x68\x65\x73\x09\x0a\x09\x63\x20\x20\x65\x73\x74\x20\x66\x6f"
		"\x75\x09\x74\x6f\x75\x74\x09\x63\x65\x20\x71\x75\x20\x6f\x6e\x20"
		"\x70\x65\x75\x74\x20\x66\x61\x69\x72\x65\x20\x61\x76\x65\x63\x09"
		"\x0a\x09\x70\x72\x69\x6e\x74\x5f\x6d\x65\x6d\x6f\x72\x79\x0a\x0a"
		"\x0a\x09\x6c\x6f\x6c\x2e\x6c\x6f\x6c\x0a\x20\x00";
	char	*ptr;
	char	*result;

	ptr = lines;



	printf("\n\n\nTEST 1");
	result = ft_print_memory(ptr, (long int)strlen(ptr));
	printf("address ofptr = %p\n", result);
	printf("size of address of ptr = %lu\n", sizeof(result));

	return (0);
}

