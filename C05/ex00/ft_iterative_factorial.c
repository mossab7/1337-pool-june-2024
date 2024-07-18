/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:19:53 by mbouhia           #+#    #+#             */
/*   Updated: 2024/07/10 14:19:58 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	start;

	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	i = 1;
	start = nb;
	while (i < start)
	{
		nb *= i;
		i++;
	}
	return (nb);
}
