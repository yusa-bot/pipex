/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:51:43 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 18:54:33 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_sign_prec(int n, t_format *p)
{
	int	len;

	len = 0;
	if ((n < 0) && p->prec == -1)
	{
		len += ft_putchar_fd('-', 1);
		--p->width;
	}
	else if (p->plus)
	{
		len += ft_putchar_fd('+', 1);
		--p->width;
	}
	else if (p->space)
	{
		len += ft_putchar_fd(' ', 1);
		--p->width;
	}
	return (len);
}

static int	ft_print_i(char *numstr, int n, t_format *p)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		if (!p->zero || p->prec >= 0)
			len += ft_putchar_fd('-', 1);
	}
	else if (p->plus && !p->zero)
		len += ft_putchar_fd('+', 1);
	else if (p->space && !p->zero)
		len += ft_putchar_fd(' ', 1);
	if (p->prec == 0 && n == 0)
		return (0);
	if (p->prec >= 0)
		len += ft_padding_width((p->prec - 1), (ft_strlen(numstr) - 1), 1);
	len += ft_print_str(numstr);
	return (len);
}

static int	ft_print_integer(char *numstr, int n, t_format *p)
{
	int	len;

	len = 0;
	if ((p->neg || p->plus || p->space) && !p->zero)
		--p->width;
	if (p->zero)
		len += ft_print_sign_prec(n, p);
	if (p->minus)
		len += ft_print_i(numstr, n, p);
	if ((p->prec >= 0) && ((size_t)p->prec < ft_strlen(numstr)) && n != 0)
		p->prec = ft_strlen(numstr);
	if (p->prec >= 0)
	{
		p->width -= p->prec;
		len += ft_padding_width(p->width, 0, 0);
	}
	else
		len += ft_padding_width(p->width, ft_strlen(numstr), p->zero);
	if (!p->minus)
		len += ft_print_i(numstr, n, p);
	return (len);
}

static int	prec_zero_n_zero_di(int len, t_format *p)
{
	int	prefix_len;

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
	return (len);
}

int	ft_print_di(int arg_di, t_format *p)
{
	long	nbr;
	int		len;
	char	*numstr;

	nbr = (long)arg_di;
	len = 0;
	if (nbr < 0)
	{
		p->neg = 1;
		if (nbr == -2147483648)
			return (ft_putstr_fd("-2147483648", 1));
		nbr = -nbr;
	}
	if (p->prec == 0 && arg_di == 0)
	{
		len += prec_zero_n_zero_di(len, p);
		return (len);
	}
	numstr = ft_itoa(nbr);
	if (!numstr)
		return (0);
	len += ft_print_integer(numstr, arg_di, p);
	free(numstr);
	return (len);
}
