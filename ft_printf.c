/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:56:45 by rgiraud           #+#    #+#             */
/*   Updated: 2023/11/18 16:08:25 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

// initialise tt les flags a 0
t_format	init_flags(va_list *args)
{
	t_format	flags;

	ft_bzero(&flags, sizeof(t_format));
	va_copy(flags.args, *args);
	return (flags);
}

void	ft_print_space(int *count, t_format *flags)
{
	write(1, " ", 1);
	(*count)++;
	flags->width--;
}

void	ft_print_zero(int *count, t_format *flags)
{
	write(1, "0", 1);
	(*count)++;
	flags->width--;
}

void	ft_print_zero_precision(int *count, t_format *flags)
{
	write(1, "0", 1);
	(*count)++;
	flags->precision--;
}

void	ft_putchar_count(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_print_null(int *count)
{
	write(1, "(null)", 6);
	(*count) += 6;
}

void	ft_display(t_format args)
{
	printf("\n==============\nFLAGS\n--------------\n");
	printf("Width: %d\n", args.width);
	printf("Precision: %d\n", args.precision);
	printf("Flags:\n");
	printf("  Zero padding: %s\n", args.zero ? "true" : "false");
	printf("  Hashtag: %s\n", args.hashtag ? "true" : "false");
	printf("  Space: %s\n", args.space ? "true" : "false");
	printf("  Plus: %s\n", args.plus ? "true" : "false");
	printf("  Minus: %s\n", args.minus ? "true" : "false");
}

void	first_flags(char *format, int *index_format, t_format *flags)
{
	while (format[*index_format] && ft_strchr("#+- 0", format[*index_format]))
	{
		if (format[*index_format] == '#')
			flags->hashtag = 1;
		else if (format[*index_format] == '+')
			flags->plus = 1;
		else if (format[*index_format] == '-')
			flags->minus = 1;
		else if (format[*index_format] == ' ')
			flags->space = 1;
		else
			flags->zero = 1;
		(*index_format)++;
	}
}

// fonction qui affiche la lettre de format a l'indice index_format,
// increment le compteur pour le retour
// de ft_printf() et l'index_format
void	ft_putchar_max(char *format, int *count, int *index_format)
{
	write(1, &(format[*index_format]), 1);
	(*count)++;
	(*index_format)++;
}

void	parse_width(char *format, int *index_format, t_format *flags)
{
	while (format[*index_format] && ft_isdigit(format[*index_format]))
	{
		flags->width = flags->width * 10 + format[*index_format] - 48;
		(*index_format)++;
	}
}

void	parse_precision(char *format, int *index_format, t_format *flags)
{
	if (format[*index_format] == '.')
	{
		(*index_format)++;
		while (format[*index_format] && ft_isdigit(format[*index_format]))
		{
			flags->precision = flags->precision * 10 + format[*index_format]
				- 48;
			(*index_format)++;
		}
	}
}
// fonction qui gere les priorite de flag, ex : '-' > '0'
// '+' > ' '
void	check_priority(t_format *flags)
{
	if (flags->minus && flags->zero)
		flags->zero = 0;
	if (flags->plus && flags->space)
		flags->space = 0;
}

void	convert_c(t_format *flags, int *count)
{
	char	result;

	result = (char)va_arg(flags->args, int);
	while (flags->width > 1 && !flags->minus)
		ft_print_space(count, flags);
	write(1, &result, 1);
	(*count)++;
	while (flags->width > 1 && flags->minus)
		ft_print_space(count, flags);
}

void	convert_s(t_format *flags, int *count)
{
	char	*result;
	int		len_result;

	result = va_arg(flags->args, char *);
	if (!result)
		return (ft_print_null(count));
	if (flags->precision && flags->precision < (int)ft_strlen(result))
		result = ft_substr(result, 0, flags->precision);
	len_result = ft_strlen(result);
	while (flags->width && flags->width > len_result && !flags->minus)
		ft_print_space(count, flags);
	ft_putstr_fd(result, 1);
	(*count) += len_result;
	while (flags->width && flags->width > len_result && flags->minus)
		ft_print_space(count, flags);
	if (flags->precision && flags->precision < (int)ft_strlen(result))
		free(result);
}

char	*ft_add_plus(char *s)
{
	char	*result;
	int		len_s;

	len_s = ft_strlen(s);
	result = (char *)malloc((len_s + 2) * sizeof(char));
	result[len_s + 1] = '\0';
	result[0] = '+';
	ft_strlcpy(result + 1, s, len_s);
	free(s);
	return (result);
}
void	convert_id(t_format *flags, int *count)
{
	char	*result;
	int		len_result;
	int		precision;

	precision = flags->precision;
	result = ft_itoa(va_arg(flags->args, int));
	len_result = ft_strlen(result);
	// if (result[0] != '-')
	// 	if (flags->plus || flags->space)
	// 		len_result++;
	while (flags->width > (len_result + (flags->precision - len_result)) && !flags->minus)
		ft_print_space(count, flags);
	if (result[0] != '-')
	{
		if (flags->plus)
			ft_putchar_count('+', count);
		else if (flags->space)
			ft_putchar_count(' ', count);
	}
	while (flags->precision > len_result)
		ft_print_zero_precision(count, flags);
	ft_putstr_fd(result, 1);
	(*count) += len_result;
	while (flags->width > (len_result + (precision - len_result)) && flags->minus)
		ft_print_space(count, flags);
	free(result);
}

void	ft_convert(t_format *flags, char *format, int *count, int *index_format)
{
	char	*conversion_letter;
	char	*i_conv;

	conversion_letter = "cspdiuxX";
	i_conv = ft_strchr(conversion_letter, format[*index_format]);
	if (!i_conv)
		return ;
	else if (*i_conv == 'c')
		convert_c(flags, count);
	else if (*i_conv == 's')
		convert_s(flags, count);
	else if (*i_conv == 'd' || *i_conv == 'i')
		convert_id(flags, count);
	// else if (*i_conv == 'p')
	//     convert_p(flags, count, index_format);
	// else if (*i_conv == 'u')
	//     convert_u(flags, count, index_format);
	// else if (*i_conv == 'x')
	//     convert_x(flags, count, index_format);
	// else
	//     convert_X(flags, count, index_format);
	(*index_format)++;
}

// fonction principale pour construire les parametre apres %
void	ft_construct_param(t_format *flags, char *format, int *count,
		int *index_format)
{
	(*index_format)++;
	if (format[*index_format] == '%')
		return (ft_putchar_max(format, count, index_format));
	first_flags(format, index_format, flags);
	parse_width(format, index_format, flags);
	parse_precision(format, index_format, flags);
	check_priority(flags);
	// ft_display(*flags);
	ft_convert(flags, format, count, index_format);
}

// parcours de la chaine format, initialisation des parametre variadique,
// constructions des parametre apres %
// tient le compte des charactere affiche avec la variable count;
int	ft_printf(char *format, ...)
{
	int			index_format;
	int			count;
	va_list		args;
	t_format	flags;

	va_start(args, format);
	flags = init_flags(&args);
	index_format = 0;
	count = 0;
	while (format[index_format])
	{
		if (format[index_format] == '%' && format[index_format + 1])
			ft_construct_param(&flags, format, &count, &index_format);
		else
			ft_putchar_max(format, &count, &index_format);
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int	count;

// 	count = ft_printf("% 010.5d", 42);
// 	printf("\n% 010.5d", 42);
// 	printf("\n\nCOUNT DE LA FONCTION FT_PRINTF=> %d", count);
// 	return (0);
// }
