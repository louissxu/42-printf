/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <lxu@student.42adel.org.au>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:54:35 by lxu               #+#    #+#             */
/*   Updated: 2022/01/11 03:48:20 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*priv_strdup_partial(char const *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	word = malloc(sizeof (*word) * (end - start + 1));
	if (!word)
	{
		return (word);
	}
	i = 0;
	while (s[start + i] && start + i < end)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	priv_destroy(char **words, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static size_t	priv_num_of_words(char const *s, char c)
{
	size_t	i;
	size_t	number_of_words;

	number_of_words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				number_of_words++;
			}
		}
		i++;
	}
	return (number_of_words);
}

static void	priv_find_word(char const *s, size_t *i, size_t *j, char c)
{
	while (s[*i] == c)
	{
		(*i)++;
	}
	*j = *i;
	while (s[*j] && s[*j] != c)
	{
		(*j)++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	num_of_words;
	size_t	word_i;
	size_t	i;
	size_t	j;
	char	**words;

	num_of_words = priv_num_of_words(s, c);
	words = malloc(sizeof (*words) * (num_of_words + 1));
	if (!words)
		return (NULL);
	word_i = 0 - 1;
	i = 0;
	while (++word_i < num_of_words)
	{
		priv_find_word(s, &i, &j, c);
		words[word_i] = priv_strdup_partial(s, i, j);
		if (!words[word_i])
		{
			priv_destroy(words, word_i);
			return (NULL);
		}
		i = j;
	}
	words[word_i] = NULL;
	return (words);
}
