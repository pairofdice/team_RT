/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:49:21 by jjuntune          #+#    #+#             */
/*   Updated: 2022/10/18 18:20:15 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

void	add_hit_color(t_main *main, t_object *obj)
{
	main->ray.hit.color.rgb.r += obj->color.rgb.r;
	main->ray.hit.color.rgb.g += obj->color.rgb.g;
	main->ray.hit.color.rgb.b += obj->color.rgb.b;
}

unsigned int	color_to_int(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = (unsigned int)(color.rgb.r * 255);
	g = (unsigned int)(color.rgb.g * 255);
	b = (unsigned int)(color.rgb.b * 255);
	return (r << 24 | g << 16 | b << 8);
}

void	fix_aliasing_color(t_main *main, int sub_pixel_count)
{
	main->ray.hit.color.rgb.r /= sub_pixel_count;
	main->ray.hit.color.rgb.g /= sub_pixel_count;
	main->ray.hit.color.rgb.b /= sub_pixel_count;
}