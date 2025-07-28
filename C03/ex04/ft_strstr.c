/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:34:11 by mbouhia           #+#    #+#             */
/*   Updated: 2024/07/02 17:49:11 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len ++;
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	j;
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(to_find);
	if (len == 0)
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (!to_find[j + 1])
				return (str + i);
			else
				j ++;
		}
		i ++;
	}
	return (0);
}
