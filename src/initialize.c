/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:43:10 by jjuntune          #+#    #+#             */
/*   Updated: 2022/10/10 16:46:51 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

int	initialize_window(t_sdl	*sdl)
{
	sdl->win = SDL_CreateWindow("RT", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H, 0);
	if (sdl->win == NULL)
		return (0);
	sdl->ren = SDL_CreateRenderer(sdl->win, -1, 0);
	if (sdl->ren == NULL)
		return (0);
	sdl->texture = SDL_CreateTexture(sdl->ren, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STREAMING, WIN_W, WIN_H);
	if (sdl->texture == NULL)
		return (0);
	sdl->frame_buffer.data_len = (WIN_H * WIN_W);
	sdl->frame_buffer.data = (int *)malloc(sizeof(int)
			* sdl->frame_buffer.data_len);
	if (sdl->frame_buffer.data == NULL)
		return (0);
	return (1);
}
