/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_record.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:44:03 by jsaarine          #+#    #+#             */
/*   Updated: 2022/11/09 17:50:52 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	intersection_record(t_ray_m *ray, double intersect, t_object_mt *s)
{
	t_intersection	xs;
	
	xs = intersection_new(intersect, s);
	vec_push(&ray->xs.vec, &xs);

/* 	if (t1 < t2)
	{
		xs = intersection_new(t1, s);
		vec_push(&ray->xs.vec, &xs);
		xs = intersection_new(t2, s);
		vec_push(&ray->xs.vec, &xs);
	}
	else
	{
		xs = intersection_new(t2, s);
		vec_push(&ray->xs.vec, &xs);
		xs = intersection_new(t1, s);
		vec_push(&ray->xs.vec, &xs);
	} */
}
