/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:16:21 by jjuntune          #+#    #+#             */
/*   Updated: 2022/11/29 16:57:36 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

// t_intersection	find_closest_intersection(t_intersections *xs)
// {
// 	t_intersection	closest_t;
// 	size_t			i;
// 	t_intersection	t;

// 	i = 0;
// 	closest_t.t = INFINITY;
// 	while (i < xs->vec.len)
// 	{
// 		//t = *(t_intersection *)vec_get(&xs->vec, i);
// 		if (t.t < closest_t.t && t.t >= 0)
// 		{
// 			//closest_t = t;
// 			// closest_t.i = (t.object->id);
// 		}
// 		i++;
// 	}
// 	return (closest_t);
// }


t_intersection	find_closest_intersection(t_intersections *xs)
{
	t_intersection	intersection;
 	t_intersection	closest;
	size_t			i;
	size_t			closest_i;

	// printf(" 🏴‍☠️ 1\n");
	i = 0;
	closest.t = INFINITY;
	while (i < xs->vec.len)
	{
		// printf(" 🏴‍☠️ 2\n");
		intersection = *(t_intersection *)vec_get(&xs->vec, i);
		// printf(" 🏴‍☠️ 3\n");
		if (intersection.t < closest.t && intersection.t > 0)
		{
			// printf(" 🏴‍☠️ 4\n");
			closest_i = i;
		}
		i++;
	} 
	
	// printf(" 🏴‍☠️ 5\n");
	intersection = *(t_intersection *)vec_get(&xs->vec, 0);
	return (intersection);
}
