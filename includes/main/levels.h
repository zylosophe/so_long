/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:45:16 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/19 14:12:07 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVELS_H
# define LEVELS_H

void	init_level(void);
void	ask_retry(bool current);
void	init_levels(int count, const t_const_string *srcs);
void	win(void);

#endif
