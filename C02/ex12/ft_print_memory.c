/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:38:30 by mbouhia           #+#    #+#             */
/*   Updated: 2024/07/09 21:48:28 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char n)
{
	write (1, &"0123456789abcdef"[n / 16], 1);
	write (1, &"0123456789abcdef"[n % 16], 1);
}

void	print_addr(unsigned long addr)
{
	int		i;
	char	*hex;
	char	buffer[16];

	i = 15;
	hex = "0123456789abcdef";
	while (i >= 0)
	{
		buffer[i] = hex[addr % 16];
		addr /= 16;
		i--;
	}
	write (1, buffer, 16);
	write (1, ": ", 2);
}

void	print_ascii(unsigned char *ptr, unsigned int i, unsigned int size)
{
	int	j;

	j = 0;
	while (j < 16)
	{
		if (j + i < size)
			print_hex(ptr[i + j]);
		else
			write (1, "  ", 2);
		if (j % 2)
			write (1, " ", 1);
		j++;
	}
}

void	print_str(unsigned char *ptr, unsigned int i, unsigned int size)
{
	int	j;

	j = 0;
	while (j < 16 && i + j < size)
	{
		if (ptr[i + j] >= 32 && ptr[i + j] <= 126)
			write (1, &ptr[i + j], 1);
		else
			write (1, ".", 1);
		j++;
	}
	write (1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*ptr;
	int				j;

	ptr = (unsigned char *)addr;
	i = 0;
	if (size == 0)
		return (addr);
	while (i < size)
	{
		j = 0;
		print_addr((unsigned long)(ptr + i));
		print_ascii(ptr, i, size);
		print_str(ptr, i, size);
		i += 16;
	}
	return (addr);
}
/*
int main(void)
{
	char str[] = "hello world! n\nigg\tas";
	ft_print_memory(str, sizeof(str) - 1);
}
*/
