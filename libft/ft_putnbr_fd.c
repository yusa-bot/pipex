/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:44:05 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 15:04:55 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	*c;
	int		len;

	len = 0;
	c = ft_itoa(n);
	if (!c)
		return (0);
	len += write(fd, c, ft_strlen(c));
	free(c);
	return (len);
}
