/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:20:53 by jjuntune          #+#    #+#             */
/*   Updated: 2022/10/12 13:29:37 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclue/rt.h"

double	calc_b2_4ac(t_abc abc)
{
	return (abc.b * abc.b - 4 * abc.a * abc.c);
}

double	quadratic(t_abc abc, double b2_4ac)
{
	double	result_m;
	double	result_p;
	double	numerator;

	if (b2_4ac < 0)
		return (INFINITY);
	numerator = -abc.b - sqrt(b2_4ac);
	result_m = numerator / (2 * abc.a);
	numerator = -abc.b + sqrt(b2_4ac);
	result_p = numerator / (2 * abc.a);
	if (result_p < result_m && result_p >= 0.0)
		return (result_p);
	if (result_m >= 0.0)
		return (result_m);
	return (INFINITY);
}
