/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:39:08 by eouhrich          #+#    #+#             */
/*   Updated: 2023/11/28 10:39:11 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mendatory_flag(char c, va_list *args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(*args, int));
	if (c == 's')
		count = ft_putstr(va_arg(*args, char *));
	if (c == 'p')
	{
		count += ft_putstr("0x");
		print_adress(va_arg(*args, unsigned long), "0123456789abcdef", &count);
	}
	if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(*args, int), "0123456789", &count, "");
	if (c == 'u')
		ft_putnbr_base(va_arg(*args, unsigned int), "0123456789", &count, "");
	if (c == 'x')
		ft_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef",
			&count, "");
	if (c == 'X')
		ft_putnbr_base(va_arg(*args, unsigned int), "0123456789ABCDEF",
			&count, "");
	if (c == '%')
		count += ft_putchar('%');
	return (count);
}
