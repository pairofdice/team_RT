/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:55:52 by jjuntune          #+#    #+#             */
/*   Updated: 2022/11/11 21:41:22 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

//Copys 1d arrey to texture and draws it.

void	draw_filter(t_sdl *sdl, int *filter_type, int i)
{
	if (i == 1)
	{
		if (sdl->event.key.keysym.sym == SDLK_DOWN && *filter_type > 0)
			*filter_type -= 1;
		else if (sdl->event.key.keysym.sym == SDLK_DOWN)
			*filter_type = 4;
		else if (sdl->event.key.keysym.sym == SDLK_UP && *filter_type < 4)
			*filter_type += 1;
		else if (sdl->event.key.keysym.sym == SDLK_UP)
			*filter_type = SPHERE;
	}
	if (*filter_type == 0)
		draw_to_window(sdl, sdl->frame_buffer.data);
	else if (*filter_type == 1)
		draw_to_window(sdl, sdl->frame_buffer.cartoon);
	else if (*filter_type == 2)
		draw_to_window(sdl, sdl->frame_buffer.b_w);
	else if (*filter_type == 3)
		draw_to_window(sdl, sdl->frame_buffer.b_w_cartoon);
	else if (*filter_type == 4)
		draw_to_window(sdl, sdl->frame_buffer.edge_map);
}

static void	free_buffers_and_sdl(t_sdl *sdl)
{
	SDL_DestroyTexture(sdl->texture);
	SDL_DestroyWindow(sdl->win);
	free(sdl->frame_buffer.data);
	free(sdl->frame_buffer.cartoon);
	free(sdl->frame_buffer.b_w);
	free(sdl->frame_buffer.b_w_cartoon);
	free(sdl->frame_buffer.edge_map);
}

// Infinite loop to handle the window.

void	rt_loop_and_exit(t_sdl *sdl)
{
	int	quit;
	int	filter_type;

	quit = 0;
	filter_type = SPHERE;
	while (quit == 0)
	{
		if (SDL_WaitEvent(&sdl->event) != 0)
			kay_hooks(sdl, &quit, &filter_type);
		draw_filter(sdl, &filter_type, 0);
	}
	free_buffers_and_sdl(sdl);
}

void	tests(t_main *main); // unit tests

int	main(void)
{
	t_main		main;
	t_matrix	cam_transform;
	t_matrix	cam_rotate;
	t_matrix	cam_scale;

	


	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (1);
	if (initialize_window(&main) == 0)
		return (1);
	
	cam_transform = matrix_translate(0.0, 0.0, 0.0);
	double						x_r = 0.0;
	double						y_r = 0.0;
	double						z_r = 0.0;

	cam_rotate = matrix_rotate_x(x_r);
	cam_transform = matrix_multiply(&cam_transform, &cam_rotate);
	cam_rotate = matrix_rotate_y(y_r);
	cam_transform = matrix_multiply(&cam_transform, &cam_rotate);
	cam_rotate = matrix_rotate_z(z_r);
	cam_transform = matrix_multiply(&cam_transform, &cam_rotate);
	cam_scale = matrix_scale(1,1,1);
	cam_transform = matrix_multiply(&cam_transform, &cam_scale);
	

	main.light.pos = point_new(10, 0, 0);

		//0 = sphere
		//1 = cylinder
		//2 = plane
		//3 = cone

		
	main.obj[0].loc = point_new(0, 0, 30);
	main.obj[0].size = 3.0;
	main.obj[0].type = SPHERE;
	main.obj[0].color.s_rgb.r = 0.0;
	main.obj[0].color.s_rgb.g = 1.0;
	main.obj[0].color.s_rgb.b = 0.0;

	main.obj[1].loc = point_new(5, 0, 30);
	main.obj[1].size = 0.1;
	main.obj[1].type = SPHERE;
	main.obj[1].color.s_rgb.r = 1.0;
	main.obj[1].color.s_rgb.g = 0.0;
	main.obj[1].color.s_rgb.b = 0.0;

	main.obj[2].loc = point_new(0, 0, 40);
	main.obj[2].rot = vector_new(0,0,1);
	main.obj[2].type = PLANE;
	main.obj[2].color.s_rgb.r = 1.0;
	main.obj[2].color.s_rgb.g = 1.0;
	main.obj[2].color.s_rgb.b = 1.0;

	main.obj[3].loc = point_new(0,-10, 40);
	main.obj[3].rot = vector_new(0,1,0);
	main.obj[3].type = PLANE;
	main.obj[3].color.s_rgb.r = 0.0;
	main.obj[3].color.s_rgb.g = 1.0;
	main.obj[3].color.s_rgb.b = 1.0;

	main.obj[4].loc = point_new(0, 0, 30);
	main.obj[4].rot = vector_new(1,1,1);
	main.obj[4].type = CYLINDER;
	main.obj[4].size = 0.9;
	main.obj[4].color.s_rgb.r = 1.0;
	main.obj[4].color.s_rgb.g = 1.0;
	main.obj[4].color.s_rgb.b = 1.0;

	main.obj[5].loc = point_new(0, 0, 30);
	main.obj[5].rot = vector_new(-1,1,1);
	main.obj[5].type = CYLINDER;
	main.obj[5].size = 1.2;
	main.obj[5].color.s_rgb.r = 1.0;
	main.obj[5].color.s_rgb.g = 0.0;
	main.obj[5].color.s_rgb.b = 1.0;

	main.obj[6].loc = point_new(-10.0, 0, 30);
	main.obj[6].rot = vector_new(0,1,0);
	main.obj[6].type = CONE;
	main.obj[6].size = 1;
	main.obj[6].color.s_rgb.r = 1.0;
	main.obj[6].color.s_rgb.g = 0.1;
	main.obj[6].color.s_rgb.b = 0.8;
	main.obj_count = 7;

	initialize_camera(&main.cam, cam_transform);
/* 	create_threads(&main, 1);
	draw_frame(&main);
	while (main.multi.threads_done < NUM_THREADS)
		ft_putstr("");
	edge_detection(&main.sdl.frame_buffer);
	main.ant_al = A_A_DIV;
	draw_frame(&main);
	creat_filters(&main.sdl.frame_buffer); */
	
	tests(&main);
	draw_to_window(&main.sdl, main.sdl.frame_buffer.data);
	rt_loop_and_exit(&main.sdl);
	SDL_Quit();
	return (0);
}
