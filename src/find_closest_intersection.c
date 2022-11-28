/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:16:21 by jjuntune          #+#    #+#             */
/*   Updated: 2022/11/28 14:56:45 by jsaarine         ###   ########.fr       */
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

	i = 0;
	closest.t = INFINITY;
	while (i < xs->vec.len)
	{
		intersection = *(t_intersection *)vec_get(&xs->vec, i);
		if (intersection.t < closest.t && intersection.t > 0)
			closest_i = i;
		i++;
	} 
	
	intersection = *(t_intersection *)vec_get(&xs->vec, 0);
	return (intersection);
}
