/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_prepare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:26:33 by mmakinen          #+#    #+#             */
/*   Updated: 2022/12/13 13:35:59 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/input.h"

int	prepare_object(t_xml_node *node, t_object *obj)
{
	t_matrix	rotate;

	if (!get_object(node, obj))
		return (FALSE);
	obj->transform = matrix_translate_2(obj->loc);
	rotate = matrix_rotate_x(obj->rot.a[0]);
	obj->transform = matrix_multiply(&obj->transform, &rotate);
	rotate = matrix_rotate_y(obj->rot.a[1]);
	obj->transform = matrix_multiply(&obj->transform, &rotate);
	rotate = matrix_rotate_z(obj->rot.a[2]);
	obj->transform = matrix_multiply(&obj->transform, &rotate);
	rotate = matrix_scale(obj->scale.a[0], obj->scale.a[1], obj->scale.a[2]);
	obj->transform = matrix_multiply(&obj->transform, &rotate);
	return (TRUE);
}

int	prepare_camera(t_xml_node *node, t_cam *cam)
{
	cam->coi = point_new(0.0, 0.0, 0.0);
	get_camera(node, cam);
	cam->coi_transform = matrix_translate_2(cam->coi);
	cam->motion = motion_new(FALSE, 5.0, tuple_unit(vector_new(1, 0, 0)));
	cam->coi_motion = motion_new(FALSE, 5.0, tuple_unit(vector_new(1, 0, 0)));
	initialize_camera(cam, matrix_translate_2(cam->pos));
	return (TRUE);
}

int	prepare_light(t_xml_node *node, t_light *light)
{
	int			index;
	t_xml_attr	*attr;

	index = 0;
	light->location.a[3] = 1.0;
	get_light(node, light);
	while (index < node->attributes.size)
	{
		attr = &node->attributes.list[index];
		if (!ft_strcmp(attr->key, "type"))
		{
			if (!ft_strcmp(attr->value, "point"))
				light->type = POINT;
			else if (!ft_strcmp(attr->value, "sun"))
				light->type = SUN;
		}
		index++;
	}
	return (TRUE);
}
