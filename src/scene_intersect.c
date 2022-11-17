/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:57:35 by jsaarine          #+#    #+#             */
/*   Updated: 2022/11/17 21:35:10 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	get_shape_intersections(t_ray *ray, t_object *shape)
{
	int	ret;

	ret = 0;
	if (shape->type == SPHERE)
		ret = intersect_sphere(ray, shape);
	else if (shape->type == CYLINDER)
		ret = intersect_cylinder(ray, shape);
	else if (shape->type == PLANE)
		ret = intersect_plane(ray, shape);
	else if (shape->type == CONE)
		ret = intersect_cone(ray, shape);
	
	return (ret);
}

void	push_intersections(t_intersections *intersections, t_ray *ray)
{
	t_intersection	is;
	size_t			i;

		printf("IN push_intersections\n");
	i = intersections->vec.len;
	while (i < ray->xs.vec.len)
	{
		printf("IN push_intersections - WHILE\n");
		is = *(t_intersection *) vec_get(&ray->xs.vec, i);
		vec_push(&(intersections->vec), &is);
		i++;
	}
}



void	scene_intersect(t_scene *scene, t_ray *ray, t_intersections *intersections)
{
 
	t_object		object;
	size_t				i;
	printf("IN scene_intersect 🤢😷🤡\n");
	
	i = 0;
	while (i < scene->objects.len)
	{
		object = *(t_object *) vec_get(&scene->objects, i);
		printf("IN scene_intersect --------- %zu\n", object.id);
		if (get_shape_intersections(ray, &object))
		{
				printf("IN scene_intersect\n");
			push_intersections(intersections, ray);
				printf("AFTER push_intersections\n");
		}
		printf("IN scene_intersect +++++++++\n");
		i++;
	}
	printf("IN scene_intersect 🤢😷🤡 --------- \n");
	if (intersections->vec.len > 0)
	{
		t_intersection is = *(t_intersection *) vec_get(&intersections->vec, 0);
		printf("IN scene_intersect 🤢😷🤡 --------- %zu %zu\n", is.object->id,(size_t)&vec_get);
	}


	// return (intersections);
}