/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:04:17 by jsaarine          #+#    #+#             */
/*   Updated: 2022/11/29 16:56:20 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "stdio.h"

t_hit_record	precompute(t_intersection intersection, t_ray *ray)
{
	t_hit_record	hit;
	t_intersection closest_t;
// 
	// printf(" ⏰ 1\n");

	closest_t = find_closest_intersection(&ray->xs);
	// printf(" ⏰ 2\n");
	hit.hit_dist = intersection.t;
	hit.object = intersection.object;
	hit.hit_loc = ray_position(*ray, hit.hit_dist);
	// printf(" ⏰ 3\n");
	hit.to_eye = tuple_neg(ray->dir);
	// printf(" ⏰ 4\n");
	hit.normal = normal_at(hit.object, hit.hit_loc);
	// printf(" ⏰ 5\n");
	if (vector_dot(hit.normal, hit.to_eye) < 0)
	{
		hit.inside = 1;
		hit.normal = tuple_neg(hit.normal);
		// printf(" ⏰ 6\n");
	}
	else
		hit.inside = 0;
	return (hit);
}
