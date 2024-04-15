/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:58:54 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/26 12:58:55 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*arr;
	unsigned int	i;

	i = 0;
	if (min >= max)
	{
		return (NULL);
	}
	arr = (int *)malloc((max - min) * sizeof(int));
	while (min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}
