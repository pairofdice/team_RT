/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:32:00 by jsaarine          #+#    #+#             */
/*   Updated: 2022/12/07 18:28:07 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_material	material_new()
{
	t_material	m;

 	m.ambient = 0.1;
 	m.diffuse = 0.9;
 	m.color = color_new(1, 1, 1);
	m.shininess = 200.0;
 	m.specular = 0.9;
	m.reflective = 0.0;
	return (m);
}