/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:22:00 by dania             #+#    #+#             */
/*   Updated: 2023/09/04 15:37:42 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

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
int		check_input(char *av);
void	get_args(char *av, t_st **st_a);
int		check_duplicate(t_st *st_a);

//	utils stack
t_st	*st_new(int value);
void	st_add(t_st **stack, t_st *new);
int		get_size(t_st *stack);
void	get_index(t_st *st_a, int size);

// push swap
void	push_swap(t_st **st_a, t_st **st_b, int size);

//	utils
void	exit_error(t_st **st_a, t_st **st_b);
int		pos_nb(int nb);
void	free_st(t_st **stack);

//	utils sort
int		get_max_index(t_st *stack);
int		check_sort(t_st *stack);
void	first_push(t_st **st_a, t_st **st_b, int size);
int		get_low_pos(t_st **stack);
void	final_rotate(t_st **st_a, int size);

//	big sort
void	get_target_position(t_st **st_a, t_st **st_b);
void	get_cost(t_st **st_a, t_st **st_b);
void	min_move(t_st **st_a, t_st **st_b);
void	get_position(t_st **stack);

//	move best
void	move(t_st **st_a, t_st **st_b, int cost_a, int cost_b);

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

#endif
