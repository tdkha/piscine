/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:04:38 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/16 15:57:52 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(char str)
{
	write(1, &str, 1);
}

void	convert_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c / 16 > 0)
	{
		print_char(hex[c / 16]);
		print_char(hex[c % 16]);
	}
	else
	{
		print_char(hex[0]);
		print_char(hex[c]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < ' ' || str[i] > '~')
		{
			print_char('\\');
			convert_hex(str[i]);
		}
		else
		{
			print_char(str[i]);
		}
		i++;
	}
}
