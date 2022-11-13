/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:56:58 by jjuntune          #+#    #+#             */
/*   Updated: 2022/11/13 19:34:38 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

/* int	get_shape_intersections(t_ray *ray, t_object *shape)
{
	int	ret;

	ret = 0;
	if (shape->type == SPHERE)
		ret = intersect_sphere(ray, shape);
	else if (shape->type == CYLINDER)
		ret = intersect_cylinder(ray, shape);
	else if (shape->type == PLANE)
		ret = intersect_plane(ray, shape);
	else if (shape->type == CONE)
		ret = intersect_cone(ray, shape);
	
	return (ret);
}
 */
int	fill_hit_record(t_ray *ray)
{
	t_intersection closest_t;

	closest_t = find_closest_intersection(&ray->xs);
	if (!closest_t.t)
		return (1);
	ray->hit.hit_dist = closest_t.t;
	ray->hit.clo_obj_id = (int)closest_t.i;
	ray->hit.hit_loc = ray_position(*ray, ray->hit.hit_dist);

	//if (main->obj[clo_shape].type == SPHERE)
	//	main->ray.hit.normal = get_sphere_normal(main, &main->ray.hit);
	//else if (main->obj[clo_shape].type == CYLINDER)
	//	main->ray.hit.normal = get_cylinder_normal(main, &main->ray.hit);
	//else if (main->obj[clo_shape].type == PLANE)
	//	main->ray.hit.normal = tuple_unit(main->obj[clo_shape].rot);
	//else if (main->obj[clo_shape].type == CONE)
	//	main->ray.hit.normal = get_cone_normal(main, &main->ray.hit);
	return (0);
}

int	ray_shooter(t_ray *ray, t_main *main)
{
	int		count;
	int		hit;

	count = 0;
	hit = 0;
	while (count < main->obj_count)
	{
		if (get_shape_intersections(ray, &main->obj[count]) == 1)
			hit++;
		count++;
	}
	//printf ("hit count per pixel %d\n", hit);
	if (hit > 0)
	{
		if (fill_hit_record(ray) == 1)
			return (0);
		//if (check_shadow(main, ray) == 1)
		//	return (0);
		
		// add_hit_color(main, &main->ray);
		ray->hit.normal = normal_at(&main->obj[ray->hit.clo_obj_id], ray->hit.hit_loc);
	
		main->ray.hit.color = lighting(main->obj[ray->hit.clo_obj_id].material, main->light, ray->hit.hit_loc, tuple_neg(ray->dir), ray->hit.normal);
		return (1);
	}
	return (0);
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
			vec_free(&main->ray.xs.vec);
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

	y = task;
	copy = *main;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			// copy.ray.hit.color.s_rgb.r = 0.0;
			// copy.ray.hit.color.s_rgb.g = 0.0;
			// copy.ray.hit.color.s_rgb.b = 0.0;
			copy.ray.hit.color = color_new(0,0,0);
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
