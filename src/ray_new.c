/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:44:03 by jsaarine          #+#    #+#             */
/*   Updated: 2022/12/12 14:05:54 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "tuple.h"

static int	new_intersections(t_vec *intersections)
{
	return (vec_new(intersections, 4, sizeof(t_intersection)));
}

t_ray	ray_new(t_point origin, t_vector dir)
{
	t_ray	result;

	result.orig = origin;
	result.dir = dir;
	result.remaining = 4;
	new_intersections(&result.xs.vec);
	return (result);
}

t_ray	ray_new_no_malloc(t_point origin, t_vector dir)
{
	t_ray	result;

	result.orig = origin;
	result.dir = dir;
	return (result);
}
