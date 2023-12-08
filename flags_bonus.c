/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:39:30 by eouhrich          #+#    #+#             */
/*   Updated: 2023/11/28 10:39:32 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_is_exist(const char *format, int *i, int *existence_of_flag)
{
	existence_of_flag[0] = 0;
	existence_of_flag[1] = 0;
	existence_of_flag[2] = 0;
	while (format[*i + 1] == '+' || format[*i + 1] == ' '
		|| format[*i + 1] == '#')
	{
		if (format[*i + 1] == '+')
			existence_of_flag[0] = 1;
		if (format[*i + 1] == ' ')
			existence_of_flag[1] = 1;
		if (format[*i + 1] == '#')
			existence_of_flag[2] = 1;
		*i += 1;
	}
}

int	hash_flag(int is_exist, const char *format, int i, va_list *args)
{
	unsigned int	nbr;
	int				count;

	count = 0;
	nbr = va_arg(*args, unsigned int);
	if (format[i + 1] == 'x')
	{
		if (nbr != 0 && is_exist == 1)
			count += ft_putstr("0x");
		ft_putnbr_base(nbr, "0123456789abcdef", &count, "");
	}
	else if (format[i + 1] == 'X')
	{
		if (nbr != 0 && is_exist == 1)
			count += ft_putstr("0X");
		ft_putnbr_base(nbr, "0123456789ABCDEF", &count, "");
	}
	return (count);
}

void	bonus_flags(const char *format, int *i, va_list *args, int *count)
{
	char	passing_flag[1];
	int		existence_of_flag[3];

	flag_is_exist(format, i, existence_of_flag);
	if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
	{
		if (existence_of_flag[0] == 1)
		{
			passing_flag[0] = '+';
			ft_putnbr_base(va_arg(*args, int), "0123456789",
				count, passing_flag);
		}
		if (existence_of_flag[1] == 1 && existence_of_flag[0] == 0)
		{
			passing_flag[0] = ' ';
			ft_putnbr_base(va_arg(*args, int), "0123456789",
				count, passing_flag);
		}
	}
	else if (format[*i + 1] == 'x' || format[*i + 1] == 'X')
	{
		*count += hash_flag(existence_of_flag[2], format, *i, args);
	}
	else if (ft_strchr("cspu%", format[*i + 1]) != NULL)
		*count += mendatory_flag(format[*i + 1], args);
}
