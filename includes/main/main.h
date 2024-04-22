/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:39:54 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/20 13:29:14 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

typedef struct s_loopfunctions
{
	void	(*loop)(void);
	void	(*draw)(void);
}			t_loopfunctions;

int	main(int argc, t_const_string *argv);

#endif
