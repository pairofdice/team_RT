/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:56:24 by jjuntune          #+#    #+#             */
/*   Updated: 2022/10/12 14:06:48 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OBJECT_H
# define OBJECT_H

typedef struct s_object
{
	t_vec3	loc;
	t_vec3	coi;
	t_vec3	up;
	t_vec3	rot;
	double	size;
	double	brightness;
	int		type;
}	t_object;

typedef struct s_abc
{
	double		a;
	double		b;
	double		c;
}				t_abc;

#endif