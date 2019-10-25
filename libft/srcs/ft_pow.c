/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 03:15:53 by pthan             #+#    #+#             */
/*   Updated: 2019/10/25 03:16:05 by pthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double nb, int pow)
{
	double	tmp;

	if (pow == 0)
		return (1);
	tmp = ft_pow(nb, pow / 2);
	if ((pow % 2) == 0)
		return (tmp * tmp);
	else
	{
		if (pow > 0)
			return (nb * tmp * tmp);
		else
			return ((tmp * tmp) / nb);
	}
}
