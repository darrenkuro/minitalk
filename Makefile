# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 01:06:58 by dlu               #+#    #+#              #
#    Updated: 2025/06/21 01:22:04 by dlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	:=	server
NAME2	:=	client

SRCDIR	:=	src

INCDIR	:=	include
_HEADER	:=	minitalk.h
HEADER	:=	$(addprefix $(INCDIR)/, $(_HEADER))

LIBDIR	:=	libft
_LIBFT	:=	libft.a
LIBFT	:=	$(addprefix $(LIBDIR)/, $(_LIBFT))

CC			:=	cc
RM			:=	/bin/rm -f
CFLAGS		:=	-Wall -Wextra -Werror
CPPFLAGS	:=	-I $(INCDIR) -I $(LIBDIR)/$(INCDIR)
LDFLAGS		:=	-L $(LIBDIR)
LDLIBS		:=	-lft

.DEFAULT_GOAL	:=	all

.PHONY: all
all: $(NAME1) $(NAME2)

.PHONY: clean
clean:
	$(MAKE) -C $(LIBDIR) $@ --silent

.PHONY: fclean
fclean: clean
	$(MAKE) -C $(LIBDIR) $@ --silent
	$(RM) $(NAME1) $(NAME2)

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: all

%: $(SRCDIR)/%.c $(LIBFT) $(HEADER)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

$(LIBFT):
	git submodule update --init --recursive
	$(MAKE) -C $(LIBDIR)