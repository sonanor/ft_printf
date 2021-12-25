/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:18:39 by adratini          #+#    #+#             */
/*   Updated: 2021/12/18 16:18:40 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_specifier(char c, va_list args)
{
	int	char_count;

	char_count = 0;
	if (c == 'c')
		char_count = treat_char(va_arg(args, int));
	if (c == 's')
		char_count = treat_string(va_arg(args, char *));
	if (c == 'p')
		char_count = treat_pointer(va_arg(args, unsigned long long));
	if (c == 'd' || c == 'i')
		char_count = treat_integer(va_arg(args, int));
	if (c == 'u')
		char_count = treat_unsigned_int(va_arg(args, unsigned int));
	if (c == 'x' || c == 'X')
		char_count = treat_hex(va_arg(args, unsigned int), c);
	return (char_count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			char_count;
	int			i;

	va_start(args, format);
	i = 0;
	char_count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[++i] == '%')
				char_count += write(1, &format[i], 1);
			else if (ft_strchr("cspdiuxX", format[i]))
				char_count += treat_specifier(format[i], args);
		}
		else
			char_count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (char_count);
}
