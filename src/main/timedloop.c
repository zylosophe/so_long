/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timedloop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:54:49 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/23 01:12:36 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static long	get_nanos(void)
{
	FILETIME	ft;

	GetSystemTimePreciseAsFileTime(&ft);
	return (((unsigned long long)ft.dwHighDateTime << 32)| ft.dwLowDateTime);
}

void	timedloop(void (*f)(void))
{
	static long	last_time = 0;
	const long	new_time = get_nanos();
	static bool	checked = false;

	if (new_time - last_time >= 1000000000L / FPS)
	{
		if (checked)
			last_time += 1000000000L / FPS;
		else
			last_time = new_time;
		checked = false;
		f();
	}
	else
		checked = true;
}
