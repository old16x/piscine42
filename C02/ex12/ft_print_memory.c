/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:51:04 by aradix            #+#    #+#             */
/*   Updated: 2023/09/10 22:43:54 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> // a delete

void write_pointer(void* ptr) {
    char buffer[20];
    char hexChars[] = "0123456789abcdef";

    int ptr_size = sizeof(void*);
    

    int	i = ptr_size -1;
    while (i >= 0)
    {
        unsigned char byte = ((unsigned char*)&ptr)[i];
        buffer[(ptr_size - 1 - i) * 2] = hexChars[byte >> 4];
        buffer[(ptr_size - 1 - i) * 2 + 1] = hexChars[byte & 0xf];
    	i--;
	}
    buffer[ptr_size * 2] = '\0';
    write(1, buffer, ptr_size * 2);
}


void *ft_print_memory(void *addr, unsigned int size) {
    write_pointer(addr);
    return addr;
}
