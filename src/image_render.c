/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:56:58 by jjuntune          #+#    #+#             */
/*   Updated: 2022/11/09 17:39:27 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

double	get_shape_intersections(t_ray *ray, t_object *shape)
{
	double	ret;

	if (shape->type == SPHERE)
		ret = intersects_sphere(ray, shape);
	else if (shape->type == CYLINDER)
		ret = intersects_cylinder(ray, shape);
	else if (shape->type == PLANE)
		ret = intersects_plane(ray, shape);
	else if (shape->type == CONE)
		ret = intersects_cone(ray, shape);
	else
		return (-1);
	return (ret);
}

void	fill_hit_record(t_main *main, double clo_ret, int clo_shape)
{
	main->ray.hit.hit_dist = clo_ret;
	main->ray.hit.clo_obj_id = clo_shape;
	main->ray.hit.hit_loc = vec3_ray_at(main->ray, clo_ret);
	if (main->obj[clo_shape].type == SPHERE)
		main->ray.hit.normal = get_sphere_normal(main, &main->ray.hit);
	else if (main->obj[clo_shape].type == CYLINDER)
		main->ray.hit.normal = get_cylinder_normal(main, &main->ray.hit);
	else if (main->obj[clo_shape].type == PLANE)
		main->ray.hit.normal = vec3_unit(main->obj[clo_shape].rot);
	else if (main->obj[clo_shape].type == CONE)
		main->ray.hit.normal = get_cone_normal(main, &main->ray.hit);
}

int	ray_shooter(t_ray *ray, t_main *main)
{
	double	ret;
	int		count;
	double	clo_ret;
	int		clo_shape;

	count = 0;
	clo_ret = -1;
	while (count < main->obj_count)
	{
		ret = get_shape_intersections(ray, &main->obj[count]);
		if (ret > 0.0)
		{
			if (clo_ret == -1 || ret < clo_ret)
			{
				clo_shape = count;
				clo_ret = ret;
			}
		}
		count++;
	}
	fill_hit_record(main, clo_ret, clo_shape);
	if (clo_ret < 0.0 || (check_shadow(main, ray) == 1))
		return (0);
	add_hit_color(main, &main->shadow);
	return (1);
}

int	anti_aliasing(t_main *main, int pixel_x, int pixel_y, int ant_al)
{
	double	x;
	double	y;
	double	offset;
	int		i;
	int		j;

	j = 0;
	offset = (1.0 / ant_al);
	while (j < ant_al)
	{
		i = 0;
		y = ((float)pixel_y + (offset / 2) + (offset * j));
		while (i < ant_al)
		{
			x = ((float)pixel_x + (offset / 2) + (offset * i));
			initialize_ray(&main->ray, x, y, &main->cam);
			ray_shooter(&main->ray, main);
			i++;
		}
		j++;
	}
	fix_aliasing_color(main, (ant_al * ant_al));
	return (color_to_int(main->ray.hit.color));
}

void	render_image(t_main	*main, int task, int ant_al)
{
	t_main	copy;
	int		y;
	int		x;
	int		color;

	y = task;// * (WIN_H / NUM_TASKS));
	copy = *main;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			copy.ray.hit.color.s_rgb.r = 0.0;
			copy.ray.hit.color.s_rgb.g = 0.0;
			copy.ray.hit.color.s_rgb.b = 0.0;
			while (ant_al != 1 && x < WIN_W
				&& main->sdl.frame_buffer.mask[((y * WIN_W) + x)] == 0)
				x++;
			if (x == WIN_W)
				break ;
			color = anti_aliasing(&copy, x, y, ant_al);
			main->sdl.frame_buffer.data[((y * WIN_W) + x++)] = color;
		}
		y += NUM_TASKS;
	}
}
