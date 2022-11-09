/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:55:52 by jjuntune          #+#    #+#             */
/*   Updated: 2022/11/11 22:19:40 by jjuntune         ###   ########.fr       */
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
	t_matrix	rotate;
	t_matrix	cam_scale;

	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (1);
	if (initialize_window(&main) == 0)
		return (1);
	
	cam_transform = matrix_translate(-5.0, 1.0, 0.0);
	double						x_r = 0.0;
	double						y_r = 1.0;
	double						z_r = 0.0;

	rotate = matrix_rotate_x(x_r);
	cam_transform = matrix_multiply(&cam_transform, &rotate);
	rotate = matrix_rotate_y(y_r);
	cam_transform = matrix_multiply(&cam_transform, &rotate);
	rotate = matrix_rotate_z(z_r);
	cam_transform = matrix_multiply(&cam_transform, &rotate);
	cam_scale = matrix_scale(1,1,1);
	cam_transform = matrix_multiply(&cam_transform, &cam_scale);
	

	main.light.pos = point_new(10, 0, 0);

		//0 = sphere
		//1 = cylinder
		//2 = plane
		//3 = cone

	
	main.obj[0].transform = matrix_translate(0.0, 0.0, 10.0);
											x_r = 0.0;
											y_r = 0.0;
											z_r = 0.0;

	rotate = matrix_rotate_x(x_r);
	main.obj[0].transform = matrix_multiply(&main.obj[0].transform, &rotate);
	rotate = matrix_rotate_y(y_r);
	main.obj[0].transform = matrix_multiply(&main.obj[0].transform, &rotate);
	rotate = matrix_rotate_z(z_r);
	main.obj[0].transform = matrix_multiply(&main.obj[0].transform, &rotate);
	//cam_scale = matrix_scale(1,1,1);
	//main.obj[0].transform = matrix_multiply(&main.obj[0].transform, &cam_scale);
	main.obj[0].type = PLANE;
	main.obj[0].id = 0;
	main.obj[0].color.s_rgb.r = 0.0;
	main.obj[0].color.s_rgb.g = 1.0;
	main.obj[0].color.s_rgb.b = 0.0;
	main.obj[0].color.s_rgb.b = 1.0;

	main.obj[1].transform = matrix_translate(0.0, 0.0, 10.0);
											x_r = M_PI_2;
											y_r = 0.0;
											z_r = 0.0;

	rotate = matrix_rotate_x(x_r);
	main.obj[1].transform = matrix_multiply(&main.obj[1].transform, &rotate);
	rotate = matrix_rotate_y(y_r);
	main.obj[1].transform = matrix_multiply(&main.obj[1].transform, &rotate);
	rotate = matrix_rotate_z(z_r);
	main.obj[1].transform = matrix_multiply(&main.obj[1].transform, &rotate);
	//cam_scale = matrix_scale(1,1,1);
	//main.obj[1].transform = matrix_multiply(&main.obj[1].transform, &cam_scale);
	main.obj[1].type = PLANE;
	main.obj[1].id = 1;
	main.obj[1].color.s_rgb.r = 0.0;
	main.obj[1].color.s_rgb.g = 1.0;
	main.obj[1].color.s_rgb.b = 0.0;

	main.obj[2].transform = matrix_translate(0.0, 0.0, 10.0);
											x_r = 0.0;
											y_r = 0.0;
											z_r = 0.0;

	rotate = matrix_rotate_x(x_r);
	main.obj[2].transform = matrix_multiply(&main.obj[2].transform, &rotate);
	rotate = matrix_rotate_y(y_r);
	main.obj[2].transform = matrix_multiply(&main.obj[2].transform, &rotate);
	rotate = matrix_rotate_z(z_r);
	main.obj[2].transform = matrix_multiply(&main.obj[2].transform, &rotate);
	//cam_scale = matrix_scale(1,1,1);
	//main.obj[1].transform = matrix_multiply(&main.obj[1].transform, &cam_scale);
	main.obj[2].type = SPHERE;
	main.obj[2].id = 2;
	main.obj[2].color.s_rgb.r = 1.0;
	main.obj[2].color.s_rgb.g = 0.0;
	main.obj[2].color.s_rgb.b = 0.0;

	main.obj[3].transform = matrix_translate(0.0, 2.0, 5.0);
											x_r = 0.0;
											y_r = 0.0;
											z_r = 0.0;

	rotate = matrix_rotate_x(x_r);
	main.obj[3].transform = matrix_multiply(&main.obj[3].transform, &rotate);
	rotate = matrix_rotate_y(y_r);
	main.obj[3].transform = matrix_multiply(&main.obj[3].transform, &rotate);
	rotate = matrix_rotate_z(z_r);
	main.obj[3].transform = matrix_multiply(&main.obj[3].transform, &rotate);
	cam_scale = matrix_scale(0.5,1,1);
	main.obj[3].transform = matrix_multiply(&main.obj[3].transform, &cam_scale);
	main.obj[3].type = CONE;
	main.obj[3].id = 3;
	main.obj[3].color.s_rgb.r = 1.0;
	main.obj[3].color.s_rgb.g = 0.5;
	main.obj[3].color.s_rgb.b = 0.0;

	main.obj_count = 4;

	initialize_camera(&main.cam, cam_transform);
	create_threads(&main, 1);
	draw_frame(&main);
	while (main.multi.threads_done < NUM_THREADS)
		ft_putstr("");
	edge_detection(&main.sdl.frame_buffer);
	main.ant_al = A_A_DIV;
	draw_frame(&main);
	creat_filters(&main.sdl.frame_buffer);
	draw_to_window(&main.sdl, main.sdl.frame_buffer.data);
	rt_loop_and_exit(&main.sdl);
	SDL_Quit();
	return (0);
}
