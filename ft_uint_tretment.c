/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_tretment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:24:13 by adratini          #+#    #+#             */
/*   Updated: 2021/12/19 17:24:14 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	uint_digit_len(unsigned int num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

int	treat_unsigned_int(unsigned int num)
{
	int		char_count;

	char_count = uint_digit_len(num);
	if (num >= 10)
	{
		treat_unsigned_int(num / 10);
		treat_unsigned_int(num % 10);
	}
	else
		ft_putchar(num + '0');
	return (char_count);
}
