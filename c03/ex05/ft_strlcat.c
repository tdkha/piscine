/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:01:28 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/18 12:01:30 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_dest;
	unsigned int	i;
	unsigned int	size_total;
	unsigned int	size_remain;

	i = 0;
	size_dest = ft_strlen(dest);
	size_total = size_dest + ft_strlen(src);
	if (size <= size_dest || size == 0)
	{
		return (ft_strlen(src) + size);
	}
	else
	{
		size_remain = size - size_dest - 1;
	}
	while (i < size_remain && src[i])
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	dest[size_dest + i] = '\0';
	return (size_total);
}
