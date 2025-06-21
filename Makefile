# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 01:06:58 by dlu               #+#    #+#              #
#    Updated: 2025/06/21 19:58:26 by dlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	minitalk
PROJECT	:=	$$YELLOW[$(NAME)]$$RESET
TARGET1	:=	server
TARGET2	:=	client

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
all: $(TARGET1) $(TARGET2)

.PHONY: clean
clean:
	@$(MAKE) -C $(LIBDIR) $@

.PHONY: fclean
fclean: clean
	@$(MAKE) -C $(LIBDIR) $@
	@printf "$(PROJECT) 🗑️ Removing binary files..."
	@$(RM) $(TARGET1) $(TARGET2)
	@echo " ✅ "

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: all

%: $(SRCDIR)/%.c $(LIBFT) $(HEADER)
	@printf "$(PROJECT) ⚙️ Compiling: $<..."
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)
	@echo " ✅ "

$(LIBFT):
	@printf "$(PROJECT) 🔄 Initializing and updating git submodules..."
	@git submodule update --init --recursive
	@echo " ✅ "
	@echo "$(PROJECT) ⚙️ Building libft..."
	@$(MAKE) -C $(LIBDIR) --silent