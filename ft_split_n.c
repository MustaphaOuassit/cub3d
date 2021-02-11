/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouassit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:19:50 by mouassit          #+#    #+#             */
/*   Updated: 2021/02/11 19:23:22 by mouassit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_separator_n(char str, char c)
{
	return (str != c && str != '\n');
}

int		ft_count_words_n(char *str, char c)
{
	int		i;
	int		in_word;
	int		count;

	i = 0;
	in_word = 0;
	count = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == c || *str == '\n')
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

int		ft_word_length_n(char *str, int i, char c)
{
	int		length;

	length = 0;
	while (ft_separator_n(str[i], c) && str[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

void	*fr_ee_n(char **words, int j)
{
	while (j)
		free(words[j--]);
	free(words);
	return (NULL);
}

char	**ft_split_n(char const *s, char c)
{
	char	**words;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!(words = (char**)malloc(sizeof(char*) *
					(ft_count_words_n((char*)s, c) + 1))) || !s)
		return (0);
	while (s[i] != '\0' && j < ft_count_words_n((char*)s, c))
	{
		k = 0;
		while (s[i] == c || s[i] == '\n')
			i++;
		if (!(words[j] = (char*)malloc(sizeof(char) *
						ft_word_length_n((char*)s, i, c) + 1)))
			return (fr_ee_n(words, j));
		while (ft_separator_n(s[i], c) && s[i] != '\0')
			words[j][k++] = s[i++];
		words[j++][k] = '\0';
	}
	words[j] = 0;
	return (words);
}
