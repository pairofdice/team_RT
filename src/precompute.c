/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:04:17 by jsaarine          #+#    #+#             */
/*   Updated: 2022/12/09 15:40:33 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "stdio.h"
#include "rt.h"

void/* t_hit_record */	precompute(/* t_intersection intersection, */ t_ray *ray)
{
	t_hit_record	hit;
	t_intersection closest_t;
// 
	closest_t = find_closest_intersection(&ray->xs);
	// SEGFAULT FIX
	if (closest_t.t > 999999)
		return ;
	hit.hit_dist = closest_t.t;
	hit.object = closest_t.object;
	hit.hit_loc = ray_position(*ray, hit.hit_dist);
	hit.to_eye = tuple_neg(ray->dir);
	hit.normal = normal_at(hit.object, hit.hit_loc);
	 //hit.hit_loc = tuple_add(hit.hit_loc, tuple_scalar_mult(hit.normal,  2 * EPSILON));
	 //comps.over_point ← comps.point + comps.normalv * EPSILON
	if (vector_dot(hit.normal, hit.to_eye) < 0)
	{
		hit.inside = 1;
		hit.normal = tuple_neg(hit.normal);
	}
	else
		hit.inside = 0;
	hit.over_point = tuple_add(hit.hit_loc, tuple_scalar_mult(hit.normal, EPSILON));
	hit.reflect_v = vector_reflect(ray->dir, hit.normal);
	ray->hit = hit;
	// return (hit);
}
