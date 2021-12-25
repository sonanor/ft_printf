/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_treatment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 21:23:21 by adratini          #+#    #+#             */
/*   Updated: 2021/12/18 21:23:57 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t ull_ptr)
{
	int	char_count;

	char_count = 0;
	while (ull_ptr != 0)
	{
		char_count++;
		ull_ptr /= 16;
	}
	return (char_count);
}

void	print_poiner(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		print_poiner(ptr / 16);
		print_poiner(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr - 10 + 'a');
	}
}

int	treat_pointer(unsigned long long ull_ptr)
{
	int	char_count;

	char_count = 2;
	ft_putstr("0x");
	if (ull_ptr == 0)
	{
		ft_putchar('0');
		char_count++;
	}
	else
	{
		print_poiner(ull_ptr);
		char_count += ft_ptr_len(ull_ptr);
	}
	return (char_count);
}
