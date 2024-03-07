/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:04:31 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/11 13:23:02 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libtf.h"

void	err(t_const_string msg);
void	err_perror(t_const_string s);
void	err_perror_str(t_const_string s, t_const_string msg);
void	finish(void);

#endif
