/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:45:34 by mbouhia           #+#    #+#             */
/*   Updated: 2024/07/09 15:53:01 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	if (min >= max || (min == 0 && max == 0))
	{
		*range = NULL;
		return (0);
	}
	size = ft_abs(max - min);
	*range = (int *)malloc((sizeof(int) * (size)));
	i = 0;
	if ((*range) == NULL)
		return (0);
	while (max > min + i)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}
