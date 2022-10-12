/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:39:38 by jjuntune          #+#    #+#             */
/*   Updated: 2022/10/12 14:13:30 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

double	dot_prdct(t_vec3 a, t_vec3 b);
t_vec3	cross_product(t_vec3 a, t_vec3 b);

t_vec3	add_vectors(t_vec3 a, t_vec3 b);
t_vec3	sub_vectors(t_vec3 a, t_vec3 b);

t_vec3	multiply_vectors(t_vec3 a, t_vec3 b);
t_vec3	div_vectors(t_vec3 a, t_vec3 b);

t_vec3	multiply_vect_float(t_vec3 a, double b);
t_vec3	div_vect_float(t_vec3 a, double b);
t_vec3	add_vect_float(t_vec3 a, double b);


#endif