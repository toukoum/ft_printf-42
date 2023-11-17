/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:56:45 by rgiraud           #+#    #+#             */
/*   Updated: 2023/11/17 17:06:03 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_format    init_flags(t_format flags)
{
    
    ft_bzero(&flags, sizeof(t_format));
    return (flags);
}

// fontion qui boucle sur les flags, si 
int set_flags(char *format, int i, t_format flags)
{

    while (ft_isdigit(format[i]))
    {
        if (!flags.pad_right)
            flags.pad_left = true;
        flags.pad_count = flags.pad_left * 10 + (format[i] - 48);
        i++;
    }
    if (format[i] == '-')
    
}



void ft_construct_param(va_list args, char *format, size_t *count, size_t *index)
{
    int i;
    t_format flags;

    flags = init_flags(flags);
    (*index)++;
    i = index;
    if (format[*index] == '%')
    {
        write(1, &(format[*index]), 1);\
        (*count)++;
        (*index)++;
        return ;
    }
    while (format[i] && !ft_strrchr("cspdiuxX", format[i]))
    {
        i = set_flags(format, i, flags);
        
        if (i == -1)
        {
            write(1, '%', 1);
            return ;
        }
    }
    
    // else if (format[*i] == 'i' || format[*i] == 'd')
    // {
    //     ft_parse
    // }
    
    
    
}
int ft_printf(char *format, ...) 
{
    size_t  i;
    size_t  count;
    va_list args;
    
    va_start(args, format);
    i = 0;
    count = 0;
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            ft_construct_param(args, format, &count, &i);
        }
        else
        {
            write(1, &format[i], 1);
            count++;
            i++;
        }
    }
    
    va_end(args);
    return (count);
}

int main() {
    int count;
    
    count = ft_printf("bonjour %%");
    printf("\nbonjour %%%");



    printf("\nCOUNT=> %d", count);
    return 0;
}

