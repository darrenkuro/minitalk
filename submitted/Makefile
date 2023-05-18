SRCS=server.c client.c
CC=cc
LIBDIR=libft
RM=/bin/rm -f
CFLAGS=-Wall -Wextra -Werror

all: server client

%: %.c
	@make -C $(LIBDIR) all >/dev/null
	$(CC) $(CFLAGS) -o $@ $< -L $(LIBDIR) -lft -I $(LIBDIR)

%: %.c
	@make -C $(LIBDIR) all >/dev/null
	$(CC) $(CFLAGS) -o $@ $< -L $(LIBDIR) -lft -I $(LIBDIR)

clean:
	@make -C $(LIBDIR) clean >/dev/null

fclean: clean
	@make -C $(LIBDIR) fclean >/dev/null
	$(RM) server client

re: fclean all

.PHONY: all clean fclean re
