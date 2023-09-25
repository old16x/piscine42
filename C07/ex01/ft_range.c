#include <stdlib.h>

int *ft_range(int min, int max)
{
	int 					*tab;
	unsigned int	size;
	unsigned int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	tab  = (int *)malloc(sizeof(int) * (size));
	if (!tab)
		return (NULL);
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}
