/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:41:14 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/23 18:23:08 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || !base[0] || !base[1])
	{
		return (0);
	}
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	recursive(int nbr, char *base, int base_size)
{
	char			c;
	unsigned int	n;

	if (nbr < 0)
	{
		write(1, "-", 1);
		n = -nbr;
	}
	else
		n = nbr;
	if (n >= (unsigned int)base_size)
	{
		recursive(n / base_size, base, base_size);
	}
	c = base[n % base_size];
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	base_size;

	i = 0;
	if (check_base_valid(base))
	{
		base_size = ft_strlen(base);
		recursive(nbr, base, base_size);
	}
}

/*
#include <stdio.h>
#include <string.h>
int main() {
    // Example usage:
	printf("----------------------------\n");
	printf("Testing valid \n");
	printf("----------------------------\n");
    ft_putnbr_base(255, "0123456789");  // Should print "255"
	printf("\n");
	ft_putnbr_base(-2147483648, "0123456789");  // Should print "-2147483648"
	printf("\n");
	ft_putnbr_base(2147483647, "0123456789");  // Should print "2147483647"
	printf("\n");
    ft_putnbr_base(-123, "01");         // Should print "-1111011"
	printf("\n");
    ft_putnbr_base(42, "poneyvif");     // Should print "vn"
	printf("\n");
	ft_putnbr_base(42, "01234567");     // Should print "52"
	printf("\n");
    ft_putnbr_base(255, "0123456789ABCDEF");  // Should print "FF"
	printf("\n");

    // Invalid bases:
	printf("----------------------------\n");
	printf("Testing invalid \n");
	printf("----------------------------\n");
    ft_putnbr_base(123, "");       
    ft_putnbr_base(123, "01231");   
    ft_putnbr_base(123, "12+34");

    return 0;
}
*/