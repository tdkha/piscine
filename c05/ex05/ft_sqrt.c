/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:28:35 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/22 17:28:36 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	res;

	res = 1;
	if (nb > 0)
	{
		while (res * res <= nb)
		{
			if (res * res == nb)
			{
				return (res);
			}
			if (res > 46340)
			{
				return (0);
			}
			res++;
		}
	}
	return (0);
}

/*
#include <stdio.h>
int main(void){
	int test1 = 9;
	int test2 = 0;
	int test3 = -12;
	int test4 = 21613201;
	int test5 = 821280964;

	printf("Test 1: %d\n", ft_sqrt(test1));
	printf("Test 2: %d\n", ft_sqrt(test2));
	printf("Test 3: %d\n", ft_sqrt(test3));
	printf("Test 4: %d\n", ft_sqrt(test4)); // shoud return 4649
	printf("Test 5: %d\n", ft_sqrt(test5)); // shoud return 28658
}
*/