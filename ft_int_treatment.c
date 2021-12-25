/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_treatment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:49:15 by adratini          #+#    #+#             */
/*   Updated: 2021/12/18 22:49:17 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	digit_len(int num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		len = 1;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

int	treat_integer(int num)
{
	int		char_count;

	char_count = digit_len(num);
	if (num == -2147483648)
	{
		ft_putstr("-2147483648");
		return (char_count);
	}
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
	{
		treat_integer(num / 10);
		treat_integer(num % 10);
	}
	else
		ft_putchar(num + '0');
	return (char_count);
}
