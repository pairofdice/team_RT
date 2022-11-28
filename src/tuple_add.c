/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:44:03 by jsaarine          #+#    #+#             */
/*   Updated: 2022/11/27 16:10:04 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	tuple_add(t_tuple left, t_tuple right)
{
	t_tuple	result;

	result.s_xyzw.x = left.s_xyzw.x + right.s_xyzw.x;
	result.s_xyzw.y = left.s_xyzw.y + right.s_xyzw.y;
	result.s_xyzw.z = left.s_xyzw.z + right.s_xyzw.z;
	result.s_xyzw.w = left.s_xyzw.w + right.s_xyzw.w;
	return (result);
}
