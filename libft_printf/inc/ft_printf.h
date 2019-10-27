/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 00:39:12 by sle-lieg          #+#    #+#             */
/*   Updated: 2018/06/18 09:30:39 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define BUF_SIZE 32768
# define FLAGS "#0- +"
# define MODIF "hljz"
# define TYPE "sSpdDioOuUxXcCb"

# define EOC	"\033[0;m"
# define RED 	"\033[1;31m"
# define GREEN  "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE   "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN   "\033[1;36m"
# define GREY   "\033[1;37m"

typedef struct	s_env
{
	va_list	ap;
	void	(*type_select[15])(struct s_env*);
	char	buff[BUF_SIZE];
	char	*pos;
	char	*last_valid_pos;
	int		flags[5];
	int		modif[4];
	int		width;
	int		accu;
	int		ret;
	int		width_bool;
	int		accu_bool;
	int		error;
}				t_env;

enum		{DIEZ, ZERO, MIN, SPACE, PLUS};
enum		{H, L, J, Z};
enum		{FALSE, TRUE};

/*
** +++++ FT_PRINTF.C +++++
*/
int				ft_printf(const char *format, ...);
void			ft_init(t_env *e);
void			ft_print_buff(t_env *e);
void			ft_read(t_env *e, const char *format);
void			ft_reset_options(t_env *e);

/*
** +++++ PARSING.C +++++
*/
void			ft_parse(t_env *e, const char *format, int *i);
int				ft_get_opt(t_env *e, const char *format, int *i);
void			ft_fill_error(t_env *e, const char *format, int *i);
int				ft_get_flags(t_env *e, char flag);
int				ft_get_modifier(t_env *e, char flag);
int				ft_get_opt(t_env *e, const char *format, int *i);

/*
** +++++ PARSING_TOOLS.C +++++
*/
void			ft_get_color(t_env *e, const char *format, int *i);
void			ft_get_width(t_env *e, const char *format, int *i);
void			ft_get_accuracy(t_env *e, const char *format, int *i);

/*
** +++++ UNICODE_TOOLS.C +++++
*/
int				ft_four_octet(t_env *e, uint32_t arg);
int				ft_three_octet(t_env *e, uint32_t arg);
int				ft_two_octet(t_env *e, uint32_t arg);
void			ft_get_color(t_env *e, const char *format, int *i);

/*
** +++++ TYPE_big_c.C +++++
*/
void			ft_type_big_c(t_env *e);
void			ft_post_indent_big_c(t_env *e, uint32_t arg);
void			ft_pre_indent_big_c(t_env *e, uint32_t arg);

/*
** +++++ TYPE_s.C +++++
*/
void			ft_type_s(t_env *e);
void			ft_post_indent_s(t_env *e, char *arg_str, int len);
void			ft_pre_indent_s(t_env *e, char *arg_str, int len);

/*
** +++++ TYPE_big_s.C +++++
*/
void			ft_type_big_s(t_env *e);
void			ft_post_indent_big_s(t_env *e, uint32_t *arg);
void			ft_pre_indent_big_s(t_env *e, uint32_t *arg);
void			ft_get_accu(t_env *e, uint32_t *arg);
void			ft_fill_wstring(t_env *e, uint32_t *arg);

/*
** +++++ TYPE_p.C +++++
*/
void			ft_type_p(t_env *e);
void			ft_post_indent_p(t_env *e, char *arg_addr);
void			ft_pre_indent_p(t_env *e, char *arg_addr);

/*
** +++++ TYPE_d_i.C +++++
*/
void			ft_type_d(t_env *e);
char			*ft_get_arg_d(t_env *e);
void			ft_post_indent_d(t_env *e, char *tmp);
void			ft_pre_indent_d(t_env *e, char *tmp);
void			ft_pre_indent_dnext(t_env *e, char *tmp);

/*
** +++++ TYPE_o_big_o.C +++++
*/
void			ft_type_o(t_env *e);
void			ft_pre_indent_o(t_env *e, char *tmp);
void			ft_post_indent_o(t_env *e, char *tmp);
char			*ft_get_arg_o(t_env *e);
void			ft_type_big_o(t_env *e);

/*
** +++++ TYPE_u.C +++++
*/
void			ft_type_u(t_env *e);
char			*ft_get_arg_u(t_env *e);
void			ft_type_big_u(t_env *e);

/*
** +++++ TYPE_x.C +++++
*/
void			ft_type_x(t_env *e);
void			ft_post_indent_x(t_env *e, char *tmp);
void			ft_pre_indent_x(t_env *e, char *arg_addr);
void			ft_pre_indent_xnext(t_env *e, char *tmp);
char			*ft_get_arg_x(t_env *e);

/*
** +++++ TYPE_big_x.C +++++
*/
void			ft_type_big_x(t_env *e);

/*
** +++++ TYPE_c_big_d.C +++++
*/
void			ft_type_c(t_env *e);
void			ft_type_big_d(t_env *e);

/*
** +++++ TYPE_b.C +++++
*/
void			ft_type_b(t_env *e);
void			ft_post_indent_b(t_env *e, char *tmp);
void			ft_pre_indent_b(t_env *e, char *tmp);
void			ft_pre_indent_bnext(t_env *e, char *tmp);
char			*ft_get_arg_b(t_env *e);

#endif
