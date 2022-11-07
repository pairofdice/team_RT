/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_record.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:44:03 by jsaarine          #+#    #+#             */
/*   Updated: 2022/11/07 15:06:04 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	intersection_record(t_ray_m *ray, double t1, double t2, t_object_mt *s)
{
	t_intersection	xs;

	if (t1 < t2)
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
	}
}
