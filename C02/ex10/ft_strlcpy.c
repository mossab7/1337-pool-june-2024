/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:22:29 by mbouhia           #+#    #+#             */
/*   Updated: 2024/07/02 23:38:52 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	lenght(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len ++;
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	srclen;
	unsigned int	destlen;

	i = 0;
	srclen = lenght(src);
	if (size == 0)
		return (srclen);
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	destlen = lenght(dest);
	return (srclen);
}
