/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:18:24 by ktieu             #+#    #+#             */
/*   Updated: 2024/01/30 12:18:25 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

int	ft_abs(int number)
{
	if (number < 0)
	{
		return (-number);
	}
	else
	{
		return (number);
	}
}
# define ABS ft_abs

#endif