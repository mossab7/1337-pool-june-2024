/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:47:36 by mbouhia           #+#    #+#             */
/*   Updated: 2024/07/03 20:45:40 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

int	get_base_index(char digit, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (digit == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	valid_base(char *base)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(base);
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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	sign;
	int	len;
	int	base_value;

	i = 0;
	result = 0;
	sign = 1;
	len = ft_strlen(base);
	if (!(valid_base(base)))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i])
	{
		base_value = get_base_index(str[i++], base);
		if (base_value == -1)
			return (result * sign);
		result = (result * len) + base_value;
	}
	return (result * sign);
}
