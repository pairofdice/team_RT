/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:01:57 by jjuntune          #+#    #+#             */
/*   Updated: 2022/10/10 16:34:52 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include "../build/libsdl2/include/SDL2/SDL.h"
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

#endif