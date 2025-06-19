# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 01:06:58 by dlu               #+#    #+#              #
#    Updated: 2025/06/20 01:09:14 by dlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	:=	server
NAME2	:=	client

HEADER	:=	minitalk.h
SRCS	:=	server.c client.c
LIBDIR	:=	libft

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
RM		:=	/bin/rm -f

.PHONY: all
all: $(NAME1) $(NAME2)

.PHONY: clean
clean:
	@make -C $(LIBDIR) clean >/dev/null

.PHONY: fclean
fclean: clean
	@make -C $(LIBDIR) fclean >/dev/null
	$(RM) $(NAME1) $(NAME2)

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: all

%: %.c $(HEADER)
	@make -C $(LIBDIR) all >/dev/null
	$(CC) $(CFLAGS) -o $@ $< -L $(LIBDIR) -lft -I $(LIBDIR)