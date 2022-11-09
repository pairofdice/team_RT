/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:35:17 by jjuntune          #+#    #+#             */
/*   Updated: 2022/11/09 17:35:36 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

t_object_mt	object_new(int shape_type)
{
	static size_t	id;
	t_object_mt		new_object;

	new_object.transform = matrix_new_identity(4);
	new_object.id = id;
	id++;
	new_object.loc = (t_point){.s_xyzw = {0, 0, 0, 0}};
	new_object.size = 1.0;
	new_object.type = shape_type;
	return (new_object);
}
