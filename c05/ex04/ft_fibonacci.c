/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:53:58 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/22 16:54:00 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
	{
		return (-1);
	}
	if (index <= 1)
	{
		return (index);
	}
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/*
#include <stdio.h>
int main(void)
{
	printf("-------------------------------\n");
	printf("Testing\n");
	printf("-------------------------------\n");
	int num1 = 4;
	int res1 = ft_fibonacci(num1);
	printf("Result 1 is : %d\n", res1); // should return 3
	int num2 = -5;
	int res2 = ft_fibonacci(num2);
	printf("Result 2 is : %d\n", res2); // should return -1
	int num3 = 6;
	int res3 = ft_fibonacci(num3);
	printf("Result 3 is : %d\n", res3); // should return 8
}
*/