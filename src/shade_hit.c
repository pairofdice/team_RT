#include "../include/object.h"
#include "../include/rt.h"
#include "../include/tuple.h"
#include <stddef.h>

t_color	shade_hit(t_scene *scene, t_ray *ray)
{
	t_color	result;
	t_color	temp_color;
	t_color	reflected;
	t_light	light;
	size_t	i;
	

	i = 0;
	result = color_new(0, 0, 0);
	while (i < scene->lights.len)
	{
		light = *(t_light *)vec_get(&scene->lights, i);
		temp_color = lighting(&ray->hit.object->material, 
								light, ray->hit.hit_loc, 
								ray->hit.to_eye, 
								ray->hit.normal, 
								is_shadowed(scene, light,  ray->hit.over_point));
		reflected = reflected_color(scene, ray);
		result = tuple_add(result, temp_color);
		result = tuple_add(result, reflected);
		i++;
	}
	return (result);
}

// t_color	shade_hit(t_scene *scene, t_ray *ray)
// {
// 	t_color	result;
// 	t_color	reflected;
// 	t_light	light;
// 	size_t	i;
// 	int shadowed;
	

// 	i = 0;
// 	result = color_new(0, 0, 0);
// 	while (i < scene->lights.len)
// 	{
// 		light = *(t_light *)vec_get(&scene->lights, i);
// 		shadowed = is_shadowed(scene, light,  ray->hit.over_point);
// 		result = lighting(&ray->hit.object->material, 
// 								light,
// 								ray->hit.over_point, 
// 								ray->hit.to_eye, 
// 								ray->hit.normal, 
// 								shadowed);
// 		reflected = reflected_color(scene, ray);
// 		// result = tuple_add(result, reflected);
// 		i++;
// 	}
// 	return (result);
// }
