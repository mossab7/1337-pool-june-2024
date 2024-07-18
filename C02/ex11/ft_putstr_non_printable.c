/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:07:01 by mbouhia           #+#    #+#             */
/*   Updated: 2024/07/02 20:30:33 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_unprintbale(unsigned char n)
{
	write (1, &"0123456789abcdef"[n / 16], 1);
	write (1, &"0123456789abcdef"[n % 16], 1);
}

int	unprintbale(char c)
{
	if (c <= 31 || c >= 127)
		return (1);
	return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (unprintbale(str[i]))
		{
			write(1, "\\", 1);
			print_unprintbale((unsigned char)str[i]);
		}
		else
			write(1, &str[i], 1);
		i ++;
	}
}
