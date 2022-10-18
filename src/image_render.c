/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:56:58 by jjuntune          #+#    #+#             */
/*   Updated: 2022/10/18 21:54:33 by jjuntune         ###   ########.fr       */
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
	if (clo_ret < 0.0)
		return (0);
	fill_hit_record(main, clo_ret, clo_shape);
	if (check_shadow(main, ray) == 1)
		return (0);
	add_hit_color(main, &main->obj[clo_shape]);
	return (1);
}

int	anti_aliasing(t_main *main, int pixel_x, int pixel_y)
{
	double x;
	double y;
	int		i;
	int		j;
	int color;

	j = 0;
	while (j < A_A_DIV)
	{
		i = 0;
		y = ((float)pixel_y + ((1.0 / A_A_DIV) * j));
		while (i < A_A_DIV)
		{
			x = ((float)pixel_x + ((1.0 / A_A_DIV) * i));
			initialize_ray(&main->ray, x, y, &main->cam);
			ray_shooter(&main->ray, main);
			i++;
		}
		j++;
	}
	fix_aliasing_color(main, (A_A_DIV * A_A_DIV));
	color = color_to_int(main->ray.hit.color);
	return (color);
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
			main->ray.hit.color.rgb.r = 0.0;
			main->ray.hit.color.rgb.g = 0.0;
			main->ray.hit.color.rgb.b = 0.0;
			color = anti_aliasing(main, x, y);
			main->sdl.frame_buffer.data[((y * WIN_W) + x)] = color;
			x++;
		}
		y++;
	}
}
