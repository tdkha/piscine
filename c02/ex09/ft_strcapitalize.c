/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:49:48 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/16 18:36:09 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strlowcase(char *str)
{
	if (*str >= 'A' && *str <= 'Z')
	{
		*str += 32;
	}
}

void	ft_strupcase(char *str)
{
	if (*str >= 'a' && *str <= 'z')
	{
		*str -= 32;
	}
}

int	is_alpha_numeric(char *str)
{
	int	res;

	res = 0;
	if (*str >= 'A' && *str <= 'Z')
	{
		res = 1;
	}
	if (*str >= 'a' && *str <= 'z')
	{
		res = 1;
	}
	if (*str >= '0' && *str <= '9')
	{
		res = 1;
	}
	return (res);
}

char	*ft_strcapitalize(char *str)
{
	int	capitalized_next;
	int	i;

	i = 0;
	capitalized_next = 1;
	while (str[i] != '\0')
	{
		if (is_alpha_numeric(&str[i]))
		{
			if (capitalized_next)
			{
				ft_strupcase(&str[i]);
				capitalized_next = 0;
			}
			else
				ft_strlowcase(&str[i]);
			if (!is_alpha_numeric(&str[i + 1]))
				capitalized_next = 1;
		}
		else
			capitalized_next = 1;
		i++;
	}
	return (str);
}
