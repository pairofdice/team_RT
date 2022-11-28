/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_record.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:44:03 by jsaarine          #+#    #+#             */
/*   Updated: 2022/11/27 18:39:05 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "stdio.h"

void	intersection_record(t_vec *vec, double intersect, t_object *s)
{
	t_intersection	xs;
	
	xs = intersection_new(intersect, s);
	vec_push(vec, &xs);

}

void	intersection_record_test(t_ray *ray, double t1, double t2, t_object *s)
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
