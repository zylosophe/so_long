/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:05:54 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/20 15:16:29 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_utils.h"

t_input_hidden	*get_input_hidden(void)
{
	static t_input_hidden	v = {
		enter: false,
		input_i: 0,
		to_unpress: {false, false, false, false},
		inputbuf: {false, false, false, false},
	};

	return (&v);
}
