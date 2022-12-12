/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:49:39 by jsaarine          #+#    #+#             */
/*   Updated: 2022/12/12 19:43:17 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// int	intersection_compare(const void *i_a, const void *i_b)
// {
// 	t_intersection left = *(const t_intersection *) i_a;
// 	t_intersection right = *(const t_intersection *) i_b;

// 	if (nearly_equal(left.t, right.t))
// 		return (0);
// 	return ((left.t > right.t) - (left.t < right.t));
// }

t_color	color_at(t_scene *scene, t_ray *ray)
{
	t_color	color;

	scene_intersect(scene, ray);
	if (ray->xs.vec.len == 0)
		return (color_new(0, 0, 0));
	precompute(ray);
	if (ray->hit.hit_dist > MAX_DISTANCE)
		return (color_new(0, 0, 0));
	color = shade_hit(scene, ray);
	return (color);
}
