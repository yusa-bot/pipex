/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:34:54 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 18:55:00 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pdata(t_format *p, char spec, va_list ap)
{
	if (spec == '%')
		p->len += ft_putchar_fd('%', 1);
	else if (spec == 'c')
		p->len += ft_print_c(va_arg(ap, int), p);
	else if (spec == 's')
		p->len += ft_print_s(va_arg(ap, const char *), *p);
	else if (spec == 'd' || spec == 'i')
		p->len += ft_print_di(va_arg(ap, int), p);
	else if (spec == 'u')
		p->len += ft_print_u(va_arg(ap, unsigned int), *p);
	else if (spec == 'x')
		p->len += ft_print_x(va_arg(ap, unsigned int), 0, *p);
	else if (spec == 'X')
		p->len += ft_print_x(va_arg(ap, unsigned int), 1, *p);
	else if (spec == 'p')
		p->len += ft_print_p((unsigned long int)va_arg(ap, void *), *p);
}
