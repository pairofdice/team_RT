/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_coi_transform.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:28:28 by jjuntune          #+#    #+#             */
/*   Updated: 2022/11/21 14:10:06 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

t_matrix	coi_transform(t_cam *cam, t_matrix transform)
{
	t_tuple		transform_coi;	
	t_matrix	result;
	t_matrix	rotation;
	double		rot;

	result = matrix_inverse(&transform);
	transform_coi = matrix_tuple_multiply(&result, &cam->coi);
	transform_coi = vector_new(transform_coi.s_xyzw.x,
								transform_coi.s_xyzw.y,
								transform_coi.s_xyzw.z);
	transform_coi = tuple_unit(transform_coi);
	result = transform;
	transform_coi = tuple_unit(transform_coi);
	rot = atan2(transform_coi.s_xyzw.y, transform_coi.s_xyzw.z);
	rotation = matrix_rotate_x(rot);
	result = matrix_multiply(&result, &rotation);
	
	rot = atan2(transform_coi.s_xyzw.x, transform_coi.s_xyzw.z);
	rotation = matrix_rotate_y(rot);
	result = matrix_multiply(&result, &rotation);
	
	rot = atan2(transform_coi.s_xyzw.y, transform_coi.s_xyzw.x);
	rotation = matrix_rotate_z(rot);
	result = matrix_multiply(&result, &rotation);
	return(result);
}
