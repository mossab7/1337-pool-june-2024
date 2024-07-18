/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:56:21 by mbouhia           #+#    #+#             */
/*   Updated: 2024/07/03 17:03:11 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	blen(char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

int	valid_base(char *base)
{
	int	len;
	int	i;
	int	j;

	len = blen(base);
	i = 0;
	j = 0;
	if (len < 2)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' )
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char*base)
{
	int	base_len;

	base_len = blen(base);
	if (!(valid_base(base)))
		return ;
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr_base(2147483648 / base_len, base);
		ft_putnbr_base(2147483648 % base_len, base);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nbr / base_len != 0)
		ft_putnbr_base(nbr / base_len, base);
	write(1, &base[nbr % base_len], 1);
}
