/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:00:58 by mbouhia           #+#    #+#             */
/*   Updated: 2024/07/13 14:42:53 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ultimate_strlen(char **str, int size)
{
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (j < size)
	{
		len += ft_strlen(str[j]);
		j++;
	}
	return (len);
}

void	fill_out(char *str, char **strs, char *sep, int size)
{
	int	j;
	int	i;
	int	k;

	j = 0;
	k = 0;
	while (j < size)
	{
		i = 0;
		while (strs[j][i])
		{
			str[k++] = strs[j][i++];
		}
		i = 0;
		while (sep[i] && j < size - 1)
			str[k++] = sep[i++];
		j++;
	}
	str[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*str;

	if (size == 0)
	{
		str = (char *)malloc(sizeof(char));
		*str = '\0';
		return (str);
	}
	len = ultimate_strlen(strs, size) + (ft_strlen(sep) * (size - 1));
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!(str))
		return (0);
	fill_out(str, strs, sep, size);
	return (str);
}
