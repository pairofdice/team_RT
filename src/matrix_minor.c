/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_minor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:44:03 by jsaarine          #+#    #+#             */
/*   Updated: 2022/12/08 17:01:36 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "stdio.h"

double	matrix_minor(t_matrix *m33, int skip_row, int skip_col)
{
	t_matrix	m22;
	double		determinant;

	// if (m33->size != 3)
	// 	printf("matrix_minor, shitty matrix! %zu\n", m33->size);
	if (m33->size == 3 || m33->size == 4 )
	{
		m22 = matrix_submatrix(m33, (t_coords){skip_row, skip_col});
		determinant = matrix_determinant(&m22);
		return (determinant);
	}
	return (-1);
}
