#include "../include/object.h"
#include "../include/rt.h"
#include "../include/tuple.h"
#include <stddef.h>

t_color	shade_hit(t_scene *scene, t_hit_record *hit)
{
	t_color	result;
	t_color	temp_color;
	t_light	light;
	size_t	i;

	i = 0;
	result = color_new(0, 0, 0);
	while (i < scene->lights.len)
	{
		light = *(t_light *)vec_get(&scene->lights, i);
		// printf("light color: ");
		// tuple_print(light.intensity);
		temp_color = lighting(&hit->object->material, light, hit->hit_loc, hit->to_eye, hit->normal, 1);
		// printf("result color: ");
		// tuple_print(temp_color);
		result = tuple_add(result, temp_color);
		i++;
	}
	return (result);
}
