/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:43:10 by jjuntune          #+#    #+#             */
/*   Updated: 2022/10/12 14:14:38 by jjuntune         ###   ########.fr       */
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

void	initialize_camera(t_cam *cam)
{
	double	angle;

	cam->v_up = div_vect_float(cam->v_up, sqrt(dot_prdct(cam->v_up, cam->v_up)));
	cam->n = sub_vectors(cam->pos, cam->coi);
	cam->n = div_vect_float(cam->n, sqrt(dot_prdct(cam->n, cam->n)));
	cam->n = div_vect_float(cam->n, -1.0);
	angle = dot_prdct(cam->v_up, cam->n);
	if (angle == 1 || angle == -1)
		cam->v_up.z += 0.001;
	cam->u = cross_product(cam->n, cam->v_up);
	cam->u = div_vect_float(cam->u, sqrt(dot_prdct(cam->u, cam->u)));
	cam->v = cross_product(cam->u, cam->n);
	cam->c = sub_vectors(cam->pos, multiply_vect_float(cam->n, 0.1));
	cam->plane_h = (tan(1.04719 / 2) * 2 * 0.1);
	cam->plane_w = (cam->plane_h * ((float)WIN_W / WIN_H));
	cam->l = sub_vectors(cam->c, multiply_vect_float(cam->u, (cam->plane_w / 2.0)));
	cam->l = sub_vectors(cam->l, multiply_vect_float(cam->v, cam->plane_h / 2.0));
}

void	initialize_ray(t_ray *ray, int x, int y, t_cam *cam)
{
	ray->orig = cam->pos;
	ray->dir = add_vectors(cam->l, multiply_vect_float(cam->u,
				((float)x * (cam->plane_w / WIN_W))));
	ray->dir = add_vectors(ray->dir, multiply_vect_float(cam->v,
				((float)y * (cam->plane_h / WIN_H))));
	ray->dir = div_vectors(cam->pos, ray->dir);
	ray->dir = div_vect_float(ray->dir,
			sqrt((dot_prdct(ray->dir, ray->dir))));
}
