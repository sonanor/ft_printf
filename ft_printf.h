/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:19:59 by adratini          #+#    #+#             */
/*   Updated: 2021/12/18 16:20:01 by adratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_treat_format(const char *format, va_list args);
int		treat_char(char c);
void	ft_putchar(char c);
char	*ft_strchr(const char *str, int ch);
int		treat_string(char *str);
void	print_poiner(uintptr_t ptr);
int		ft_strlen(const char *str);
void	ft_putstr(char *str);
int		treat_pointer(unsigned long long ptr);
int		ft_ptr_len(uintptr_t ull_ptr);
int		treat_specifier(char c, va_list args);
size_t	digit_len(int num);
int		treat_integer(int num);
int		treat_unsigned_int(unsigned int num);
size_t	uint_digit_len(unsigned int num);
int		treat_hex(unsigned int num, char c);
int		ft_hex_len(unsigned int num);
void	print_hex(unsigned int num, char c);

#endif
