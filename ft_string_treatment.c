/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_treatment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 20:01:00 by adratini          #+#    #+#             */
/*   Updated: 2021/12/25 20:01:01 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_char(char c)
{
	ft_putchar(c);
	return (1);
}

int	treat_string(char *str)
{
	int	char_count;

	char_count = 0;
	if (!str)
	{
		char_count = ft_strlen("(null)");
		ft_putstr("(null)");
	}
	else
	{
		char_count = ft_strlen(str);
		ft_putstr(str);
	}
	return (char_count);
}
