/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:50:06 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/18 14:50:08 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_count(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		return (1);
	}
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	ft_pow(int count)
{
	int	result;

	result = 1;
	if (count == 1)
	{
		return (result);
	}
	while (count > 1)
	{
		result *= 10;
		count--;
	}
	return (result);
}

void	ft_putnbr(int nb)
{
	int		power;
	int		count;
	int		temp;

	if (nb == (-2147483647 - 1))
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < (-2147483647 - 1) || nb > 2147483647)
		return ;
	count = ft_count(nb);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	while (count > 0)
	{
		power = ft_pow(count);
		temp = (nb / power) % 10 + '0';
		write(1, &temp, 1);
		count--;
	}
}
