/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:32:36 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/20 12:48:15 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

const t_const_string	g_levels[LEVEL_COUNT] = {
	"rooms/01.ber",
	"rooms/02.ber",
	"rooms/03.ber",
	"rooms/04.ber",
	"rooms/05.ber",
	"rooms/06.ber",
	"rooms/07.ber",
	"rooms/08.ber",
	"rooms/09.ber",
	"rooms/10.ber",
};

t_env					g_env;
