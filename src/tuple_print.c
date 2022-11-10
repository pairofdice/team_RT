/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:44:03 by jsaarine          #+#    #+#             */
/*   Updated: 2022/11/09 21:15:25 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include <printf.h>

void	tuple_print(t_tuple t)
{
	printf("%5.2f %5.2f %5.2f %5.2f\n",
		t.s_xyzw.x,
		t.s_xyzw.y,
		t.s_xyzw.z,
		t.s_xyzw.w);
}
