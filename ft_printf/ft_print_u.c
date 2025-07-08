/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:06:09 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 18:54:46 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_unsigned(char	*numstr, t_format p)
{
	int	len;

	len = 0;
	if (p.prec >= 0)
		len += ft_padding_width((p.prec - 1), (ft_strlen(numstr) - 1), 1);
	len += ft_print_str(numstr);
	return (len);
}

static int	ft_print_unit(char *numstr, t_format p)
{
	int	len;

	len = 0;
	if (p.minus)
		len += ft_print_unsigned(numstr, p);
	if ((p.prec >= 0) && (size_t)p.prec < ft_strlen(numstr))
		p.prec = ft_strlen(numstr);
	if (p.prec >= 0)
	{
		p.width -= p.prec;
		len += ft_padding_width(p.width, 0, 0);
	}
	else
		len += ft_padding_width(p.width, ft_strlen(numstr), p.zero);
	if (!p.minus)
		len += ft_print_unsigned(numstr, p);
	return (len);
}

int	ft_print_u(unsigned int n, t_format p)
{
	int		len;
	char	*numstr;

	len = 0;
	if (!p.prec && n == 0)
	{
		len += ft_padding_width(p.width, 0, 0);
		return (len);
	}
	numstr = ft_uitoa(n);
	if (!numstr)
		return (0);
	len += ft_print_unit(numstr, p);
	free(numstr);
	return (len);
}
