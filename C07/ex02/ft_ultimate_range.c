#include <stdio.h>
#include <stdlib.h>

int 	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	size;
	unsigned int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range  = (int *)malloc(sizeof(int) * (size));
	if (!*range)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (i);
}
