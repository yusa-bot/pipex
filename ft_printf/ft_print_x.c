/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:02:57 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 18:54:57 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex(char *numstr, size_t n, int is_upper, t_format *p)
{
	int	len;

	len = 0;
	if (p->sharp && n != 0)
		p->width -= 2;
	if (p->zero && p->sharp && n != 0)
		len += ft_putx_prefix(is_upper);
	if (p->minus)
		len += ft_puthex(numstr, n, is_upper, *p);
	if ((p->prec >= 0) && ((size_t)p->prec < ft_strlen(numstr)))
		p->prec = ft_strlen(numstr);
	if (p->prec >= 0)
	{
		p->width -= p->prec;
		len += ft_padding_width(p->width, 0, 0);
	}
	else
		len += ft_padding_width(p->width, ft_strlen(numstr), p->zero);
	if (!p->minus)
		len += ft_puthex(numstr, n, is_upper, *p);
	return (len);
}

static int	prec_zero_n_zero_x(int len, size_t n, t_format *p)
{
	int	prefix_len;

	if (p->prec == 0 && n == 0)
	{
		prefix_len = 0;
		if (p->plus || p->space)
			prefix_len = 1;
		if (p->minus)
		{
			if (p->plus)
				len += ft_putchar_fd('+', 1);
			else if (p->space)
				len += ft_putchar_fd(' ', 1);
			len += ft_padding_width(p->width, prefix_len, 0);
		}
		else
		{
			len += ft_padding_width(p->width, prefix_len, 0);
			if (p->plus)
				len += ft_putchar_fd('+', 1);
			else if (p->space)
				len += ft_putchar_fd(' ', 1);
		}
	}
	return (len);
}

int	ft_print_x(size_t n, int is_upper, t_format p)
{
	char	*numstr;
	int		len;

	len = 0;
	if (p.prec == 0 && n == 0)
	{
		len += prec_zero_n_zero_x(len, n, &p);
		return (len);
	}
	numstr = ft_xtoa(n, is_upper);
	if (!numstr)
		return (0);
	len += ft_print_hex(numstr, n, is_upper, &p);
	free(numstr);
	return (len);
}
