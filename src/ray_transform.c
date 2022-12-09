/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:44:03 by jsaarine          #+#    #+#             */
/*   Updated: 2022/12/08 17:56:34 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray	ray_transform(t_ray *source, t_matrix *transform)
{
	t_point		origin;
	t_vector	direction;
	t_ray		result;

	origin = matrix_tuple_multiply(transform, &source->orig);
	direction = matrix_tuple_multiply(transform, &source->dir);
	result = ray_new_no_malloc(origin, direction);
	result.hit = source->hit;
	result.xs = source->xs;
	return (result);
}
