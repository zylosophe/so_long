/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:05:21 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/29 18:04:54 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
	print_str(err_remember, 2, "error: ");
	print_line(err_remember, 2, msg);
	end(1);
}

void	finish(void)
{
	end(0);
}
