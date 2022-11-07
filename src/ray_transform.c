/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:44:03 by jsaarine          #+#    #+#             */
/*   Updated: 2022/11/07 15:04:24 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "tuple.h"

t_ray_m	ray_transform(t_ray_m *source, t_matrix *transform)
{
	t_point		p;
	t_vector	v;
	t_ray_m		result;

	p = matrix_tuple_multiply(transform, &source->orig);
	v = matrix_tuple_multiply(transform, &source->dir);
	result = ray_new_no_malloc(p, v);
	return (result);
}
