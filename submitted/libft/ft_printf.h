/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:31:59 by dlu               #+#    #+#             */
/*   Updated: 2023/05/16 15:47:15 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define DEC		"0123456789"
# define HEXU		"0123456789ABCDEF"
# define HEXL		"0123456789abcdef"
# define NULL_STR	"(null)"
# define NULL_PTR	"(nil)"

typedef unsigned long long	t_ull;
typedef long long			t_ll;
typedef struct s_format
{
	t_ll	nbr;
	char	type;
	char	padding;
	char	*num;
	int		hash;
	int		minus;
	int		plus;
	int		space;
	int		dot;
	int		zero;
	int		width;
	int		precision;
	int		base;
	int		signed_nbr;
}	t_format;

int		ft_printf(const char *s, ...);
int		ft_strlenf(char *s, t_format format);
int		print_padding(char c, int len);
int		print_str(char *s, int *count, t_format format);
void	print_char(char c, int *count, t_format format);
void	print_ptr(void *p, int *count, t_format format);
void	print_arg(va_list *args, int *count, t_format format);
void	print_nbr(t_ll n, const char *base, int *count, t_format format);
void	parse_nbr(t_ll n, const char *base, t_format *format);
void	parse_format(char **s, va_list *args, t_format *format);
void	*ft_callocn(size_t n);

#endif
