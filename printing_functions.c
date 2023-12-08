/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:50:52 by eouhrich          #+#    #+#             */
/*   Updated: 2023/11/25 21:52:30 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

void	ft_putnbr_base(long long n, char *base, int *count, char *flag)
{
	int	len;

	len = ft_strlen(base);
	if (n >= 0 && flag[0] != '\0')
	{
		if (flag[0] == '+')
			*count += write(1, "+", 1);
		if (flag[0] == ' ')
			*count += write(1, " ", 1);
		flag[0] = '\0';
	}
	if (n < 0)
	{
		*count += write(1, "-", 1);
		n = 0 - n;
		if (flag[0] != '\0')
			flag[0] = '\0';
	}
	if (n > (len - 1))
	{
		ft_putnbr_base(n / len, base, count, flag);
		ft_putnbr_base(n % len, base, count, flag);
	}
	else
		*count += write(1, &base[n], 1);
}

void	print_adress(unsigned long n, char *base, int *count)
{
	unsigned long	len;

	len = ft_strlen(base);
	if (n < 0)
	{
		*count += write(1, "-", 1);
		n = 0 - n;
	}
	if (n > (len - 1))
	{
		print_adress(n / len, base, count);
		print_adress(n % len, base, count);
	}
	else
		*count += write(1, &base[n], 1);
}
