/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_cofactor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:44:03 by jsaarine          #+#    #+#             */
/*   Updated: 2022/12/08 16:59:46 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	matrix_cofactor(t_matrix *m33, int row, int col)
{
	double	result;

	result = matrix_minor(m33, row, col); 
	if ((row + col) % 2 == 1)
		result = -result;
	return (result);
}
