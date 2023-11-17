/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:29:10 by rgiraud           #+#    #+#             */
/*   Updated: 2023/11/17 17:02:03 by rgiraud          ###   ########.fr       */
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
	int		pad_count;
	bool	pad_zero;
	bool	pad_left;
	bool	pad_right;
	bool	precision;
	bool	hashtag;
	bool	space;
	bool	plus;
}			t_format;
#endif