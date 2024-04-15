/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:37:46 by ktieu             #+#    #+#             */
/*   Updated: 2024/02/01 13:37:47 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
		{
			return (1);
		}
		charset++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	count;
	int	is_in_a_word;

	count = 0;
	is_in_a_word = 0;
	while (*str)
	{
		if (!ft_is_charset(*str, charset))
		{
			if (!is_in_a_word)
			{
				count++;
				is_in_a_word = 1;
			}
		}
		else
		{
			is_in_a_word = 0;
		}
		str++;
	}
	return (count);
}

char	*ft_worddup(char *start, char *end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (word == NULL)
	{
		return (NULL);
	}
	while (start < end)
	{
		word[i++] = *start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_helper(char **compress, char **res, int *arr, char *start)
{
	while (*compress[0])
	{
		if (!ft_is_charset(*compress[0], compress[1]) && (!arr[1]))
		{
			start = compress[0];
			arr[1] = 1;
		}
		else if (ft_is_charset(*compress[0], compress[1]) && arr[1])
		{
			res[arr[0]++] = ft_worddup(start, compress[0]);
			if (!res[arr[0] - 1])
				return (NULL);
			arr[1] = 0;
		}
		compress[0]++;
	}
	if (arr[1])
	{
		res[arr[0]++] = ft_worddup(start, compress[0]);
		if (!res[arr[0] - 1])
			return (NULL);
	}
	res[arr[0]] = NULL;
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	int		words_count;
	int		arr[2];
	char	**res;
	char	**compressed;
	char	*word_start;

	arr[0] = 0;
	arr[1] = 0;
	compressed = (char **)malloc(2 * sizeof(char *));
	if (compressed == NULL)
		return (NULL);
	compressed[0] = str;
	compressed[1] = charset;
	word_start = NULL;
	words_count = ft_count_words(str, charset);
	res = (char **)malloc((words_count + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	return (ft_split_helper(compressed, res, arr, word_start));
}
