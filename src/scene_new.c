/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:57:35 by jsaarine          #+#    #+#             */
/*   Updated: 2022/11/18 15:07:44 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	default_scene(t_scene *scene)
{
	t_light		light;
	t_object	object;

	if (!scene_new(scene))
	{
		printf("No new scene 😨\n");
		return (0);
	}
	light = point_light_new(point_new(-10, 10, -10), color_new(1, 1, 1));
	vec_push(&scene->lights, &light);
	object = object_new(SPHERE);
	printf("PALLO 1 id: %zu\n", object.id);
	object.material.color = color_new(0.8, 1.0, 0.6);
	object.material.diffuse = 0.7;
	object.material.specular = 0.2;
	object.debug = "PALLO 1";
	vec_push(&scene->objects, &object);
	object = object_new(SPHERE);
	printf("PALLO 2 id: %zu\n", object.id);
	object.transform = matrix_scale(0.5, 0.5, 0.5);
	object.debug = "PALLO 2";
	vec_push(&scene->objects, &object);
	return (1);
}

int	scene_new(t_scene *scene)
{
	int ok;

	ok = 0;
	ok = vec_new(&scene->lights, 2, sizeof(t_light));
	if (!ok)
		return (0);
	ok = vec_new(&scene->objects, 2, sizeof(t_object));
	if (!ok)
		return (0);
	return (1);
}