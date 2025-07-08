# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 00:02:40 by ayusa             #+#    #+#              #
#    Updated: 2025/07/08 22:58:58 by ayusa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_isdigit.c ft_memset.c ft_strchr.c \
       ft_strmapi.c ft_toupper.c ft_atol.c ft_isprint.c \
       ft_putchar_fd.c ft_strdup.c ft_strncmp.c ft_uitoa.c \
       ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_striteri.c \
       ft_strnstr.c ft_calloc.c ft_memchr.c ft_putnbr_fd.c \
       ft_strjoin.c ft_strrchr.c ft_isalnum.c ft_memcmp.c \
       ft_putstr_fd.c ft_strlcat.c ft_strtrim.c ft_isalpha.c \
       ft_memcpy.c ft_putstrn_fd.c ft_strlcpy.c ft_substr.c \
       ft_isascii.c ft_memmove.c ft_split.c ft_strlen.c \
       ft_tolower.c ft_split_c.c
OBJS = $(SRCS:.c=.o)

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
