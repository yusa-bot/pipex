/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:42:33 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 18:54:18 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_format	ft_flag_minus(t_format p)
{
	p.minus = 1;
	p.zero = 0;
	return (p);
}

static void	ft_parse_width(const char *fmt, t_format *p, int i)
{
	while (fmt[i] != '.' && !ft_isspec(fmt[i]))
	{
		if (ft_isdigit(fmt[i]) && !p->width)
			p->width = ft_atoi(fmt + i);
		i++;
	}
}

static void	ft_parse_prec(const char *fmt, t_format *p, int i)
{
	p->dot = 1;
	p->zero = 0;
	p->prec = ft_atoi(&fmt[i + 1]);
	if (p->prec < 0)
		p->prec = 0;
}

int	ft_parse_flag(const char *fmt, t_format *p, int i)
{
	while (fmt[++i] && ft_isflag(fmt[i]))
	{
		if (fmt[i] == '-')
			*p = ft_flag_minus(*p);
		else if (fmt[i] == '#')
			p->sharp = 1;
		else if (fmt[i] == ' ')
			p->space = 1;
		else if (fmt[i] == '+')
			p->plus = 1;
		else if (fmt[i] == '0' && !p->minus && !p->width)
			p->zero = 1;
		if (ft_isdigit(fmt[i]) && !p->width && !p->dot)
			ft_parse_width(fmt, p, i);
		if (fmt[i] == '.')
			ft_parse_prec(fmt, p, i);
		if (ft_isspec(fmt[i]))
		{
			p->specifier = fmt[i];
			break ;
		}
	}
	return (i);
}
