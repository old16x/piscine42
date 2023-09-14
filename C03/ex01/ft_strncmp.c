/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:11:32 by aradix            #+#    #+#             */
/*   Updated: 2023/09/13 16:32:00 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

int ft_strncmp1(char *s1, char *s2, unsigned int n)
{
    unsigned int i;

    i = 0;
    while (i < n && (*s1 || *s2))
    {
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - ((unsigned char)s2[i]));
        i++;
    }
    return (0);
}

int ft_strncmp2(char *s1, char *s2, unsigned int n)
{
    unsigned int i;

    i = -1;
    while (++i < n && (*s1 || *s2))
        if (s1[i] != s2[i])
            return (((char *)s1)[i] - ((char *)s2)[i]);
    return (0);
}

int main() {
    char s1[] = {128, '\0'}; // 0x80
    char s2[] = {0, '\0'};   // 0x00

    int result1 = ft_strncmp1(s1, s2, 1);
    int result2 = ft_strncmp2(s1, s2, 1);

    printf("Result from ft_strncmp1: %d\n", result1);
    printf("Result from ft_strncmp2: %d\n", result2);

    return 0;
}

