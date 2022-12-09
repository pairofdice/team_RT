/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:44:22 by jjuntune          #+#    #+#             */
/*   Updated: 2022/12/07 17:46:52 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

int	intersect_cylinder(t_ray *inc_ray, t_object *s)
{
	static t_abcd	abcd;
	// t_point			test_x;
	// t_point			test_y;
	double			t1;
	double			t2;
	t_matrix		inverse_transform;
	t_ray			ray;

	double	y0;
	double	y1;


	ray = ray_new_no_malloc(inc_ray->orig, inc_ray->dir);
	inverse_transform = matrix_inverse(&s->transform);
	ray = ray_transform(&ray, &inverse_transform);
	
	abcd.a = ((ray.dir.s_xyzw.x * ray.dir.s_xyzw.x))
			 + ((ray.dir.s_xyzw.z * ray.dir.s_xyzw.z));
	if (nearly_equal(abcd.a, 0))
		return (0);
	abcd.b = ((2 * ray.orig.s_xyzw.x * ray.dir.s_xyzw.x)
			 + (2 * ray.orig.s_xyzw.z * ray.dir.s_xyzw.z));
	abcd.c = ((ray.orig.s_xyzw.x * ray.orig.s_xyzw.x)
			 + (ray.orig.s_xyzw.z * ray.orig.s_xyzw.z) - 1);
	abcd.d = calc_discriminant(abcd.a, abcd.b, abcd.c);
	if (abcd.d < 0)
		return (0);
	t1 = (-(abcd.b) - sqrt(abcd.d)) / (2 * abcd.a);
	t2 = (-(abcd.b) + sqrt(abcd.d)) / (2 * abcd.a);
	if (t1 > t2)
		double_swap(&t1, &t2);
	// test_x = ray_position(ray, t1);
	// test_y = ray_position(ray, t2);
	// intersection_record_test(inc_ray, t1,t2, s);
	y0 = ray.orig.s_xyzw.y + t1 * ray.dir.s_xyzw.y;
	if (y0 > s->y_min && y0 < s->y_max)
		intersection_record(&inc_ray->xs.vec, t1, s);
	y1 = ray.orig.s_xyzw.y + t2 * ray.dir.s_xyzw.y;
	if (y1 > s->y_min && y1 < s->y_max)
		intersection_record(&inc_ray->xs.vec, t2, s);
	return (1);
}
