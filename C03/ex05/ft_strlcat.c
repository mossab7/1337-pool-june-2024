/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:20:26 by mbouhia           #+#    #+#             */
/*   Updated: 2024/07/02 23:05:25 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len ++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	lensrc;
	unsigned int	lendest;
	unsigned int	nlen;
	unsigned int	i;

	i = 0;
	lensrc = str_len(src);
	lendest = str_len(dest);
	if (!dest || !src)
		return (0);
	if (size <= lendest)
		return (lensrc + size);
	while (src[i] && lendest + i < size - 1)
	{
		dest[(lendest + i)] = src[i];
		i ++;
	}
	dest[(lendest + i)] = '\0';
	nlen = lensrc + lendest;
	return (nlen);
}
