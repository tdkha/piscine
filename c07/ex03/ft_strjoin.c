/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:19:15 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/29 12:19:16 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*forming_whole_str(int size, char **strs, char *sep)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = -1;
	while (++i < size)
	{
		len += ft_strlen(strs[i]);
	}
	len += ft_strlen(sep) * (size - 1);
	if (size <= 0)
	{
		len = 1;
	}
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
	{
		return (0);
	}
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		i;
	int		j;
	int		arr_index;

	arr = forming_whole_str(size, strs, sep);
	i = -1;
	arr_index = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			arr[arr_index++] = strs[i][j];
			j++;
		}
		j = 0;
		while (sep[j] && i < (size - 1))
		{
			arr[arr_index++] = sep[j];
			j++;
		}
	}
	arr[arr_index] = '\0';
	return (arr);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char sep[] = " ";
	char *s1[2]= {"Hello", "there"};
	printf("Result: %s\n", ft_strjoin(2, s1, sep));
}
*/