/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:22:13 by jjuntune          #+#    #+#             */
/*   Updated: 2022/12/12 19:51:55 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

t_color	shade_hit(t_scene *scene, t_hit_record *hit)
{
	t_color	result;
	t_color	temp;
	t_light	light;
	size_t	i;

	i = 0;
	result = color_new(0, 0, 0);
	while (i < scene->lights.len)
	{
		light = *(t_light *)vec_get(&scene->lights, i);
		temp = lighting(hit->object->material, light, hit->hit_loc, hit->to_eye,
				hit->normal, 0);
		result = tuple_add(result, temp);
		i++;
	}
	return (result);
}
