/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:30:38 by rgiraud           #+#    #+#             */
/*   Updated: 2023/11/20 18:24:20 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reverse_str(char *result)
{
	int		len_result;
	int		i;
	int		j;
	char	temp;

	len_result = 0;
	i = 0;
	if (result[0] == '-')
		i++;
	while (result[len_result])
		len_result++;
	j = len_result - 1;
	while (i < j)
	{
		temp = result[i];
		result[i] = result[j];
		result[j] = temp;
		i++;
		j--;
	}
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
				|| base[j] == '+' || base[j] == '-' || base[i] <= ' '
				|| base[i] > 126 || base[j] <= ' ' || base[j] > 126)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_len_result(int nbr, char *base)
{
	int	len_result;
	int	len_base;

	len_base = 0;
	while (base[len_base])
		len_base++;
	len_result = 0;
	while (nbr)
	{
		nbr = nbr / len_base;
		len_result++;
	}
	return (len_result);
}

char	*ft_putnbr_base(unsigned long long nbr, char *base)
{
	char				*result;
	int					i;
	unsigned long long	n;

	n = nbr;
	i = 0;
	result = malloc(ft_len_result(nbr, base) * sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		i++;
		n *= -1;
	}
	if (n == 0)
		result[i++] = base[0];
	while (n)
	{
		result[i++] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	i -= 1;
	ft_reverse_str(result);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned long long number;
	char *result;

	if ((!ft_check_base(base_from) || !ft_check_base(base_to)))
		return (NULL);
    printf("\n\nnumber AVANT atoi base: %s\n", nbr);

	number = ft_atoi_base(nbr, base_from);
    printf("\n\nnumber apres atoi base: %llu\n", number);
	result = ft_putnbr_base(number, base_to);
	return (result);
}