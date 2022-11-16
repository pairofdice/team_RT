/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_striped.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:55:12 by jjuntune          #+#    #+#             */
/*   Updated: 2022/11/15 19:55:51 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

int	pattern_striped(double	coordinate_in)
{
	double coordinate;

	coordinate = coordinate_in;
	if ((((int)floor(coordinate)) % 2) == 0)
		return (1);
	return (0);
			
}