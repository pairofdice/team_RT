/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:04:17 by jsaarine          #+#    #+#             */
/*   Updated: 2022/11/17 20:37:26 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "stdio.h"

t_hit_record	precompute(t_intersection intersection, t_ray *ray)
{
	t_hit_record	hit;

	printf("...1\n");
	hit.hit_dist = intersection.t;
	printf("...oid %zu\n", intersection.object->id);
	hit.object = intersection.object;
	hit.hit_loc = ray_position(*ray, hit.hit_dist);
	printf("...2\n");
	hit.to_eye = tuple_neg(ray->dir);
	printf("...3\n");
	printf("...obj id %zu\n", hit.object->id);
	hit.normal = normal_at(hit.object, hit.hit_loc);
	printf("...4\n");
	if (vector_dot(hit.normal, hit.to_eye) < 0)
	{
		printf("...5\n");
		hit.inside = 1;
		hit.normal = tuple_neg(hit.normal);
	}
	else
		hit.inside = 0;
	printf("...6\n");
	return (hit);
}