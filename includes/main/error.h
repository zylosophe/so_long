/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:04:31 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/02 18:04:00 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	error_err(t_const_string msg);
void	error_perror(t_const_string s);
void	error_str(t_const_string s, t_const_string msg);
void	success(void);

#endif
