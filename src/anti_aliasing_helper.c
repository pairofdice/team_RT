/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:49:21 by jjuntune          #+#    #+#             */
/*   Updated: 2022/11/06 15:58:02 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

void	add_hit_color(t_main *main, t_ray *shadow)
{
	double	angle;

	if (vec3_dot(main->ray.dir, shadow->hit.normal) > 0)
		shadow->hit.normal = multiply_vect_float(shadow->hit.normal, -1.0);
	angle = vec3_dot(shadow->dir, shadow->hit.normal);
	if (angle >= 0)
	{
		main->ray.hit.color.s_rgb.r
			+= (main->obj[shadow->hit.clo_obj_id].color.s_rgb.r * angle);
		main->ray.hit.color.s_rgb.g
			+= (main->obj[shadow->hit.clo_obj_id].color.s_rgb.g * angle);
		main->ray.hit.color.s_rgb.b
			+= (main->obj[shadow->hit.clo_obj_id].color.s_rgb.b * angle);
	}
}

unsigned int	color_to_int(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = (unsigned int)(color.s_rgb.r * 255);
	g = (unsigned int)(color.s_rgb.g * 255);
	b = (unsigned int)(color.s_rgb.b * 255);
	return (r << 24 | g << 16 | b << 8);
}

void	fix_aliasing_color(t_main *main, int sub_pixel_count)
{
	main->ray.hit.color.s_rgb.r /= sub_pixel_count;
	main->ray.hit.color.s_rgb.g /= sub_pixel_count;
	main->ray.hit.color.s_rgb.b /= sub_pixel_count;
}
