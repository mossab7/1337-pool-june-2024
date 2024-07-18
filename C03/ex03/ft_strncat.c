/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:39:38 by mbouhia           #+#    #+#             */
/*   Updated: 2024/07/02 17:44:20 by mbouhia          ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int		destlen;
	unsigned int		i;
	char				*original;

	if (!src || !dest)
		return (dest);
	original = dest;
	destlen = lenght(dest);
	i = 0;
	while (*src && i < nb)
	{
		*(dest + destlen) = *src;
		destlen ++;
		src ++;
		i ++;
	}
	*(dest + destlen) = '\0';
	return (original);
}
