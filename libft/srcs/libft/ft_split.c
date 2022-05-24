/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:01:20 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/13 11:00:27 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	nb_word;
	int	i;

	nb_word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			nb_word++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nb_word);
}

static int	word_len(char const *s, char c)
{
	int	length;

	length = 0;
	while (s[length] && s[length] != c)
		length++;
	return (length);
}

static char	*insert_word(int word_len, char const *s, char c)
{
	int		i;
	char	*split;

	i = 0;
	split = __ft_calloc(sizeof(char) * (word_len + 1));
	if (!split)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		split[i] = s[i];
		i++;
	}
	split[i] = '\0';
	return (split);
}

char	**free_split(char **split, int k)
{
	while (--k)
		free(split[k]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	char	**split;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	split = __ft_calloc(sizeof(char *) * (count_word(s, c) + 1));
	if (split == NULL)
		return (NULL);
	while (s[i] && k < count_word(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		split[k] = insert_word(word_len(&s[i], c), &s[i], c);
		if (split[k] == NULL)
			return (free_split(split, k));
		while (s[i] && s[i] != c)
			i++;
		k++;
	}
	split[k] = NULL;
	return (split);
}
