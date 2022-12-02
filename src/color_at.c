/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:49:39 by jsaarine          #+#    #+#             */
/*   Updated: 2022/12/02 16:37:40 by jsaarine         ###   ########.fr       */
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

t_color	color_at(t_scene *scene, t_ray *ray, int pixel)
{
	t_intersection intersection;
	
	scene_intersect(scene, ray); 
	if (ray->xs.vec.len == 0)
	{	
		// printf("🤪 Returned out of color_at\n");
			return (color_new(0, 0, 0));
	}
	
	//mergesort(ray->xs.vec.memory, ray->xs.vec.len, ray->xs.vec.elem_size, intersection_compare);
	intersection = find_closest_intersection(&ray->xs);
	//intersection = *(t_intersection *) vec_get(&ray->xs.vec, 0);
	t_hit_record hit = precompute(intersection, ray);
	t_color color = shade_hit(scene, &hit);
	if (pixel == 4)
	{
		// printf("__hit dst %lf color: ", hit.hit_dist);
		// tuple_print(color);
		// printf("__\n");
		// tuple_print(main->ray.xs.vec.len);
		
	}
	
	return (color);
}
