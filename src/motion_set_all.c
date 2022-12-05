/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_set_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:43:31 by jjuntune          #+#    #+#             */
/*   Updated: 2022/12/05 16:10:04 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

int	motion_set_all(t_main *main)
{
	int	i;
	int	motions_done;

	i = 0;
	motions_done = 0;
	while (i < main->obj_count)
	{
		if (main->obj[i].motion.on_off == TRUE
			&& main->obj[i].motion.speed_iteration < main->obj[i].motion.speed)
		{
			motion_move(&main->obj[i].transform, &main->obj[i].motion);
			motions_done++;
		}
		i++;
	}
	if (main->cam.motion.on_off == TRUE)
	{
		motion_move(&main->cam.transform, &main->cam.motion);
		motions_done++;
	}
	return (motions_done);
}
