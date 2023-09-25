#include <stdlib.h>

char *ft_strdup(char *src)
{
	char					*dest;
	unsigned int	i;

	i = 0;
	while(src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	dest[i] = '\0';
	while (i-- > 0)
		dest[i] = src[i];
	return (dest);
}
