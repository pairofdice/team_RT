/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:48:26 by jsaarine          #+#    #+#             */
/*   Updated: 2022/11/06 15:48:03 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include "coords.h"
# include "tuple.h"
# include <stddef.h>

typedef struct s_matrix
{
	double	rc[4][4];
	size_t	size;
}			t_matrix;

void		print_matrix(t_matrix *mm);
t_tuple		matrix_tuple_multiply(t_matrix *m, t_tuple *t);
void		matrix_transpose(t_matrix *m);
double		matrix_determinant(t_matrix *m);
t_matrix	submatrix(t_matrix *src, t_coords c);
double		minor(t_matrix *m, int skip_row, int skip_col);
double		cofactor(t_matrix *m, int row, int col);
t_matrix	matrix_inverse(t_matrix *m);
t_matrix	matrix_translate(double x, double y, double z);
t_matrix	matrix_scale(double x, double y, double z);
t_matrix	matrix_rotate_x(double w);
t_matrix	matrix_rotate_y(double w);
t_matrix	matrix_rotate_z(double w);

#endif