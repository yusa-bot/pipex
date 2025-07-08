/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:41:18 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 18:54:24 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(char c, t_format *p)
{
	int	len;

	len = 0;
	if (p->minus)
		len += ft_putchar_fd(c, 1);
	len += ft_padding_width(p->width, 1, 0);
	if (!p->minus)
		len += ft_putchar_fd(c, 1);
	p->width = 0;
	return (len);
}
