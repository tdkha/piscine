/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:00:07 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/26 19:00:09 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	res;
	int	*arr;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (arr == NULL)
	{
		return (-1);
	}
	res = 0;
	while (res < (max - min))
	{
		arr[res] = min + res;
		res++;
	}
	*range = arr;
	return (res);
}
