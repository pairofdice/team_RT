#include "challenge.h"
#include <strings.h>

#define EPSILON 0.00006103515625

double	fabs(double x)
{
	if (x >= 0.0)
		return (x);
	return (-x);
}

int nearly_equal(double a, double b)
{
	if (fabs((a - b)) < EPSILON)
		return (1);
	return (0);
}

int		tuples_equal(t_tuple a, t_tuple b)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (nearly_equal(a.a[i], b.a[i]) == 0) 
			return (0);
		i++;
	}
	return (1);
}

t_tuple	tuple_add(t_tuple u, t_tuple v)
{
	t_tuple	r;

	r.xyzw.x = u.xyzw.x + v.xyzw.x;
	r.xyzw.y = u.xyzw.y + v.xyzw.y;
	r.xyzw.z = u.xyzw.z + v.xyzw.z;
	r.xyzw.w = u.xyzw.w + v.xyzw.w;
	return (r);
}

t_tuple	tuple_sub(t_tuple u, t_tuple v)
{
	t_tuple	r;

	r.xyzw.x = u.xyzw.x - v.xyzw.x;
	r.xyzw.y = u.xyzw.y - v.xyzw.y;
	r.xyzw.z = u.xyzw.z - v.xyzw.z;
	r.xyzw.w = u.xyzw.w - v.xyzw.w;
	return (r);
}

t_tuple	tuple_neg(t_tuple u)
{
	t_tuple	r;

	r.xyzw.x = -u.xyzw.x;
	r.xyzw.y = -u.xyzw.y;
	r.xyzw.z = -u.xyzw.z;
	r.xyzw.w = -u.xyzw.w;
	return (r);
}



t_tuple	tuple_scalar_mult(t_tuple u, double x)
{
	t_tuple	r;

	r.xyzw.x = u.xyzw.x * x;
	r.xyzw.y = u.xyzw.y * x;
	r.xyzw.z = u.xyzw.z * x;
	r.xyzw.w = u.xyzw.w * x;
	return (r);
}

t_tuple	tuple_scalar_div(t_tuple u, double x)
{
	t_tuple	r;

	r.xyzw.x = u.xyzw.x / x;
	r.xyzw.y = u.xyzw.y / x;
	r.xyzw.z = u.xyzw.z / x;
	r.xyzw.w = u.xyzw.w / x;
	return (r);
}

double	tuple_mag(t_tuple u)
{
	double	r;

	r = u.xyzw.x * u.xyzw.x;
	r += u.xyzw.y * u.xyzw.y;
	r += u.xyzw.z * u.xyzw.z;
	r += u.xyzw.w * u.xyzw.w;
	return (sqrt(r));
}
	// return (sqrt(u.x * u.x + u.y * u.y + u.z * u.z));


t_tuple	tuple_unit(t_tuple u)
{
	double	mag;

	mag = tuple_mag(u);
	return (tuple_scalar_div(u, mag));
}

double	vector_dot(t_tuple u, t_tuple v)
{
	double	r;

	r = u.xyzw.x * v.xyzw.x;
	r += u.xyzw.y * v.xyzw.y;
	r += u.xyzw.z * v.xyzw.z;
	r += u.xyzw.w * v.xyzw.w;
	return (r);
}

t_vector	vector_cross(t_vector u, t_vector v)
{
	t_vector	crossed;

	crossed.xyzw.x = u.xyzw.y * v.xyzw.z - u.xyzw.z * v.xyzw.y;
	crossed.xyzw.y = u.xyzw.z * v.xyzw.x - u.xyzw.x * v.xyzw.z;
	crossed.xyzw.z = u.xyzw.x * v.xyzw.y - u.xyzw.y * v.xyzw.x;
	return (crossed);
}


t_point		new_point(double x, double y, double z)
{
	t_point	r;

	r.xyzw.x = x;
	r.xyzw.y = y;
	r.xyzw.z = z;
	r.xyzw.w = 1.0;
	return (r);
}

t_vector	new_vector(double x, double y, double z)
{
	t_vector	r;

	r.xyzw.x = x;
	r.xyzw.y = y;
	r.xyzw.z = z;
	r.xyzw.w = 0.0;
	return (r);
}

t_tuple	new_tuple(double x, double y, double z, double w)
{
	t_tuple	r;

	r.xyzw.x = x;
	r.xyzw.y = y;
	r.xyzw.z = z;
	r.xyzw.w = w;
	return (r);
}

