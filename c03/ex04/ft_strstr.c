/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:10:48 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/17 16:10:51 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_helper(char *str, char *to_find)
{
	while (*str && *to_find && *str == *to_find)
	{
		str++;
		to_find++;
	}
	if (!*to_find)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	validate;

	if (*to_find == '\0')
	{
		return (str);
	}
	validate = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == *to_find)
		{
			if (ft_helper(&str[i], to_find))
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
