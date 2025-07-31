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

int	is_sep(char c, const char *charset)
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

int	word_len(const char *str, const char *charset, int *i)
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

void	ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	words_count(const char *str, const char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (str[i] && !is_sep(str[i], charset))
			count++;
		while (str[i] && !is_sep(str[i], charset))
			i++;
	}
	return (count);
}

void	free_all(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;
	int		len;
	int		word_start;

	res = malloc((words_count(str, charset) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		len = word_len(str, charset, &i);
		if (len > 0)
		{
			word_start = i - len;
			res[j] = malloc((len + 1) * sizeof(char));
			if (!res[j])
				return (free_all(res, j), NULL);
			ft_strncpy(res[j++], &str[word_start], len);
		}
	}
	res[j] = NULL;
	return (res);
}
