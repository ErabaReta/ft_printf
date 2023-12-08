/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:38:55 by eouhrich          #+#    #+#             */
/*   Updated: 2023/11/28 10:38:57 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	flag_checker(const char *format, int *i, va_list *args, int *count)
{
	if (ft_strchr("cspdiuxX%", format[*i + 1]) != NULL)
		*count += mendatory_flag(format[*i + 1], args);
	else if (ft_strchr(" +#", format[*i + 1]) != NULL)
		bonus_flags(format, i, args, count);
	else if (format[*i + 1])
		*count += ft_putchar(format[*i + 1]);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			flag_checker(format, &i, &args, &count);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		if (format[i] != '\0')
			i++;
	}
	va_end(args);
	return (count);
}
