/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:02:29 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/20 13:48:31 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "gameover_utils.h"

static t_gameover_env	*get_gameover_env(void)
{
	static t_gameover_env	v;

	return (&v);
}

static void	gameover_byfirskattack_loop(void)
{
}

static void	gameover_byfirskattack_draw(void)
{
	t_gameover_env *const	env = get_gameover_env();
	void *const				allsprites[][5] = {
	{&env->spr_snas, &env->spr_attack, NULL, NULL, NULL},
	{&env->spr_snas, &env->spr_explosion1, NULL, NULL,
		NULL},
	{&env->spr_explosion2, NULL, (void *)1, (void *)1, NULL},
	{NULL, NULL, (void *)1, (void *)1, &ask_retry}};
	void *const				*sprites = allsprites[env->state];
	t_point					p_gameover;
	t_point					p_youded;

	p_gameover = point_init(145, 120);
	p_youded = point_init(145, 210);
	if (sprites[0])
		if (!sprite_draw(env->snaspos, sprites[0]))
			env->state++;
	if (sprites[1])
		if (!sprite_draw(env->snaspos, sprites[1]))
			env->state++;
	if (sprites[2])
		display_text(&p_gameover, TEXT_BIG_GAMEOVER);
	if (sprites[3])
		display_text(&p_youded, TEXT_REGULAR_YOUDED);
	if (sprites[4])
		((void (*)(bool))sprites[4])(true);
}

void	gameover_byfirskattack(t_character *character)
{
	t_gameover_env *const	env = get_gameover_env();
	const t_point			snas_p = room_find(snas_init);
	const t_spritesmap_id	snas_sprite = character->sprites->still;

	env->snaspos = point_subpoint(
			point_subpoint(
				point_multiply(snas_p, 50),
				g_env.camera.pos),
			point_multiply(
				point_fromdirection(character->direction),
				character->walk_remaining_steps * 50 / character->walk_steps_nb
				));
	env->spr_snas = sprite_init(snas_sprite);
	env->spr_snas.index = character->direction;
	env->spr_attack = sprite_init(SPR_KNIFEATTACK);
	env->spr_explosion1 = sprite_init(SPR_EXPLOSION_1);
	env->spr_explosion2 = sprite_init(SPR_EXPLOSION_2);
	env->state = 0;
	g_env.loopfunctions.loop = gameover_byfirskattack_loop;
	g_env.loopfunctions.draw = gameover_byfirskattack_draw;
}
