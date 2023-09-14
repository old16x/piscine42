/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:13:40 by aradix            #+#    #+#             */
/*   Updated: 2023/09/13 20:23:49 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	if (ft_strlen(to_find) == 0)
		return ((char*)str);
	while (str[i])
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
				return ((char*)str + i);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	tmp;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = -1;
			tmp = 0;
			while (to_find[++i] != '\0')
				if (str[i] != to_find[i])
					tmp = 1;
			if (tmp == 0)
				return (str);
		}
		str++;
	}
	return (0);
}

char *ft_strstr(char *str, char *to_find)
{
    unsigned int i;
    unsigned int j;

    i = 0;
    if (to_find[0] == '\0')
        return (str);
    while (str[i])
    {
        j = 0;
        while (to_find[j] == str[i + j])
        {
            if (to_find[j + 1] == '\0')
                return (str + i);
            j++;
        }
        i++;
    }
    return (0);
}


int main() {
    char str[] = "Hello, World!";
    char to_find[] = "";

    char *result1 = ft_strstr1(str, to_find);
    char *result2 = ft_strstr2(str, to_find);

    printf("Result from ft_strstr1: %s\n", result1);
    printf("Result from ft_strstr2: %s\n", result2);

    return 0;
}
