/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:50:36 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 18:54:43 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_s_prec(const char *str, int prec)
{
	int	len;

	len = 0;
	while (str[len] && len < prec)
		ft_putchar_fd(str[len++], 1);
	return (len);
}

static int	ft_putstr(const char *s, t_format p)
{
	int	len;

	len = 0;
	if (p.prec >= 0)
	{
		len += ft_print_s_prec(s, p.prec);
	}
	else
		len += ft_print_s_prec(s, ft_strlen(s));
	return (len);
}

int	ft_print_s(const char *str, t_format p)
{
	int	len;

	len = 0;
	if ((str == NULL) && (p.prec >= 0) && (p.prec < 6))
		str = "";
	if (str == NULL)
		str = "(null)";
	if ((p.prec >= 0) && ((size_t)p.prec > ft_strlen(str)))
		p.prec = ft_strlen(str);
	if (p.minus)
		len += ft_putstr(str, p);
	if (p.prec >= 0)
		len += ft_padding_width(p.width, p.prec, 0);
	else
		len += ft_padding_width(p.width, ft_strlen(str), 0);
	if (!p.minus)
		len += ft_putstr(str, p);
	return (len);
}
