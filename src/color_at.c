/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:49:39 by jsaarine          #+#    #+#             */
/*   Updated: 2022/11/26 18:35:42 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	intersection_compare(const void *d1, const void *d2)
{
	t_intersection left = *(const t_intersection *) d1;
	t_intersection right = *(const t_intersection *) d2;

	if (nearly_equal(left.t, right.t))
		return (0);
	return ((left.t > right.t) - (left.t < right.t));	
}

t_color	color_at(t_scene *scene, t_ray *ray)
{
	t_intersection intersection;
	// printf("IN COLOR_AT 8\n");
	/* t_object pallo1 = *(t_object *) vec_get(&scene->objects, 0); */
	/* t_object pallo2 = *(t_object *) vec_get(&scene->objects, 1); */
	// // printf("%zu %s\n", pallo1.id, pallo1.debug);
	// printf("%zu %s\n", pallo2.id, pallo2.debug);

	scene_intersect(scene, ray); // not getting good data out of here
	// printf("IN COLOR_AT POST INTERSECT ⌘\n");
	
	// t_intersection is1 = *(t_intersection *) vec_get(&intersections.vec, 0);
	// printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
	//t_intersection is2 = *(t_intersection *) vec_get(&intersections.vec, 1);
	//printf("%zu \n", is1.object->id);
	//printf("%zu \n", is2.object->id);
	if (ray->xs.vec.len == 0)
	{	
		// printf("🤪 Returned out of color_at\n");
			return (color_new(0, 0, 0));
	}
	// printf("XXXXX😇 IN COLOR_AT 2 8\n");
	mergesort(ray->xs.vec.memory, ray->xs.vec.len, ray->xs.vec.elem_size, intersection_compare);
	size_t i = 0;
	while (i < ray->xs.vec.len)
	{
		
		t_intersection is = *(t_intersection *) vec_get(&ray->xs.vec, i);
		if (is.t >= 0)
		{i++;
			break;
		}
		 printf("IN COLOR_AT ❓❓❓❓❓❓ %lf %zu %zu\n", is.t, is.object->id,(size_t)&vec_get);
		i++;
	}
	i--;
	// printf("IN COLOR_AT XXXXX\n");
	// printf("asdf\n");
	intersection = *(t_intersection *) vec_get(&ray->xs.vec, i);
	printf("COLOR_AT: t: %lf\n", intersection.t);
	// printf("object id in color_at %zu\n", intersection.object->id);
	t_hit_record hit = precompute(intersection, ray);
	// printf("ASDF\n");
	return (shade_hit(scene, &hit));
}
