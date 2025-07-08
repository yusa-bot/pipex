/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:53:32 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 18:54:11 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_padding_width(int width, int size, int zero)
{
	int	len;

	len = 0;
	while (width - size > 0)
	{
		if (zero)
			len += ft_putchar_fd('0', 1);
		else
			len += ft_putchar_fd(' ', 1);
		width--;
	}
	return (len);
}

int	ft_print_str(const char *str)
{
	if (str == NULL)
		return (ft_putstrn_fd("(null)", 1, 6));
	return (ft_putstrn_fd((char *)str, 1, ft_strlen(str)));
}
