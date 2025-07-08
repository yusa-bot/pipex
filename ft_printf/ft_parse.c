/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:06:18 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 18:54:21 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_reset_fmt(t_format *p)
{
	*p = (t_format){0};
	p->prec = -1;
}

int	ft_parse(const char *fmt, va_list ap, t_format *p)
{
	int		i;
	int		spec_len;

	i = -1;
	while (fmt[++i] != '\0')
	{
		ft_reset_fmt(p);
		if (fmt[i] == '%')
		{
			spec_len = ft_parse_flag(fmt, p, i);
			if (p->specifier)
				i = spec_len;
			if (fmt[i] && (p->specifier > 0) && ft_isspec(fmt[i]))
				ft_print_pdata(p, fmt[i], ap);
			else if (fmt[i] != '\0')
				p->len += ft_putchar_fd(fmt[i], 1);
		}
		else
			p->len += ft_putchar_fd(fmt[i], 1);
	}
	return (p->len);
}
