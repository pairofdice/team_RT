/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:01:57 by jjuntune          #+#    #+#             */
/*   Updated: 2022/10/12 14:16:48 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include "../build/libsdl2/include/SDL2/SDL.h"
# include "vector.h"
# include "object.h"
# include <stdio.h>

# define WIN_W 1920
# define WIN_H 1080

typedef struct s_frame_buffer
{
	int			*data;
	int			data_len;
}				t_frame_buffer;

typedef struct s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		event;
	SDL_Texture		*texture;
	t_frame_buffer	frame_buffer;
}				t_sdl;

typedef struct s_cam
{
	t_vec3	pos;
	t_vec3	v_up;
	t_vec3	coi;
	t_vec3	v;
	t_vec3	u;
	t_vec3	n;
	t_vec3	c;
	t_vec3	l;
	double	plane_h;
	double	plane_w;
}			t_cam;

typedef struct s_ray
{
	t_vec3		orig;
	t_vec3		dir;
}				t_ray;

typedef struct s_main
{
	t_cam	cam;
	t_sdl	sdl;
	t_ray	ray;
}				t_main;

int	initialize_window(t_sdl	*sdl);



double	calc_b2_4ac(t_abc abc);
double	quadratic(t_abc abc, double b2_4ac);

#endif