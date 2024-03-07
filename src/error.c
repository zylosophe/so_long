/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:05:21 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/11 13:37:12 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "error.h"
#include "libtf.h"
#include "display.h"
#include "env.h"

static void	end(int no)
{
	display_destroyall();
	mem_freeall(g_env.mc);
	exit(no);
}

void	err(t_const_string msg)
{
	print_line(err_remember, 2, "Error");
	if (str_eq(msg, "errno"))
		print_line(err_remember, 2, strerror(errno));
	else
		print_line(err_remember, 2, msg);
	end(1);
}

void	err_perror(t_const_string s)
{
	print_line(err_remember, 2, "Error");
	print_str(err_remember, 2, s);
	print_str(err_remember, 2, ": ");
	print_line(err_remember, 2, strerror(errno));
	end(1);
}

void	err_perror_str(t_const_string s, t_const_string msg)
{
	print_line(err_remember, 2, "Error");
	print_str(err_remember, 2, s);
	print_str(err_remember, 2, ": ");
	print_line(err_remember, 2, msg);
	end(1);
}

void	finish(void)
{
	end(0);
}
