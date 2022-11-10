/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:08:01 by jsaarine          #+#    #+#             */
/*   Updated: 2022/11/09 21:23:20 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include "object.h"

// assumes that the point will always be on the surface of the sphere
t_vector	normal_at_sphere(t_object *obj, t_point point)
{
	t_point		obj_point;
	t_vector	obj_normal;
	t_vector	world_normal;
	t_matrix	inverse;

	inverse = matrix_inverse(&obj->transform);
	obj_point =	matrix_tuple_multiply(&inverse, &point);
	obj_normal = tuple_sub(obj_point,  point_new(0, 0, 0));
	matrix_transpose(&inverse);
	world_normal = matrix_tuple_multiply(&inverse, &obj_normal);
	world_normal.s_xyzw.w = 0;
	return (tuple_unit(world_normal));
}

/* t_vector	normal_at_cylinder(t_object *obj, t_point point)
{
	return ();
} */

t_vector	normal_at(t_object *obj, t_point point)
{
	if (obj->type == SPHERE)
		return (normal_at_sphere(obj,  point));
/* 	if (obj->type == CYLINDER)
		return (normal_at_cylinder(obj, point)); */
	if (obj->type == PLANE)
		return (vector_new(0, 1, 0));
	return (vector_new(1, 0, 0));
}