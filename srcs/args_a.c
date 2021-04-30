/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbie <abarbie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:36:32 by abarbie           #+#    #+#             */
/*   Updated: 2021/03/16 01:20:19 by abarbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_arg(char *arg, t_ps *ps)
{
	int overflow;

	if (!is_int(arg))
		error();
	overflow = 0;
	push(&ps->a, ft_atoi_of(arg, &overflow));
	if (overflow)
		error();
}

static void	split_args(char *str, t_ps *ps)
{
	char	**split;
	int		i;

	if (!(split = ft_split(str, ' ')))
		error();
	i = 0;
	while (split[i])
		i++;
	while (--i >= 0)
		add_arg(split[i], ps);
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void		args(int ac, char **av, t_ps *ps)
{
	if (ac < 1)
		exit(EXIT_SUCCESS);
	t_ps_init(ps);
	while (--ac >= 0 && av[ac])
	{
		if (ft_strchr(av[ac], ' '))
		{
			split_args(av[ac], ps);
			continue ;
		}
		add_arg(av[ac], ps);
	}
	if (has_duplicates(ps->a))
		error();
}

static int	set_flag(char *arg, t_ps *ps)
{
	if (!ft_strcmp(arg, "-v"))
		ps->f.v = 1;
	else if (!ft_strcmp(arg, "-c"))
		ps->f.c = 1;
	else if (!ft_strcmp(arg, "-a"))
		ps->f.a = 1;
	else if (!ft_strncmp(arg, "-m", 2))
		ps->f.m = ft_atoi(&arg[2]);
	else if (!ft_strcmp(arg, "-s"))
		ps->f.s = 1;
	else
		return (0);
	return (1);
}

void		args_ps(int ac, char **av, t_ps *ps)
{
	if (ac < 1)
		exit(EXIT_SUCCESS);
	ft_bzero(&ps->f, sizeof(t_flags));
	while (*av && set_flag(*av, ps))
	{
		av++;
		ac--;
	}
	args(ac, av, ps);
}
