/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:24:41 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/22 14:24:42 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_power(nb, power - 1));
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
	int res1 = ft_recursive_power(num1,power1);
	printf("Result 1 is : %d\n", res1); // should return 25
	int num2 = 5;
	int power2 = 0;
	int res2 = ft_recursive_power(num2,power2);
	printf("Result 2 is : %d\n", res2); // should return 1
	int num3 = 0;
	int power3 = 0;
	int res3 = ft_recursive_power(num3,power3);
	printf("Result 3 is : %d\n", res3); // should return 1
	int num4 = 0;
	int power4 = -42;
	int res4 = ft_recursive_power(num4,power4);
	printf("Result 4 is : %d\n", res4); // should return 0
}
*/