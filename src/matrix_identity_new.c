/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_identity_new.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:44:03 by jsaarine          #+#    #+#             */
/*   Updated: 2022/12/08 17:05:10 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	matrix_identity_new(int size)
{
	t_matrix	m;
	t_coords	c;

	// v remove
	if (size >= 2 && size <= 4 )
		m = matrix_new(size);
	else
		m = matrix_new(4);
	// ^ remove
	c.col = 0;
	while (c.col < m.size)
	{
		c.row = 0;
		while (c.row < m.size)
		{
			if (c.row == c.col)
				m.rc[c.row][c.col] = 1;
			else
				m.rc[c.row][c.col] = 0;
			c.row++;
		}
		c.col++;
	}
	return (m);
}
