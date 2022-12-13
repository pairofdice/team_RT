/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_light_and_camera.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:26:33 by mmakinen          #+#    #+#             */
/*   Updated: 2022/12/13 13:36:32 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/input.h"

int	get_light(t_xml_node *node, t_light *light)
{
	t_xml_node	*temp;
	int			index;

	index = 0;
	while (index < node->children.size)
	{
		temp = node->children.list[index];
		if (!ft_strcmp(temp->tag, "pos"))
			get_tuple(&light->location, temp->data);
		else if (!ft_strcmp(temp->tag, "brightness") || \
		!ft_strcmp(temp->tag, "color"))
			get_tuple(&light->intensity, temp->data);
		index++;
	}
	return (TRUE);
}

int	get_camera(t_xml_node *node, t_cam *cam)
{
	t_xml_node	*temp;
	int			index;

	index = 0;
	while (index < node->children.size)
	{
		temp = node->children.list[index];
		if (!ft_strcmp(temp->tag, "pos"))
			get_tuple(&cam->pos, temp->data);
		else if (!ft_strcmp(temp->tag, "coi"))
			get_tuple(&cam->coi, temp->data);
		else if (!ft_strcmp(temp->tag, "v_up"))
			get_tuple(&cam->v_up, temp->data);
		index++;
	}
	return (TRUE);
}
