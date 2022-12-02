/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:55:52 by jjuntune          #+#    #+#             */
/*   Updated: 2022/12/02 18:44:52 by jsaarine         ###   ########.fr       */
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

void	tests(t_main *main, int draw_debug); // unit tests

int	main(void)
{
	t_main		main;
	t_light		light;
	t_object	obj;

	// default_scene(&main.scene);
	scene_new(&main.scene);

	light = point_light_new(point_new(0, 3, -3.0), color_new(0.7, 0.,0 ));
	vec_push(&main.scene.lights, &light);
	light = point_light_new(point_new(-2, 1, -3.0), color_new(0, 0, 0.7));
	vec_push(&main.scene.lights, &light);
	light = point_light_new(point_new(2, 1, -3.0), color_new(0, 0.7, 0.0));
	vec_push(&main.scene.lights, &light);

	

	tuple_print(light.intensity);
	obj = object_new(SPHERE);
	vec_push(&main.scene.objects, &obj);
	// obj.color = color_new(1, 0, 0);
	// obj.transform = matrix_multiply(&obj.transform, &scale);
	// obj.transform = translate = matrix_translate(0.2,0.2,-1);

	// obj = object_new(SPHERE);
	// obj.color = color_new(0, 0, 1);
 
	t_matrix	scale;
	t_matrix	translate;
	obj = object_new(SPHERE);
	scale = matrix_scale(0.2, 0.2, 0.2);
	translate = matrix_translate(0,0,-1);
	obj.transform = matrix_multiply(&obj.transform, &translate);
	obj.transform = matrix_multiply(&obj.transform, &scale);
	vec_push(&main.scene.objects, &obj);

	
	obj = object_new(SPHERE);
	translate = matrix_translate(1,0,0);
	obj.transform = matrix_multiply(&obj.transform, &translate);
	obj.transform = matrix_multiply(&obj.transform, &scale);
	vec_push(&main.scene.objects, &obj);
	
	obj = object_new(SPHERE);
	translate = matrix_translate(-1,0,0);
	obj.transform = matrix_multiply(&obj.transform, &translate);
	obj.transform = matrix_multiply(&obj.transform, &scale);
	vec_push(&main.scene.objects, &obj);
	
	obj = object_new(SPHERE);
	translate = matrix_translate(0,1,0);
	obj.transform = matrix_multiply(&obj.transform, &translate);
	obj.transform = matrix_multiply(&obj.transform, &scale);
	vec_push(&main.scene.objects, &obj);
	
	obj = object_new(SPHERE);
	translate = matrix_translate(0,-1,0);
	obj.transform = matrix_multiply(&obj.transform, &translate);
	obj.transform = matrix_multiply(&obj.transform, &scale);
	vec_push(&main.scene.objects, &obj);

	obj = object_new(SPHERE);
	translate = matrix_translate(0,0,2);
	scale = matrix_scale(200.0, 200.0, 0.01);
	obj.transform = matrix_multiply(&obj.transform, &translate);
	obj.transform = matrix_multiply(&obj.transform, &scale);
	vec_push(&main.scene.objects, &obj); 
	 
	t_matrix	cam_transform;
	t_matrix	rotate;
	t_matrix	cam_scale;
	


	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (1);
	if (initialize_window(&main) == 0)
		return (1);
	
	cam_transform = matrix_translate(0.0, 0.0, -3.0);
	double						x_r = 0.0;
	double						y_r = 0.0;
	double						z_r = 0.0;

	rotate = matrix_rotate_x(x_r);
	cam_transform = matrix_multiply(&cam_transform, &rotate);
	rotate = matrix_rotate_y(y_r);
	cam_transform = matrix_multiply(&cam_transform, &rotate);
	rotate = matrix_rotate_z(z_r);
	cam_transform = matrix_multiply(&cam_transform, &rotate);
	cam_scale = matrix_scale(1,1,1);
	cam_transform = matrix_multiply(&cam_transform, &cam_scale);
	
	/* main.light = point_light_new(point_new(0.0, 2.5, -2.0), color_new(1,1,1)); */
	/* // main.light.pos = point_new(10, 0, 0); */
	
	/* main.obj[0] = object_new(PLANE); */
	/* main.obj[0].transform = matrix_translate(0.0, 0.0, 10.0); */
	/* 										x_r = 0.0; */
	/* 										y_r = 0.0; */
	/* 										z_r = 0.0; */

	/* rotate = matrix_rotate_x(x_r); */
	/* main.obj[0].transform = matrix_multiply(&main.obj[0].transform, &rotate); */
	/* rotate = matrix_rotate_y(y_r); */
	/* main.obj[0].transform = matrix_multiply(&main.obj[0].transform, &rotate); */
	/* rotate = matrix_rotate_z(z_r); */
	/* main.obj[0].transform = matrix_multiply(&main.obj[0].transform, &rotate); */
	/* main.obj[0].material.color = color_new(0,1,1); */


	/* main.obj[1] = object_new(PLANE); */
	/* main.obj[1].transform = matrix_translate(0.0, 0.0, 10.0); */
	/* 										x_r = -M_PI_2; */
	/* 										y_r = 0.0; */
	/* 										z_r = 0.0; */

	/* rotate = matrix_rotate_x(x_r); */
	/* main.obj[1].transform = matrix_multiply(&main.obj[1].transform, &rotate); */
	/* rotate = matrix_rotate_y(y_r); */
	/* main.obj[1].transform = matrix_multiply(&main.obj[1].transform, &rotate); */
	/* rotate = matrix_rotate_z(z_r); */
	/* main.obj[1].transform = matrix_multiply(&main.obj[1].transform, &rotate); */
	/* main.obj[1].material.color = color_new(0,1,0); */




	/* main.obj[2] = object_new(SPHERE); */
	/* main.obj[2].transform = matrix_translate(0.0, 0.0, 2.0); */
	/* 										x_r = 0.0; */
	/* 										y_r = 0.0; */
	/* 										z_r = 0.0; */

	/* rotate = matrix_rotate_x(x_r); */
	/* main.obj[2].transform = matrix_multiply(&main.obj[2].transform, &rotate); */
	/* rotate = matrix_rotate_y(y_r); */
	/* main.obj[2].transform = matrix_multiply(&main.obj[2].transform, &rotate); */
	/* rotate = matrix_rotate_z(z_r); */
	/* main.obj[2].transform = matrix_multiply(&main.obj[2].transform, &rotate); */
	/* // main.obj[2].transform = matrix_multiply(&main.obj[2].transform, &scale_BIGG); */
	/* main.obj[2].material.color = color_new(1,0,0); */




	/* main.obj[3] = object_new(CONE); */
	/* main.obj[3].transform = matrix_translate(3.0, 2.0, 5.0); */
	/* 										x_r = 0.0; */
	/* 										y_r = 0.0; */
	/* 										z_r = 0.0; */

	/* rotate = matrix_rotate_x(x_r); */
	/* main.obj[3].transform = matrix_multiply(&main.obj[3].transform, &rotate); */
	/* rotate = matrix_rotate_y(y_r); */
	/* main.obj[3].transform = matrix_multiply(&main.obj[3].transform, &rotate); */
	/* rotate = matrix_rotate_z(z_r); */
	/* main.obj[3].transform = matrix_multiply(&main.obj[3].transform, &rotate); */
	/* cam_scale = matrix_scale(0.5,1,1); */
	/* main.obj[3].transform = matrix_multiply(&main.obj[3].transform, &cam_scale); */
	/* main.obj[3].material.color = color_new(1, 0.5,0); */


	/* main.obj[4] = object_new(CYLINDER); */
	/* main.obj[4].transform = matrix_translate(-3.0, -2.0, 5.0); */
	/* 										x_r = 0.0; */
	/* 										y_r = 0.0; */
	/* 										z_r = 0.0; */

	/* rotate = matrix_rotate_x(x_r); */
	/* main.obj[4].transform = matrix_multiply(&main.obj[4].transform, &rotate); */
	/* rotate = matrix_rotate_y(y_r); */
	/* main.obj[4].transform = matrix_multiply(&main.obj[4].transform, &rotate); */
	/* rotate = matrix_rotate_z(z_r); */
	/* main.obj[4].transform = matrix_multiply(&main.obj[4].transform, &rotate); */
	/* cam_scale = matrix_scale(0.5,1,1); */
	/* main.obj[4].transform = matrix_multiply(&main.obj[4].transform, &cam_scale); */
	/* main.obj[4].material.color = color_new(1, 0.5,0); */



	/* main.obj_count = 5; */

	int debug = 1;

	if (!debug)
	{
		initialize_camera(&main.cam, cam_transform);
		create_threads(&main, 1);
		draw_frame(&main);
		while (main.multi.threads_done < NUM_THREADS)
			ft_putstr("");
		edge_detection(&main.sdl.frame_buffer);
		main.ant_al = A_A_DIV;
		draw_frame(&main);
		creat_filters(&main.sdl.frame_buffer);
	}
	else
	{
		tests(&main, debug);
	}

	draw_to_window(&main.sdl, main.sdl.frame_buffer.data);
	rt_loop_and_exit(&main.sdl);

	
	SDL_Quit();
	return (0);
}
