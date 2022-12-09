/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:44:03 by jsaarine          #+#    #+#             */
/*   Updated: 2022/12/09 14:40:43 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

#include "stdio.h"
t_matrix	matrix_inverse(t_matrix *m)
{
	// remove stdio
	t_matrix	result;
	double		c;
	t_coords	coords;
	double		det;
	// if (!m)
	// {
	// 	printf("matrix_inverse: NOT MATRIX!\n");
	// 	return(matrix_new_identity(4));
	// }

	// if (m->size < 2 || m->size > 4)
	// {
	// 	printf("SHITTY MATRIX!!!, size: \n");
		
	// 	// matrix_print(m);
	// 	// *m = matrix_new_identity(4);
	// }

	result = matrix_new(m->size);
	det = matrix_determinant(m);
	if (det == 0)
	{
		// result = matrix_new_identity(m->size);
		return (result);
		// FIX	
	}
	coords.row = 0;
	while (coords.row < m->size)
	{
		coords.col = 0;
		while (coords.col < m->size)
		{
			c = matrix_cofactor(m, coords.row, coords.col);
			result.rc[coords.col][coords.row] = c / det;
			coords.col++;
		}
		coords.row++;
	}
	return (result);
}
