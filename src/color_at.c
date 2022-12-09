/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:49:39 by jsaarine          #+#    #+#             */
/*   Updated: 2022/12/09 18:10:17 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	intersection_compare(const void *i_a, const void *i_b)
{
	t_intersection left = *(const t_intersection *) i_a;
	t_intersection right = *(const t_intersection *) i_b;

	if (nearly_equal(left.t, right.t))
		return (0);
	return ((left.t > right.t) - (left.t < right.t));	
}

t_color	color_at(t_scene *scene, t_ray *ray)
{
	// t_intersection intersection;
	
	scene_intersect(scene, ray); 
	if (ray->xs.vec.len == 0)
	{	
		// printf("🤪 Returned out of color_at\n");
		return (color_new(0, 0, 0));
	}
	
	// intersection = find_closest_intersection(&ray->xs);
	//intersection = find_closest_intersection(&ray->xs);
 	// if (ray->xs.vec.len > 0)
	// 	intersection = *(t_intersection *) vec_get(&ray->xs.vec, 0);
	/*
	else
		intersection = intersection_new(99999, NULL); */
	/* t_hit_record hit =  */precompute(/* intersection, */ ray);
	if (ray->hit.hit_dist > 999999)
		return (color_new(0, 0, 0));
	// printf("📕📗📘\n");
	t_color color = shade_hit(scene, ray);
		
	return (color);
}
