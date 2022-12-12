/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:49:21 by jjuntune          #+#    #+#             */
/*   Updated: 2022/12/07 14:12:29 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

void	fix_aliasing_color(t_main *main, int sub_pixel_count)
{
	main->ray.hit.color.s_rgb.r /= sub_pixel_count;
	main->ray.hit.color.s_rgb.g /= sub_pixel_count;
	main->ray.hit.color.s_rgb.b /= sub_pixel_count;
}
