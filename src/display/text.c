/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:57:28 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/18 20:22:33 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "display_utils.h"

void	display_text(t_point *p, t_assetsmap_id asset)
{
	display_draw(*p, asset);
	p->x += g_allassets[asset].width;
}

void	display_uint(t_point *p, unsigned int n)
{
	const t_memclass	mc = mem_subclass(error_err, g_env.mc);
	t_string			str;

	str = str_uinttostr(error_err, mc, n);
	while (*str)
	{
		display_text(p, TEXT_LITTLE_0 + *str - '0');
		str++;
	}
	mem_freeall(mc);
}
