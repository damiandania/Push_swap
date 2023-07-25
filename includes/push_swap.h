/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:22:00 by dania             #+#    #+#             */
/*   Updated: 2023/07/25 19:54:39 by dania            ###   ########.fr       */
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

//		check input
int		check_input(char **av);

//		init stack
t_st	*init_stack(int ac, char **av);

//		utils
void	exit_error(t_st **st_a, t_st **st_b, char *msg);

//		stack utils
t_st	*st_new(int value);
void	st_add_back(t_st **stack, t_st *new);
int		get_size(t_st *stack);
void	set_index(t_st *st_a, int size);

#endif
