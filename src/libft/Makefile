# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 01:09:31 by dlu               #+#    #+#              #
#    Updated: 2025/06/20 01:13:33 by dlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a
SRC		:=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
			ft_memset.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_memcmp.c \
			ft_calloc.c ft_itoa.c ft_atoi.c ft_bzero.c ft_strmapi.c \
			ft_strncmp.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strnstr.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
			ft_lstnew.c ft_lstdelone.c ft_lstadd_front.c ft_lstadd_back.c \
			ft_lstlast.c ft_lstsize.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
			ft_printf.c ft_printf_parse_format.c ft_printf_parse_nbr.c \
			ft_printf_print.c ft_printf_utils.c

OBJ			:=	$(SRC:.c=.o)
OBJ_BONUS	:=	$(SRC_BONUS:.c=.o)

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
AR		:=	ar rcs
RM		:=	/bin/rm -f

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all
