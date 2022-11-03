#include "challenge.h"


void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*d1;

	d1 = dst;
	if (dst == src || n == 0)
		return (d1);
	while (n >= sizeof(long))
	{
		*(long *) d1 = *(const long *) src;
		d1 += sizeof(long);
		src += sizeof(long);
		n -= sizeof(long);
	}
	if (n >= sizeof(int))
	{
		*(int *) d1 = *(const int *) src;
		d1 += sizeof(int);
		src += sizeof(int);
		n -= sizeof(int);
	}
	while (n-- > 0)
		*(char *) d1++ = *(const char *) src++;
	return (dst);
}

void	vec_free(t_vec *src)
{
	if (!src || src->alloc_size == 0)
		return ;
	free(src->memory);
	src->memory = NULL;
	src->elem_size = 0;
	src->alloc_size = 0;
	src->len = 0;
}


int	vec_new(t_vec *src, size_t init_len, size_t elem_size)
{
	if (!src || elem_size == 0)
		return (-1);
	if (init_len == 0)
		src->memory = NULL;
	else
	{
		src->memory = (char *) malloc(init_len * elem_size);
		if (!src->memory)
			return (-1);
		ft_memset(src->memory, 0, init_len * elem_size);
	}
	src->len = 0;
	src->alloc_size = init_len * elem_size;
	src->elem_size = elem_size;
	return (1);
}

int	vec_resize(t_vec *src, size_t target_size)
{
	t_vec	resized;

	if (!src || !src->memory)
		return (-1);
	if (vec_new(&resized, target_size, src->elem_size) == -1)
		return (-1);
	ft_memcpy(resized.memory, src->memory, src->len);
	resized.len = src->len;
	vec_free(src);
	*src = resized;
	return (1);
}

int	vec_append(t_vec *dst, t_vec *src)
{
	size_t	space_needed;

	if (!dst || !src || !src->memory)
		return (-1);
	if (!dst->memory)
		vec_new(dst, 1, 1);
	space_needed = dst->len * dst->elem_size + src->len * src->elem_size;
	if (dst->alloc_size < space_needed)
	{
		if (vec_resize(dst, space_needed * 2) == -1)
			return (-1);
	}
	ft_memcpy(
		&dst->memory[dst->len * dst->elem_size],
		src->memory,
		src->len * 1);
	dst->len += src->len;
	vec_free(src);
	return (1);
}


int	vec_from(t_vec *dst, void *src, size_t len, size_t elem_size)
{
	if (!dst || !src || elem_size == 0)
		return (-1);
	if (vec_new(dst, len, elem_size) == -1)
		return (-1);
	ft_memcpy(dst->memory, src, dst->alloc_size);
	dst->len = len;
	return (1);
}

void	*vec_get(t_vec *src, size_t index)
{
	unsigned char	*ptr;

	if (index >= src->len)
		return (NULL);
	if (index >= src->len || !src || !src->memory)
		return (NULL);
	ptr = &src->memory[src->elem_size * index];
	return (ptr);
}



int	vec_push(t_vec *vec, void *elem)
{
	if (!vec || !elem)
		return (-1);
	if ((vec->len * vec->elem_size) == vec->alloc_size)
		if (vec_resize(vec, vec->len * 2) == -1)
			return (-1);
	ft_memcpy(&vec->memory[vec->len * vec->elem_size], elem, vec->elem_size);
	vec->len++;
	return (1);
}