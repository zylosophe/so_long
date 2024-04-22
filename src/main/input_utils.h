/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:05:54 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/20 15:16:11 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_UTILS_H
# define INPUT_UTILS_H

# include "includes.h"

typedef struct s_input_hidden
{
	bool	enter;
	int		input_i;
	bool	to_unpress[4];
	bool	inputbuf[4];
}	t_input_hidden;

t_input_hidden	*get_input_hidden(void);

#endif
