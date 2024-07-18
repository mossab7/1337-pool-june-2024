/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:29:04 by mbouhia           #+#    #+#             */
/*   Updated: 2024/07/10 01:22:16 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c
			&& c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int		in_word;
	char	*start;
	int		diff;

	in_word = 0;
	start = str;
	diff = 'a' - 'A';
	while (*str)
	{
		if (ft_str_is_alpha(*str))
		{
			if (!in_word && ('a' <= *str && *str <= 'z'))
				*str -= diff;
			else if (in_word && ('A' <= *str && *str <= 'Z'))
				*str += diff;
			in_word = 1;
		}
		else
		{
			in_word = 0;
		}
		str++;
	}
	return (start);
}
