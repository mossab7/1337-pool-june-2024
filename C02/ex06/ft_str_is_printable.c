/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:03:59 by mbouhia           #+#    #+#             */
/*   Updated: 2024/07/02 23:23:15 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_non_printable(char c)
{
	if (c < 32 || c > 126)
		return (1);
	return (0);
}

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_non_printable(str[i]))
			return (0);
		i ++;
	}
	return (1);
}
