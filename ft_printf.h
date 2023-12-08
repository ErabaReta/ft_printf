/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:34:02 by eouhrich          #+#    #+#             */
/*   Updated: 2023/11/26 09:44:43 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *format, ...);
int		mendatory_flag(char c, va_list *args);
void	ft_putnbr_base(long long n, char *base, int *count, char *flag);
int		ft_putchar(char c);
int		ft_putstr(char *s);
void	print_adress(unsigned long n, char *base, int *count);
int		ft_strlen(char *s);
int		digits_counter(const char *format, int *i);
void	bonus_flags(const char *format, int *i, va_list *args, int *count);
void	flag_checker(const char *format, int *i, va_list *args, int *count);
void	flag_is_exist(const char *format, int *i, int *existence_of_flag);
#endif
