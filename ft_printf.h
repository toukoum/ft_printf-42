/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:29:10 by rgiraud           #+#    #+#             */
/*   Updated: 2023/11/20 18:28:51 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define t_bool int
# define false 0
# define true 1

int					ft_printf(const char *format, ...);
char				*ft_itoa_boost(unsigned long long n);
unsigned long long	ft_atoi_base(char *str, char *base);

char				*ft_convert_base(char *nbr, char *base_from, char *base_to);

typedef struct s_format
{
	int				width;
	int				precision;
	int				point;
	t_bool			zero;
	t_bool			hashtag;
	t_bool			space;
	t_bool			plus;
	t_bool			minus;
	va_list			args;
}					t_format;
#endif