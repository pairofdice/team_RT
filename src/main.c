/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:55:52 by jjuntune          #+#    #+#             */
/*   Updated: 2022/10/10 16:40:08 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

//Copys 1d arrey to texture and draws it.

void	draw_to_window(t_sdl *sdl)
{
	int		*texture_data;
	int		texture_pitch;

	SDL_LockTexture(sdl->texture, NULL, (void **)&texture_data, &texture_pitch);
	ft_memcpy(texture_data, sdl->frame_buffer.data,
		(sdl->frame_buffer.data_len * sizeof(int)));
	SDL_UnlockTexture(sdl->texture);
	SDL_RenderCopy(sdl->ren, sdl->texture, NULL, NULL);
	SDL_RenderPresent(sdl->ren);
}

// Infinet loop to handle the window.

void	rt_loop_and_exit(t_sdl *sdl)
{
	int	quit;

	quit = 0;
	while (quit == 0)
	{
		if (SDL_WaitEvent(&sdl->event) != 0)
		{
			if (sdl->event.type == SDL_QUIT)
				quit = 1;
			if (sdl->event.type == SDL_KEYDOWN)
				if (sdl->event.key.keysym.sym == SDLK_ESCAPE)
					quit = 1;
		}
		//draw_to_window(sdl);
	}
	SDL_DestroyTexture(sdl->texture);
	SDL_DestroyWindow(sdl->win);
	free(sdl->frame_buffer.data);
}

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

int	main(void)
{
	t_sdl	sdl;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (1);
	if (initialize_window(&sdl) == 0)
		return (1);
	//draw_to_window(&sdl);
	rt_loop_and_exit(&sdl);
	SDL_Quit();
	return (0);
}
