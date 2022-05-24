/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:11:34 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/11 15:34:42 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_number(long int n)
{
	int	len;

	len = 0;
	if (n >= 0 && n < 10)
		return (1);
	if (n < 0 && n > -10)
		return (2);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

static char	*ft_itoa_zero(char *nb)
{
	nb [0] = '0';
	nb [1] = '\0';
	return (nb);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nb;

	nb = (long int)n;
	i = len_number(nb) - 1;
	str = __ft_calloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	if (n == 0)
		return (ft_itoa_zero(str));
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	str[i + 1] = '\0';
	while (nb > 0)
	{
		str[i] = '0' + (nb % 10);
		nb = nb / 10;
		i--;
	}
	return (str);
}
