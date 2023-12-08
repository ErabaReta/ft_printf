/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:47:13 by eouhrich          #+#    #+#             */
/*   Updated: 2023/11/25 21:49:16 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char )c)
			return (&str[i]);
		i++;
	}
	if ((char )c == '\0' && str[i] == '\0' )
		return (&str[i]);
	return (NULL);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	digits_counter(const char *format, int *i)
{
	int	nbr;

	nbr = 0;
	while (isdigit(format[*i]))
	{
		nbr *= 10;
		nbr += format[*i] - '0';
		i += 1;
	}
	return (nbr);
}