t_color	new_color(double r, double g, double b)
{
	t_color color;

	color.rgb.r = r;
	color.rgb.g = g;
	color.rgb.b = b;
	return (color);
}

t_color	color_add(t_color a, t_color b)
{
	t_color color;

	color = tuple_add(a, b);
	return (color);
}

t_color	color_sub(t_color a, t_color b)
{
	t_color color;

	color = tuple_sub(a, b);
	return (color);
}

t_color	color_scalar_multiply(t_color c, double x)
{
	t_color color;

	color = tuple_scalar_mult(c, x);
	return (color);
}
t_color	color_multiply(t_color a, t_color b)
{
	t_color color;

	color.rgb.r = a.rgb.r * b.rgb.r;
	color.rgb.g = a.rgb.g * b.rgb.g;
	color.rgb.b = a.rgb.b * b.rgb.b;
	return (color);
}

unsigned int	rgb_to_int(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 24 | g << 16 | b << 8);
}

int	clamp_int(int value, int min, int max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

double	clamp_float(double value, double min, double max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

unsigned int	color_to_int(t_color color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)clamp_float(color.rgb.r, 0.0, 1.0) * 255;
	g = (unsigned char)clamp_float(color.rgb.g, 0.0, 1.0) * 255;
	b = (unsigned char)clamp_float(color.rgb.b, 0.0, 1.0) * 255;
	return (r << 24 | g << 16 | b << 8);
}

t_color	int_to_color(unsigned int rgba)
{
	t_color	color;

	color.rgb.b = (rgba >> 8) % 256;
	color.rgb.g = (rgba >> 16) % 256;
	color.rgb.r = (rgba >> 24) % 256;
	return (color);
}

t_matrix	new_matrix(int size)
{
	t_matrix	m;

	bzero(&m, sizeof(t_matrix));
	if (size >= 2 && size <= 4)
		m.size = size;
	else
		m.size = 4;
	return (m);
}

int		matrices_equal(t_matrix *a, t_matrix *b)
{
	t_coords	c;

	c.col = 0;
	if (a->size != b->size)
		return (0);
	while (c.col < a->size)
	{
		c.row = 0;
		while (c.row < a->size)
		{
			if (nearly_equal(a->rc[c.row][c.col], b->rc[c.row][c.col]) == 0)
				return (0);
			c.row++;
		}
		c.col++;
	}
	return (1);
}

t_matrix	new_matrix_inc_a(size_t size)
{
	t_matrix	m;
	t_coords	c;

	m = new_matrix(size);
	c.col = 0;
	while (c.col < m.size)
	{
		c.row = 0;
		while (c.row < m.size)
		{
			m.rc[c.row][c.col] = c.col + c.row * 4 + 1;
			c.row++;
		}
		c.col++;
	}
	return (m);
}
t_matrix	new_matrix_inc_b(size_t size)
{
	t_matrix	m;
	t_coords	c;

	m = new_matrix(size);
	c.col = 0;
	while (c.col < m.size)
	{
		c.row = 0;
		while (c.row < m.size)
		{
			m.rc[c.row][c.col] = c.col + c.row + 1;

			c.row++;
		}
		c.col++;
	}
	return (m);
}

t_matrix	new_matrix_inc_c(size_t size)
{
	t_matrix	m;
	t_coords	c;

	m = new_matrix(size);
	c.col = 0;
	while (c.col < m.size)
	{
		c.row = 0;
		while (c.row < m.size)
		{
			if (c.row == 0 &&c. col == 0)
				m.rc[0][0] = 0.0;
			else
				m.rc[c.row][c.col] = pow(2, c.row + c.col - 1) ;
			c.row++;
		}
		c.col++;
	}
	return (m);
}

t_matrix	new_matrix_identity(int size)
{
	t_matrix	m;
	t_coords	c;

	m = new_matrix(size);
	c.col = 0;
	while (c.col < m.size)
	{
		c.row = 0;
		while (c.row < m.size)
		{
			if (c.row == c.col)
				m.rc[c.row][c.col] = 1;
			else
				m.rc[c.row][c.col] = 0;
			c.row++;
		}
		c.col++;
	}
	return (m);
}


double	row_column_multiply(
					t_matrix *a,
					t_matrix *b,
					t_coords c)
{
	size_t	i;
	double	result;

	i = 0;
	result = 0;
	if (a->size == b->size)
	{
		while (i < a->size)
		{
			result += a->rc[c.row][i] * b->rc[i][c.col];
			i++;
		}
	}
	return (result);
}

t_matrix	mm_multiply(t_matrix *a, t_matrix *b)
{
	t_coords	c;
	t_matrix	result;

	result = new_matrix(a->size);
	c.row = 0;
	if (a->size == b->size)
	{
		while (c.row < 4)
		{
			c.col = 0;
			while (c.col < 4)
			{
				result.rc[c.row][c.col] = row_column_multiply(a, b, c);
				c.col++;
			}
			c.row++;
		}
	}
	return (result);
}

void	print_matrix(t_matrix *mm)
{
	int row;
	int col;

	printf("    0  1  2  3\n\n");
	row = 0;
	while (row < mm->size) 
	{
		printf("%d: ", row);
		col = 0;
		while (col < mm->size)
		{
			printf("%2.0f ",mm->rc[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
	printf("\n");
}

static double	row_multiply(t_matrix *m, t_tuple *t, int row)
{
	int		col;
	double	result;

	col = 0;
	result = 0.0;
	while (col < m->size)
	{
		result += m->rc[row][col] * t->a[col];
		col++;
	}
	return (result);
}

t_tuple	mt_multiply(t_matrix *m, t_tuple *t)
{
	t_tuple	result;

	int	i;

	i = 0;
	while (i < 4)
	{
		result.a[i] = row_multiply(m, t, i);
		i++;
	}
	return (result);
}

void	matrix_transpose(t_matrix *m)
{
	double		temp;
	t_coords	c;

	c.row = 1;
	while (c.row < m->size)
	{
		c.col = 0;
		while (c.col <c. row)
		{
			temp = m->rc[c.row][c.col];
			m->rc[c.row][c.col] = m->rc[c.col][c.row];
			m->rc[c.col][c.row] = temp;
			c.col++;
		}
		c.row ++;
	}
}

t_matrix	submatrix(t_matrix *src, int skip_row, int skip_col)
{
	t_coords	c;
	t_coords	padding;
	t_matrix	result;

	if (src->size == 3 || src->size == 4)
	{
		result = new_matrix(src->size - 1);
		c.row = 0;
		padding.row = 0; 
		while(c.row < result.size)
		{
			if (c.row == skip_row)
				padding.row = 1;
			c.col = 0;
				padding.col = 0;
			while (c.col < result.size)
			{
				if (c.col == skip_col)
					padding.col  = 1;
				result.rc[c.row][c.col] = src->rc[c.row + padding.row][c.col + padding.col ];
				c.col++;
			}
			c.row++;
		}
	}
	return (result);
}

/* 
t_matrix33	submatrix44(t_matrix44 *src, int skip_row, int skip_col)
{
	int			row;
	int			col;
	int			pad_x;
	int			pad_y;
	t_matrix33	result;

	row = 0;
		pad_y = 0;
	while(row < 3)
	{
		if (row == skip_row)
			pad_y = 1;
		col = 0;
			pad_x = 0;
		while (col < 3)
		{
			if (col == skip_col)
				pad_x = 1;
			result.rc[row][col] = src->rc[row + pad_y][col + pad_x];
			col++;
		}
		row++;
	}

	// printf("Calling submatrix33 with garbage\n");
	return (result);	
}
*/

double	minor33(t_matrix33 *m, int skip_row, int skip_col)
{
	t_matrix22	m22;
	double		determinant;

	m22 = submatrix33(m, skip_row, skip_col);
	determinant = matrix22_determinant(&m22);
	return (determinant);
}

double	cofactor33(t_matrix33 *m, int row, int col)
{
	double	minor;

	minor = minor33(m, row, col);
	if ((row + col) % 2 == 1)
		minor = -minor;
	return (minor);
}

/* double	cofactor44(t_matrix44 *m, int row, int col)
{
	double	minor;

	minor = minor33(m, row, col);
	if ((row + col) % 2 == 1)
		minor = -minor;
	return (minor);
}
 */

double	matrix_determinant(t_matrix *m)
{
	int	i;

	if (m->size == 2)
		return (m->rc[0][0] * m->rc[1][1] - m->rc[0][1] * m->rc[1][0]);
	if (m->size == 3)
	{
		return(
			m->rc[0][0] * matrix_determinant( submatrix(m, 0, 0) ) - 
			m->rc[0][1] * matrix_determinant( submatrix(m, 0, 1) ) +
			m->rc[0][2] * matrix_determinant( submatrix(m, 0, 2) )
		);
	}
}