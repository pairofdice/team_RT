/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:44:22 by jjuntune          #+#    #+#             */
/*   Updated: 2022/11/27 18:33:36 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

int	intersect_cylinder(t_ray *inc_ray, t_object *s)
{
	static t_abcd	abcd;
	t_point			test_x;
	t_point			test_y;
	double			t1;
	double			t2;
	t_matrix		inverse_transform;
	t_ray			ray;

	ray = ray_new_no_malloc(inc_ray->orig, inc_ray->dir);
	inverse_transform = matrix_inverse(&s->transform);
	ray = ray_transform(inc_ray, &inverse_transform);
	
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
	test_x = ray_position(ray, t1);
	test_y = ray_position(ray, t2);
	// intersection_record_test(inc_ray, t1,t2, s);
	intersection_record(&inc_ray->xs.vec, t2, s);
	return (1);
	
	return (0);
}
