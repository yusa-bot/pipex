/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:32:54 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/06 14:56:48 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_format
{
	int				len;
	int				neg;
	char			specifier;
	unsigned int	minus : 1;
	unsigned int	plus : 1;
	unsigned int	zero : 1;
	unsigned int	dot : 1;
	unsigned int	space : 1;
	unsigned int	sharp : 1;
	int				width;
	int				prec;
}	t_format;

t_format	ft_new_fmt(void);
int			ft_printf(const char *fmt, ...);

int			ft_parse(const char *fmt, va_list ap, t_format *p);

int			ft_parse_flag(const char *fmt, t_format *p, int i);

int			ft_isspec(int c);
int			ft_isflagtype(int c);
int			ft_isflag(int c);

void		ft_print_pdata(t_format *p, char spec, va_list ap);

int			ft_print_c(char c, t_format *p);

int			ft_print_s(const char *str, t_format p);

int			ft_print_di(int n, t_format *p);

int			ft_print_u(unsigned int n, t_format p);

int			ft_print_p(unsigned long int n, t_format p);

int			ft_print_x(size_t n, int is_upper, t_format p);

char		*ft_xtoa(unsigned long int nb, int is_upper);
int			ft_putx_prefix(int is_upper);
int			ft_puthex(char *numstr, size_t n, int is_upper, t_format p);

int			ft_padding_width(int width, int size, int zero);
int			ft_print_str(const char *str);

#endif
