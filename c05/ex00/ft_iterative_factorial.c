/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:06:46 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/22 12:06:48 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb < 0)
		return (0);
	else if (nb <= 1)
		return (res);
	while (nb > 0)
	{
		res *= nb;
		nb--;
	}
	return (res);
}

/*
#include <stdio.h>
int main(void)
{
	int num = 10;
	int res = ft_iterative_factorial(num);
	printf("Result is : %d", res); // should return 3628800
}
*/