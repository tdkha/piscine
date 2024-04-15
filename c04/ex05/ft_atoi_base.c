/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:03:16 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/22 12:03:18 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (!base || base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	char_to_digit(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	i;

	if (!is_valid_base(base))
		return (0);
	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] != '\0' && (str[i] == 45 || str[i] == 43))
	{
		if (str[i] == 45)
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] != '\0' && char_to_digit(str[i], base) != -1)
	{
		result = result * (int)ft_strlen(base) + char_to_digit(str[i], base);
		i++;
	}
	return (result * sign);
}

/*
#include <stdio.h>
int main()
{
	printf("----------------------------\n");
	printf("Testing valid \n");
	printf("----------------------------\n");
	printf("%d\n", ft_atoi_base("1010", "01"));// Should print "10"
	printf("%d\n", ft_atoi_base("    -1111011", "01")); // Should print "-123"
	printf("%d\n", ft_atoi_base("    -+-1111011", "01")); // Should print "123"
	printf("%d\n", ft_atoi_base("FF", "0123456789ABCDEF")); // Should print "255"
	printf("%d\n", ft_atoi_base("-42", "0123456789")); // Should print "-42"

    // Invalid bases:
	printf("----------------------------\n");
	printf("Testing invalid \n");
	printf("----------------------------\n");
	printf("%d\n", ft_atoi_base("42", ""));
	printf("%d\n", ft_atoi_base("42", "0122"));
	printf("%d\n", ft_atoi_base("42", "012 2"));
	printf("%d\n", ft_atoi_base("42", "012345+6789"));         

    return 0;
}
*/
