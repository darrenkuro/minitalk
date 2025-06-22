# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 01:06:58 by dlu               #+#    #+#              #
#    Updated: 2025/06/22 09:14:19 by dlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	minitalk
PROJECT	:=	$$YELLOW[$(NAME)]$$RESET
TARGET1	:=	server
TARGET2	:=	client

INCDIR	:=	include
_HEADER	:=	minitalk.h
HEADER	:=	$(addprefix $(INCDIR)/,$(_HEADER))

SRCDIR	:=	src

LIBDIR	:=	libft
_LIBFT	:=	libft.a
LIBFT	:=	$(addprefix $(LIBDIR)/,$(_LIBFT))

CC			:=	cc
RM			:=	/bin/rm -f
CFLAGS		:=	-Wall -Wextra -Werror
CPPFLAGS	:=	-I $(INCDIR) -I $(LIBDIR)/$(INCDIR)
LDFLAGS		:=	-L $(LIBDIR)
LDLIBS		:=	-lft

PAD_WIDTH		?=	21
.DEFAULT_GOAL	:=	all
.SILENT:

.PHONY:	all
all:	$(TARGET1) $(TARGET2)

.PHONY:	$(LIBDIR)-clean
$(LIBDIR)-clean:
	if [ -f $(LIBDIR)/Makefile ]; then \
		$(MAKE) -C $(LIBDIR) clean PAD_WIDTH=$(PAD_WIDTH); \
	fi

.PHONY:	clean
clean: $(LIBDIR)-clean

.PHONY:	$(LIBDIR)-fclean
$(LIBDIR)-fclean:
	if [ -f "$(LIBDIR)/Makefile" ]; then \
		$(MAKE) -C $(LIBDIR) fclean PAD_WIDTH=$(PAD_WIDTH); \
	fi

.PHONY:	fclean
fclean:	clean $(LIBDIR)-fclean
	if [ -f "$(TARGET1)" ] || [ -f "$(TARGET2)" ]; then \
		printf "%-*s 🗑️ Removing binaries..." $(PAD_WIDTH) "$(PROJECT)"; \
		$(RM) $(TARGET1) $(TARGET2); \
		echo " ✅ "; \
	fi

.PHONY:	re
re:	fclean all

.PHONY:	bonus
bonus:	all

.PHONY:	$(LIBDIR)-init
$(LIBDIR)-init:
	if git submodule status "$(LIBDIR)" | grep -Eq '^[-+]'; then \
		printf "%-*s 🔄 Initializing submodule $(LIBDIR)...\n" $(PAD_WIDTH) "$(PROJECT)"; \
		git submodule update --init --recursive $(LIBDIR) 2>&1 | sed 's/^/    - /'; \
		printf "%-*s ✅ Git submodule $(LIBDIR) initialized.\n" $(PAD_WIDTH) "$(PROJECT)"; \
	fi

.PHONY:	$(LIBDIR)-deinit
$(LIBDIR)-deinit:
	if [ -f "$(LIBDIR)/.git" ]; then \
		printf "%-*s 🧹 Deinitializing $(LIBDIR) submodule...\n" \
		$(PAD_WIDTH) "$(PROJECT)"; \
		git submodule deinit -f $(LIBDIR) 2>&1 | sed 's/^/    - /'; \
		printf "%-*s ✅ Git submodule $(LIBDIR) deinitialized.\n" \
		$(PAD_WIDTH) "$(PROJECT)"; \
	fi

%:	$(SRCDIR)/%.c $(LIBFT) $(HEADER)
	printf "%-*s 🛠️ Building binary: $@" $(PAD_WIDTH) "$(PROJECT)"
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)
	echo " ✅ "

$(LIBFT):	$(LIBDIR)-init
	printf "%-*s ⚙️ Building $(_LIBFT)...\n" $(PAD_WIDTH) "$(PROJECT)"
	$(MAKE) -C $(LIBDIR) --silent PAD_WIDTH=$(PAD_WIDTH)
	printf "%-*s ✅ $(_LIBFT) built.\n" $(PAD_WIDTH) "$(PROJECT)"