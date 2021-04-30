/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbie <abarbie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:26:46 by abarbie           #+#    #+#             */
/*   Updated: 2021/03/19 13:29:30 by abarbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** Allowed functions:
** ◦ write
** ◦ read
** ◦ malloc
** ◦ free
** ◦ exit
*/

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct		s_flags
{
	int				v;
	int				c;
	int				a;
	int				m;
	int				s;
	int				hl[10000];
	int				len;
}					t_flags;

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_ps
{
	t_stack			*a;
	t_stack			*b;
	t_flags			f;
}					t_ps;

/*
** [args_a.c]
*/

void				args(int ac, char **av, t_ps *ps);
void				args_ps(int ac, char **av, t_ps *ps);

/*
** [args_b.c]
*/

int					min_of(int a, int b);
int					is_int(char *str);
int					ft_atoi_of(char *s, int *overflow);
void				ft_sleep(int sec);

/*
** [errors.c]
*/

void				error(void);

/*
** [operations_p.c]
*/

void				pa(t_ps *ps, int wr);
void				pb(t_ps *ps, int wr);

/*
** [operations_r.c]
*/

void				ra(t_ps *ps, int wr);
void				rb(t_ps *ps, int wr);
void				rr(t_ps *ps, int wr);

/*
** [operations_rr.c]
*/

void				rra(t_ps *ps, int wr);
void				rrb(t_ps *ps, int wr);
void				rrr(t_ps *ps, int wr);

/*
** [operations_s.c]
*/

void				sa(t_ps *ps, int wr);
void				sb(t_ps *ps, int wr);
void				ss(t_ps *ps, int wr);

/*
** [push_swap_b.c]
*/

int					rots_to_top(t_stack *s, int val, int *dir);
int					get_opt_elem(t_ps *ps);
void				move_elem(t_ps *ps, int val);

/*
** [stack_a.c]
*/

t_ps				t_ps_init(t_ps *ps);
int					size(t_stack *stack);
int					empty(t_stack *stack);
void				push(t_stack **stack, int value);
int					pop(t_stack **stack);

/*
** [stack_b.c]
*/

void				clear_stack(t_stack *stack);
void				clear_stacks(t_ps *ps);
int					ascending_sorting(t_stack *stack);
int					has_duplicates(t_stack *stack);
t_stack				*get_last(t_stack *stack);

/*
** [stack_c.c]
*/

int					top(t_stack *stack);
int					get_next(t_stack *stack, int val);
int					mid(t_stack *stack);

/*
** [stack_d.c]
*/

int					max(t_stack *stack);
int					min(t_stack *stack);
int					gmax(t_ps *ps);
int					gmin(t_ps *ps);

/*
** [stack_visual.c]
*/

int					highlight(t_ps *ps, int val);
void				print_stack(t_ps *ps, t_stack *s);
void				print_stacks(t_ps *ps);
void				pr_line(t_ps *ps, t_stack *s);
void				print_sort(t_ps *ps);

#endif
