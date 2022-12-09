/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflected_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:18:54 by jsaarine          #+#    #+#             */
/*   Updated: 2022/12/09 18:05:38 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// t_color	reflected_color(t_scene *scene, t_ray *ray)
// {
// 	// t_ray ray_reflected;
// 	t_color color;

// 	printf("📕📗📘 0\n");
// 	printf("%lf\n", ray->hit.object->material.reflective );
// 	printf("📕📗📘 1\n");
// 	color = color_new(0,0,0);
// 	printf("📕📗📘 2\n");
// 	if (ray->depth >= ray->depth_max)
// 		return (color);
// 	printf("📕📗📘 3\n");
// 	ray->depth++;;
// 	printf("📕📗📘 4\n");
// 	if (ray->hit.object->material.reflective < EPSILON)
// 		return (color);
// 	printf("📕📗📘 5\n");

// 	ray->orig = ray->hit.over_point;
// 	ray->dir = ray->hit.reflect_v;
// 	ray->xs.vec.len = 0;
// 	printf("📕📗📘 6\n");
// 	color = color_at(scene, ray);
// 	printf("📕📗📘 7\n");
// 	color = tuple_scalar_mult(color, ray->hit.object->material.reflective);
// 	printf("📕📗📘 8\n");
// 	return (color);
// }

t_color	reflected_color(t_scene *scene, t_ray *ray)
{
	t_color color;

	color = color_new(0,0,0);
	printf("REFLECT? %d\n", ray->depth);
	if (ray->depth >= ray->depth_max)
		return (color);
	ray->depth++;
	// if (ray->hit.object->material.reflective < EPSILON)
	// 	return (color);
	printf("DO WE EVER REFLECT?\n");
	ray->orig = ray->hit.over_point;
	ray->dir = ray->hit.reflect_v;
	ray->xs.vec.len = 0;
	color = color_at(scene, ray);
	color = tuple_scalar_mult(color, ray->hit.object->material.reflective);
	return (color);
}