/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:39:10 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/06 14:56:02 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	ft_new_fmt(void)
{
	t_format	new_format;

	ft_bzero(&new_format, sizeof(new_format));
	new_format.prec = -1;
	return (new_format);
}

int	ft_printf(const char *fmt, ...)
{
	t_format	p;
	va_list		ap;
	char		*fmt_dup;

	if (!fmt || *fmt == '\0')
		return (0);
	p = ft_new_fmt();
	fmt_dup = ft_strdup(fmt);
	if (!fmt_dup || *fmt_dup == '\0')
		return (0);
	va_start(ap, fmt);
	ft_parse(fmt_dup, ap, &p);
	va_end(ap);
	free(fmt_dup);
	return (p.len);
}
