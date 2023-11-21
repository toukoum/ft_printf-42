/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:46:16 by rgiraud           #+#    #+#             */
/*   Updated: 2023/11/21 11:20:11 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	convert_s(t_format *flags, int *count)
{
	char	*result;
	int		len_result;

	result = va_arg(flags->args, char *);
	if (!result)
		return (ft_print_null(count, flags));
	if (flags->point && flags->precision < (int)ft_strlen(result))
		len_result = flags->precision;
	else
		len_result = (int)ft_strlen(result);
	while (flags->width && flags->width > len_result && !flags->minus)
		ft_print_space(count, flags);
	(*count) += write(1, result, len_result);
	while (flags->width && flags->width > len_result && flags->minus)
		ft_print_space(count, flags);
}
