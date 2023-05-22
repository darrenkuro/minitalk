NAME1=server
NAME2=client
HEADER=minitalk.h
SRCS=server.c client.c
CC=cc
LIBDIR=libft
RM=/bin/rm -f
CFLAGS=-Wall -Wextra -Werror

all: $(NAME1) $(NAME2)

%: %.c $(HEADER)
	@make -C $(LIBDIR) all >/dev/null
	$(CC) $(CFLAGS) -o $@ $< -L $(LIBDIR) -lft -I $(LIBDIR)

clean:
	@make -C $(LIBDIR) clean >/dev/null

fclean: clean
	@make -C $(LIBDIR) fclean >/dev/null
	$(RM) $(NAME1) $(NAME2)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
