/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:35:10 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/18 15:35:11 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
	}
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res * sign);
}

/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char str[] = "-2147483648";
	printf("my %d\n", ft_atoi(str));
	printf("og %d\n", atoi(str));
	return 0;
}
*/