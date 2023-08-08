/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:22:00 by dania             #+#    #+#             */
/*   Updated: 2023/08/08 01:02:56 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# define ERR_INV "invalid values"
# define ERR_LIM "value out of limits"

typedef struct s_st
{
	int				value;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_st		*next;
}	t_st;

//	check input
int		check_input(char **av);

//	init stack
t_st	*init_stack(int ac, char **av);

// push swap
void	push_swap(t_st **st_a, t_st **st_b, int size);

//	utils
void	exit_error(t_st **st_a, t_st **st_b, char *msg);
int		pos_nb(int nb);
void	free_st(t_st **stack);

//	stack utils
t_st	*st_new(int value);
void	st_add_back(t_st **stack, t_st *new);
int		get_size(t_st *stack);
void	set_index(t_st *st_a, int size);

//	utils sort
int		get_max_index(t_st *stack);
int 	check_sort(t_st *stack);
void 	first_push(t_st **st_a, t_st **st_b, int size);

//	utils bigsort
void	get_target_position(t_st **st_a, t_st **st_b);
void	get_cost(t_st **st_a, t_st **st_b);
void	min_move(t_st **st_a, t_st **st_b);
void	get_position(t_st **stack);

//	move
void	move(t_st **st_a, t_st **st_b, int index);

//	move swap
void	move_sa(t_st **st_a);
void	move_sb(t_st **st_b);
void	move_ss(t_st **st_a, t_st **st_b);

//	move push
void	move_pa(t_st **st_a, t_st **st_b);
void	move_pb(t_st **st_a, t_st **st_b);

//	move rotate
void	move_ra(t_st **st_a);
void	move_rb(t_st **st_b);
void	move_rr(t_st **st_a, t_st **st_b);

//	move rotate reverse
void	move_rra(t_st **st_a);
void	move_rrb(t_st **st_b);
void	move_rrr(t_st **st_a, t_st **st_b);

// void 	ft_print(t_st *stack); //BORRAR ////////

#endif
