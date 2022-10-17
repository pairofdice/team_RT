/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:56:58 by jjuntune          #+#    #+#             */
/*   Updated: 2022/10/17 20:41:00 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

double	get_shape_intersections(t_ray *ray, t_object *shape)
{
	double	ret;

	if (shape->type == 0)
		ret = intersects_sphere(ray, shape);
	else if (shape->type == 1)
		ret = intersects_cylinder(ray, shape);
	else if (shape->type  == 2)
		ret = intersects_plane(ray, shape);
	else if (shape->type == 3)
		ret = intersects_cone(ray, shape);
	else
		return (-1);
	//printf("%f\n", ret);
	return (ret);
}
void fill_hit_record(t_main *main, double clo_ret, int clo_shape)
{
	main->ray.hit.hit_dist = clo_ret;
	main->ray.hit.clo_obj_id = clo_shape;
	main->ray.hit.hit_loc = vec3_ray_at(main->ray, clo_ret);
	if (main->obj[clo_shape].type == 0)
		main->ray.hit.normal = get_sphere_normal(main, &main->ray.hit);
	else if (main->obj[clo_shape].type == 1)
		main->ray.hit.normal = get_cylinder_normal(main, &main->ray.hit);
	else if (main->obj[clo_shape].type  == 2)
		main->ray.hit.normal = vec3_unit(main->obj[clo_shape].rot);
	else if (main->obj[clo_shape].type == 3)
		main->ray.hit.normal = get_cone_normal(main, &main->ray.hit);
	main->ray.hit.color = main->obj[clo_shape].color;
}

int	ray_shooter(t_ray *ray, t_main *main)
{
	double	ret;
	int		count;
	double	clo_ret;
	int		clo_shape;

	count = 0;
	clo_ret = -1;
	while (count < SHAPECOUNT)
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
	if (clo_ret > 0.0)
		return (main->obj[0].color.value);
	return (0x00000000);
}

void	render_image(t_main	*main)
{
	int		y;
	int		x;
	int		color;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			main->ray.orig = main->cam.pos;
			initialize_ray(&main->ray, x, y, &main->cam);
			color = ray_shooter(&main->ray, main);
			main->sdl.frame_buffer.data[((y * WIN_W) + x)] = color;
			x++;
		}
		y++;
	}
}
