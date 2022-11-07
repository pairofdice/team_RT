/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:44:03 by jsaarine          #+#    #+#             */
/*   Updated: 2022/11/07 15:04:32 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_point	ray_position(t_ray_m ray, double t)
{
	return (tuple_add(ray.orig, tuple_scalar_mult(tuple_unit(ray.dir), t)));
}
