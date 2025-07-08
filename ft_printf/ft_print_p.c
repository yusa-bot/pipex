/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:52:35 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 18:54:39 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(unsigned long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n = n / 16;
		++len;
	}
	return (len);
}

static void	ft_print_address(unsigned long int n)
{
	if (n >= 16)
	{
		ft_print_address(n / 16);
		ft_print_address(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd((n + '0'), 1);
		else if (n >= 10)
			ft_putchar_fd(((n - 10) + 'a'), 1);
	}
}

static int	ft_print_ptr(unsigned long int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		len += ft_print_str("(nil)");
		return (len);
	}
	len += ft_print_str("0x");
	ft_print_address(n);
	len += ft_ptrlen(n);
	return (len);
}

int	ft_print_p(unsigned long int n, t_format p)
{
	int	len;

	len = 0;
	if (n == 0)
		p.width -= ft_strlen("(nil)") - 1;
	else
		p.width -= 2;
	if (p.minus)
		len += ft_print_ptr(n);
	len += ft_padding_width(p.width, ft_ptrlen(n), 0);
	if (!p.minus)
		len += ft_print_ptr(n);
	return (len);
}
