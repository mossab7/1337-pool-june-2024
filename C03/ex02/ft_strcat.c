/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:10:36 by mbouhia           #+#    #+#             */
/*   Updated: 2024/07/02 11:10:27 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	lenght(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int		destlen;
	char	*original;

	original = dest;
	destlen = lenght(dest);
	while (*src)
	{
		*(dest + destlen) = *src;
		destlen ++;
		src ++;
	}
	*(dest + destlen) = '\0';
	return (original);
}
