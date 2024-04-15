/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:34:23 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/29 13:34:24 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str);

unsigned int	ft_strlen_base(int nbr, char *base);

int				is_valid_base(char *base);

int				char_to_digit(char c, char *base);

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

void	ft_putnbr_base(int nb, char *base_to, char *res, int *index)
{
	int		base_to_len;
	char	c;

	base_to_len = ft_strlen(base_to);
	if (nb < 0)
	{
		res[(*index)++] = '-';
		nb *= -1;
	}
	if (nb >= base_to_len)
	{
		ft_putnbr_base(nb / base_to_len, base_to, res, index);
		ft_putnbr_base(nb % base_to_len, base_to, res, index);
	}
	else
	{
		c = base_to[nb];
		res[(*index)++] = c;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	int		num;
	int		index;

	index = 0;
	if (!nbr || !base_from || !base_to)
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	res = (char *)malloc(sizeof(char) * (ft_strlen_base(num, base_to) + 1));
	if (res == NULL)
		return (NULL);
	ft_putnbr_base(num, base_to, res, &index);
	res[index] = '\0';
	return (res);
}

/*
#include <stdio.h>
int main(void)
{
	char nbr[] = "42";
	char base_from[] = "0123456789";
	char base_to[] = "01234567";
	char *res; 
	res = ft_convert_base(nbr, base_from, base_to);
	
	printf("%s\n", res);
 	
	free(res);
	return 0;
}
*/