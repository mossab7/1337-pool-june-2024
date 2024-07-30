/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:39:37 by mbouhia           #+#    #+#             */
/*   Updated: 2024/07/10 20:16:22 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_len(int *i, char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[*i] && is_sep(str[*i], charset))
		(*i)++;
	while (str[*i] && !is_sep(str[*i], charset))
	{
		len++;
		(*i)++;
	}
	return (len);
}

void	cpy(char *src, char *dest, int size)
{
	int	i;

	i = 0;
	while (src[i] && size)
	{
		dest[i] = src[i];
		i++;
		size--;
	}
	dest[i] = '\0';
}

int	words_count(char *str, char *charset)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (str[i] && !(is_sep(str[i], charset)))
			len++;
		while (str[i] && !(is_sep(str[i], charset)))
			i++;
	}
	return (len);
}

char	**ft_split(char *str, char *charset)
{
	int		j;
	int		i;
	int		strlen;
	char	**strptr;

	j = words_count(str, charset);
	strptr = (char **)malloc((j + 1) * sizeof(char *));
	if (strptr == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (!str[i])
			break ;
		strlen = word_len(&i, str, charset);
		strptr[j] = (char *)malloc((strlen + 1) * sizeof(char));
		if (strptr[j] == NULL)
			return (NULL);
		cpy(&str[i - strlen], strptr[j++], strlen);
	}
	strptr[j] = NULL;
	return (strptr);
}
