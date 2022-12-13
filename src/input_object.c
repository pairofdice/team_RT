/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:26:33 by mmakinen          #+#    #+#             */
/*   Updated: 2022/12/13 13:35:44 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/input.h"

int	get_material(t_xml_node *node, t_material *mat)
{
	t_xml_attr	*attr;
	int			index;
	t_tuple		col;

	index = 0;
	if (node->attributes.size == 0)
		return (FALSE);
	while (index < node->attributes.size)
	{
		attr = &node->attributes.list[index];
		if (!ft_strcmp(attr->key, "pattern") && \
		!ft_strcmp(attr->value, "striped"))
			mat->pattern.pattern_id = STRIPED;
		else if (!ft_strcmp(attr->key, "pattern") && \
		!ft_strcmp(attr->value, "grid"))
			mat->pattern.pattern_id = GRID;
		else if (!ft_strcmp(attr->key, "perlin") && \
		!ft_strcmp(attr->value, "true"))
			mat->pattern.pattern_perlin = TRUE;
		index++;
	}
	get_tuple(&col, node->data);
	mat->color = color_new(col.a[0], col.a[1], col.a[2]);
	return (TRUE);
}

int	get_details(t_xml_node *node, t_object *obj)
{
	if (!ft_strcmp(node->tag, "loc"))
		get_tuple(&obj->loc, node->data);
	else if (!ft_strcmp(node->tag, "coi"))
		get_tuple(&obj->coi, node->data);
	else if (!ft_strcmp(node->tag, "up"))
		get_tuple(&obj->up, node->data);
	else if (!ft_strcmp(node->tag, "rot"))
		get_tuple(&obj->rot, node->data);
	else if (!ft_strcmp(node->tag, "color"))
		get_tuple(&obj->color, node->data);
	else if (!ft_strcmp(node->tag, "scale"))
		get_tuple(&obj->scale, node->data);
	else if (!ft_strcmp(node->tag, "size"))
		obj->size = get_double(node->data);
	else if (!ft_strcmp(node->tag, "brightness"))
		obj->brightness = get_double(node->data);
	if (!ft_strcmp(node->tag, "material"))
	{
		if (!get_material(node, &obj->material))
		{
			ft_putendl_fd("ERROR: Failed to get material info", 2);
			return (FALSE);
		}
	}
	return (TRUE);
}

int	get_obj_details(t_xml_node *node, t_object *obj)
{
	int			index;
	t_xml_node	*temp;

	index = 0;
	while (index < node->children.size)
	{
		temp = node->children.list[index];
		if (!get_details(temp, obj))
			return (FALSE);
		index++;
	}
	return (TRUE);
}

static inline void	populate_types(char (*types)[9])
{
	ft_strcpy(types[0], "sphere");
	ft_strcpy(types[1], "cylinder");
	ft_strcpy(types[2], "plane");
	ft_strcpy(types[3], "cone");
}

int	get_object(t_xml_node *node, t_object *obj)
{
	t_xml_attr	*atr;
	int			index[2];
	char		types[4][9];

	populate_types(types);
	while (index[0] < node->attributes.size)
	{
		atr = &node->attributes.list[index[0]];
		if (!ft_strcmp(atr->key, "type"))
		{
			index[1] = 0;
			while (index[1] < 4)
			{
				if (!ft_strcmp(atr->value, types[index[1]]))
					*obj = object_new(index[1]);
				index[1]++;
			}
		}
		if (!ft_strcmp(atr->key, "negative") && !ft_strcmp(atr->value, "true"))
			obj->negative = TRUE;
		index[0]++;
	}
	if (node->attributes.size == 0 || !get_obj_details(node, obj))
		return (FALSE);
	return (TRUE);
}
