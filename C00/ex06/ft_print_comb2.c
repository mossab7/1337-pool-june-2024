/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:44:25 by mbouhia           #+#    #+#             */
/*   Updated: 2024/06/27 09:32:21 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_digit(int n)
{
	char	temp;

	temp = n + '0';
	write(1, "0", 1);
	write(1, &temp, 1);
}

void	put_number(int n)
{
	char	temp;

	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n / 10 != 0)
	{
		put_number(n / 10);
	}
	temp = (n % 10) + '0';
	write(1, &temp, 1);
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 0;
	while (x <= 98)
	{
		y = x + 1;
		while (y <= 99)
		{
			if (x < 10)
				put_digit(x);
			else if (x >= 10)
				put_number(x);
			write(1, " ", 1);
			if (y < 10)
				put_digit(y);
			else if (y >= 10)
				put_number(y);
			if (x != 98 || y != 99)
				write(1, ", ", 2);
			y ++;
		}
		x ++;
	}
}
