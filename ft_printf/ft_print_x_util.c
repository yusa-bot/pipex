/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:15:15 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 18:54:51 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_xtoa(unsigned long int nb, int is_upper)
{
	char	*base;
	char	buffer[17];
	char	*result;
	int		i;

	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 16;
	buffer[i] = '\0';
	if (nb == 0)
		buffer[--i] = '0';
	while (nb > 0)
	{
		buffer[--i] = base[nb % 16];
		nb /= 16;
	}
	result = ft_strdup(&buffer[i]);
	return (result);
}

int	ft_putx_prefix(int is_upper)
{
	if (is_upper)
		return (write(1, "0X", 2));
	return (write(1, "0x", 2));
}

int	ft_puthex(char *numstr, size_t n, int is_upper, t_format p)
{
	int	len;

	len = 0;
	if (!p.zero && p.sharp && (n != 0))
		len += ft_putx_prefix(is_upper);
	if (p.prec >= 0)
		len += ft_padding_width((p.prec - 1), (ft_strlen(numstr) - 1), 1);
	len += ft_print_str(numstr);
	return (len);
}
