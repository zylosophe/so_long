/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:57:28 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/19 11:55:23 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "display_utils.h"

void	display_text(t_point *p, t_assetsmap_id asset)
{
	display_draw(*p, asset);
	p->x += g_allassets[asset].width;
}

void	display_uint(t_point *p, unsigned int n, bool little)
{
	const t_memclass	mc = mem_subclass(error_err, g_env.mc);
	t_assetsmap_id		zero;
	t_string			str;

	zero = TEXT_REGULAR_0;
	if (little)
		zero = TEXT_LITTLE_0;
	str = str_uinttostr(error_err, mc, n);
	while (*str)
	{
		display_text(p, zero + *str - '0');
		str++;
	}
	mem_freeall(mc);
}
