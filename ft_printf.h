/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:29:10 by rgiraud           #+#    #+#             */
/*   Updated: 2023/11/18 10:40:22 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

# define bool int
# define false 0
# define true 1

typedef struct s_format
{
	int		width;
	int		precision;
	bool	zero;
	bool	hashtag;
	bool	space;
	bool	plus;
	bool	minus;
	va_list	args;
}			t_format;
#endif