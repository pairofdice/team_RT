/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:55:52 by jjuntune          #+#    #+#             */
/*   Updated: 2022/10/18 19:48:31 by jjuntune         ###   ########.fr       */
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

int	main(void)
{
	t_main	main;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (1);
	if (initialize_window(&main.sdl) == 0)
		return (1);
	main.cam.pos.x = 0.0;
	main.cam.pos.y = 0.0;
	main.cam.pos.z = 0.0;
	
	main.cam.v_up.x = 0.0;
	main.cam.v_up.y = 1.0;
	main.cam.v_up.z = 0.0;
	
	main.cam.coi.x = 0.0;
	main.cam.coi.y = 0.0;
	main.cam.coi.z = 10.0;


	main.obj[0].loc.x = 0.0;
	main.obj[0].loc.y = 0.0;
	main.obj[0].loc.z = 30.0;
	main.obj[0].rot.x = 1.0;
	main.obj[0].rot.y = 10.0;
	main.obj[0].rot.z = 0.0;
	main.obj[0].size = 3.0;
	main.obj[0].type = 0;
	main.obj[0].color.rgb.r = 0.0;
	main.obj[0].color.rgb.g = 1.0;
	main.obj[0].color.rgb.b = 1.0;
	
	main.obj[1].loc.x = 5.0;
	main.obj[1].loc.y = 0.0;
	main.obj[1].loc.z = 30.0;
	main.obj[1].rot.x = 1.0;
	main.obj[1].rot.y = 10.0;
	main.obj[1].rot.z = 0.0;
	main.obj[1].size = 0.1;
	main.obj[1].type = 0;
	main.obj[1].color.rgb.r = 0.9;
	main.obj[1].color.rgb.g = 0.5;
	main.obj[1].color.rgb.b = 0.2;
	initialize_camera(&main.cam);
	render_image(&main);

	draw_to_window(&main.sdl);
	rt_loop_and_exit(&main.sdl);
	SDL_Quit();
	return (0);
}
