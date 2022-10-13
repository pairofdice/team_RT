/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:55:00 by jjuntune          #+#    #+#             */
/*   Updated: 2022/10/12 14:12:25 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

double	dot_prdct(t_vec3 a, t_vec3 b)
{
	t_vec3	new;
	double		ret;

	new.x = a.x * b.x;
	new.y = a.y * b.y;
	new.z = a.z * b.z;
	ret = (new.x + new.y + new.z);
	return (ret);
}

t_vec3	add_vectors(t_vec3 a, t_vec3 b)
{
	t_vec3	new;

	new.x = a.x + b.x;
	new.y = a.y + b.y;
	new.z = a.z + b.z;
	return (new);
}

t_vec3	sub_vectors(t_vec3 a, t_vec3 b)
{
	t_vec3	new;

	new.x = a.x - b.x;
	new.y = a.y - b.y;
	new.z = a.z - b.z;
	return (new);
}

t_vec3	multiply_vectors(t_vec3 a, t_vec3 b)
{
	t_vec3	new;

	new.x = a.x * b.x;
	new.y = a.y * b.y;
	new.z = a.z * b.z;
	return (new);
}

t_vec3	div_vectors(t_vec3 a, t_vec3 b)
{
	t_vec3	new;

	if (a.x == 0.0 && b.x == 0.0)
		new.x = 0;
	else
		new.x = a.x / b.x;
	if (a.y == 0.0 && b.y == 0.0)
		new.y = 0;
	else
		new.y = a.y / b.y;
	if (a.z == 0.0 && b.z == 0.0)
		new.z = 0;
	else
		new.z = a.z / b.z;
	return (new);
}
