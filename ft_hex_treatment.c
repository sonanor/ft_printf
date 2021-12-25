/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_treatment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:23:51 by adratini          #+#    #+#             */
/*   Updated: 2021/12/19 17:23:53 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int num)
{
	int	char_count;

	char_count = 0;
	while (num != 0)
	{
		char_count++;
		num /= 16;
	}
	return (char_count);
}

void	print_hex(unsigned int num, char c)
{
	if (num >= 16)
	{
		print_hex(num / 16, c);
		print_hex(num % 16, c);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (c == 'x')
				ft_putchar(num - 10 + 'a');
			else
				ft_putchar(num - 10 + 'A');
		}
	}
}

int	treat_hex(unsigned int num, char c)
{
	int	char_count;

	char_count = ft_hex_len(num);
	if (num == 0)
		return (write(1, "0", 1));
	print_hex(num, c);
	return (char_count);
}
