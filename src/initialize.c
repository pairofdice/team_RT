/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:43:10 by jjuntune          #+#    #+#             */
/*   Updated: 2022/10/19 22:33:28 by jjuntune         ###   ########.fr       */
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
	sdl->frame_buffer.cartoon = (int *)malloc(sizeof(int)
			* sdl->frame_buffer.data_len);
	if (sdl->frame_buffer.cartoon == NULL)
		return (0);
	sdl->frame_buffer.b_w = (int *)malloc(sizeof(int)
			* sdl->frame_buffer.data_len);
	if (sdl->frame_buffer.b_w == NULL)
		return (0);
	sdl->frame_buffer.b_w_cartoon = (int *)malloc(sizeof(int)
			* sdl->frame_buffer.data_len);
	if (sdl->frame_buffer.b_w_cartoon == NULL)
		return (0);
	sdl->frame_buffer.edge_map = (int *)malloc(sizeof(int)
			* sdl->frame_buffer.data_len);
	if (sdl->frame_buffer.edge_map == NULL)
		return (0);
	sdl->frame_buffer.mask = (char *)malloc(sizeof(char)
			* sdl->frame_buffer.data_len);
	if (sdl->frame_buffer.mask == NULL)
		return (0);
	return (1);
}

void	initialize_camera(t_cam *cam)
{
	double	angle;

	cam->v_up = div_vect_float(cam->v_up,
			sqrt(vec3_dot(cam->v_up, cam->v_up)));
	cam->n = vec3_sub(cam->pos, cam->coi);
	cam->n = div_vect_float(cam->n,
			sqrt(vec3_dot(cam->n, cam->n)));
	cam->n = div_vect_float(cam->n, -1.0);
	angle = vec3_dot(cam->v_up, cam->n);
	if (angle == 1 || angle == -1)
		cam->v_up = add_vect_float(cam->v_up, 0.001);
	cam->u = vec3_cross(cam->n, cam->v_up);
	cam->u = div_vect_float(cam->u,
			sqrt(vec3_dot(cam->u, cam->u)));
	cam->v = vec3_cross(cam->u, cam->n);
	cam->c = vec3_sub(cam->pos,
			multiply_vect_float(cam->n, 0.1));
	cam->plane_h = tan(1.04719 / 2) * 2 * 0.1;
	cam->plane_w = cam->plane_h * ((float)WIN_W / WIN_H);
	cam->l = vec3_sub(cam->c,
			multiply_vect_float(cam->u, (cam->plane_w / 2.0)));
	cam->l = vec3_sub(cam->l,
			multiply_vect_float(cam->v, cam->plane_h / 2.0));
}

void	initialize_ray(t_ray *ray, double x, double y, t_cam *cam)
{
	ray->dir = vec3_add(cam->l, multiply_vect_float(cam->u,
				x * (cam->plane_w / WIN_W)));
	ray->dir = vec3_add(ray->dir, multiply_vect_float(cam->v,
				y * (cam->plane_h / WIN_H)));
	ray->dir = vec3_sub(cam->pos, ray->dir);
	ray->dir = div_vect_float(ray->dir, sqrt(vec3_dot(ray->dir, ray->dir)));
}
