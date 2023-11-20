/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:31:10 by rgiraud           #+#    #+#             */
/*   Updated: 2023/11/20 18:28:41 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_strlen2(char *str)
{
	unsigned long long	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned long long	ft_sign(char *str, int *i)
{
	unsigned long long	sign;

	sign = 1;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
		{
			sign *= -1;
		}
		(*i) += 1;
	}
	return (sign);
}

unsigned long long	convert_string_to_int(char *str, char *base, int len, int i)
{
	unsigned long long	nbr;
	unsigned long long	j;
	unsigned long long	value;

	nbr = 0;
	while (str[i])
	{
		value = -1;
		j = 0;
		while (j < len && base[j] != str[i])
		{
			j++;
		}
		if (j < len)
		{
			value = j;
		}
		if (value == -1)
			break ;
		nbr = nbr * len + value;
		i++;
	}
	return (nbr);
}

unsigned long long	ft_atoi_base(char *str, char *base)
{
	unsigned long long nbr;
	unsigned long long len;
	unsigned long long sign;
	unsigned long long i;

	i = 0;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	len = ft_strlen2(base);
	sign = ft_sign(str, &i);
	nbr = convert_string_to_int(str, base, len, i);
	return (nbr * sign);
}