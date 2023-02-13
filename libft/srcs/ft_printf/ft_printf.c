/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:05:13 by hvercell          #+#    #+#             */
/*   Updated: 2023/02/09 17:02:12 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_good_formart(char c, va_list value)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_printc(va_arg(value, int));
	else if (c == 's')
		len = ft_prints(va_arg(value, char *));
	else if (c == 'p')
		len = ft_printp(va_arg(value, size_t));
	else if (c == 'd' || c == 'i')
		len = ft_printdi(va_arg(value, int));
	else if (c == 'u')
		len = ft_printu(va_arg(value, unsigned int));
	else if (c == 'x')
		len = ft_printx(va_arg(value, unsigned int));
	else if (c == 'X')
		len = ft_printx_(va_arg(value, unsigned int));
	else if (c == '%')
		len = ft_printc('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{	
	int			i;
	int			len;
	va_list		args;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%'
			&& ft_memchr("cspdiuxX%", format[i + 1], 9) != NULL)
		{
			len += ft_print_good_formart(format[i + 1], args);
			++i;
		}
		else
		{
			ft_printc(format[i]);
			++len;
		}
		++i;
	}
	va_end(args);
	return (len);
}
