/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:44:03 by jsaarine          #+#    #+#             */
/*   Updated: 2022/11/10 13:54:38 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "rt.h"

t_matrix	matrix_new(size_t size)
{
	t_matrix	m;

	// ft_bzero(&m, sizeof(t_matrix));
	if (size >= 2 && size <= 4)
		m.size = size;
	else
		m.size = 4;
	return (m);
}

t_matrix	matrix_new_identity(int size)
{
	t_matrix	m;
	t_coords	c;

	m = matrix_new(size);
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
