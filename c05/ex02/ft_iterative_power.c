/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:55:13 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/22 12:55:13 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		res *= nb;
		power--;
	}
	return (res);
}

/*
#include <stdio.h>
int main(void)
{
	printf("-------------------------------\n");
	printf("Testing\n");
	printf("-------------------------------\n");
	int num1 = 5;
	int power1 = 2;
	int res1 = ft_iterative_power(num1,power1);
	printf("Result 1 is : %d\n", res1); // should return 25
	int num2 = 5;
	int power2 = 0;
	int res2 = ft_iterative_power(num2,power2);
	printf("Result 2 is : %d\n", res2); // should return 1
	int num3 = 0;
	int power3 = 0;
	int res3 = ft_iterative_power(num3,power3);
	printf("Result 3 is : %d\n", res3); // should return 1
	int num4 = 0;
	int power4 = -42;
	int res4 = ft_iterative_power(num4,power4);
	printf("Result 4 is : %d\n", res4); // should return 0
}
*/