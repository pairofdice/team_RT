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
	return ((t_tuple){-u.xyzw.x, -u.xyzw.y, -u.xyzw.z, -u.xyzw.w});
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
	return ((t_point){x, y, z, 1.0});
}

t_vector	new_vector(double x, double y, double z)
{
	return ((t_vector){x, y, z, 0.0});
}

t_vector	new_tuple(double x, double y, double z, double w)
{
	return ((t_tuple){x, y, z, w});
}

t_color	new_color(double r, double g, double b)
{
	return ((t_color){r, g, b});
}

t_color	color_add(t_color a, t_color b)
{
	return ((t_color){a.r + b.r, a.g + b.g, a.b + b.b});
}

t_color	color_sub(t_color a, t_color b)
{
	return ((t_color){a.r - b.r, a.g - b.g, a.b - b.b});
}

t_color	color_scalar_multiply(t_color c, double x)
{
	return ((t_color){c.r * x, c.g * x, c.b * x});
}
t_color	color_multiply(t_color a, t_color b)
{
	return ((t_color){a.r * b.r, a.g * b.g, a.b * b.b});
}

unsigned int	rgb_to_int(unsigned int r, unsigned int g, unsigned int b)
{
	return (r << 24 | g << 16 | b << 8);
}

unsigned int	color_to_int(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = (unsigned int)color.r * 255;
	g = (unsigned int)color.g * 255;
	b = (unsigned int)color.b * 255;
	return (r << 24 | g << 16 | b << 8);
}

t_color	int_to_color(unsigned int rgba)
{
	t_color	color;

	color.b = (rgba >> 8) % 256;
	color.g = (rgba >> 16) % 256;
	color.r = (rgba >> 24) % 256;
	return (color);
}

t_matrix44	new_matrix44()
{
	t_matrix44	m;
/* 	int			col;
	int			row;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			m.rc[row][col] = col + row * 4 + 1;
			row++;
		}
		col++;
	} */

	bzero(&m, sizeof(t_matrix44));
	return (m);
}

t_matrix33	new_matrix33()
{
	t_matrix33	m;

	bzero(&m, sizeof(t_matrix33));
	return (m);
}

t_matrix22	new_matrix22()
{
	t_matrix22	m;

	bzero(&m, sizeof(t_matrix22));
	return (m);
}

int		matrices_equal44(t_matrix44 *a, t_matrix44 *b)
{
	int	col;
	int	row;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			if (nearly_equal(a->rc[row][col], b->rc[row][col]) == 0)
				return (0);
			row++;
		}
		col++;
	}
	return (1);
}
int		matrices_equal33(t_matrix33 *a, t_matrix33 *b)
{
	int	col;
	int	row;

	col = 0;
	while (col < 3)
	{
		row = 0;
		while (row < 3)
		{
			if (nearly_equal(a->rc[row][col], b->rc[row][col]) == 0)
				return (0);
			row++;
		}
		col++;
	}
	return (1);
}
int		matrices_equal22(t_matrix22 *a, t_matrix22 *b)
{
	int	col;
	int	row;

	col = 0;
	while (col < 2)
	{
		row = 0;
		while (row < 2)
		{
			if (nearly_equal(a->rc[row][col], b->rc[row][col]) == 0)
				return (0);
			row++;
		}
		col++;
	}
	return (1);
}

t_matrix44	new_matrix44_inc_a()
{
	t_matrix44	m;
 	int			col;
	int			row;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			m.rc[row][col] = col + row * 4 + 1;
			row++;
		}
		col++;
	}
	return (m);
}

t_matrix44	new_matrix44_inc_b()
{
	t_matrix44	m;
 	int			col;
	int			row;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			m.rc[row][col] = col + row + 1;
			row++;
		}
		col++;
	}
	return (m);
}
t_matrix44	new_matrix44_inc_c()
{
	t_matrix44	m;
 	int			col;
	int			row;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			if (row == 0 && col == 0)
				m.rc[0][0] = 0.0;
			else
				m.rc[row][col] = pow(2, row + col - 1) ;
			row++;
		}
		col++;
	}
	return (m);
}

t_matrix33	new_matrix33_inc()
{
	t_matrix33	m;
 	int			col;
	int			row;

	col = 0;
	while (col < 3)
	{
		row = 0;
		while (row < 3)
		{
			m.rc[row][col] = col + row * 3 + 1;
			row++;
		}
		col++;
	}
	return (m);
}
t_matrix22	new_matrix22_inc()
{
	t_matrix22	m;
 	int			col;
	int			row;

	col = 0;
	while (col < 2)
	{
		row = 0;
		while (row < 2)
		{
			m.rc[row][col] = col + row * 2 + 1;
			row++;
		}
		col++;
	}
	return (m);
}

t_matrix44	new_matrix44_identity()
{
	t_matrix44	m;
 	int			col;
	int			row;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			if (row == col)
				m.rc[row][col] = 1;
			else
				m.rc[row][col] = 0;
			row++;
		}
		col++;
	}
	return (m);
}


double	row_column_multiply(
					t_matrix44 *a,
					t_matrix44 *b,
					int row,
					int col)
{
	int	i;
	double	result;

	i = 0;
	result = 0;
	while (i < 4)
	{
		result += a->rc[row][i] * b->rc[i][col];
		i++;
	}
	return (result);
}

t_matrix44	mm_multiply(t_matrix44 *a, t_matrix44 *b)
{
	int			row;
	int			col;
	t_matrix44	result;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			// DO THE THING!
			result.rc[row][col] = row_column_multiply(a, b, row, col);
			col++;
		}
		row++;
	}
	return (result);
}

void	print_matrix(t_matrix44 *mm)
{
	int row;
	int col;

	printf("    0  1  2  3\n\n");
	row = 0;
	while (row < 4) 
	{
		printf("%d: ", row);
		col = 0;
		while (col < 4)
		{
			printf("%2.0f ",mm->rc[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
	printf("\n");
}


void	print_matrix33(t_matrix33 *mm)
{
	int row;
	int col;

	printf("    0  1  2\n\n");
	row = 0;
	while (row < 3) 
	{
		printf("%d: ", row);
		col = 0;
		while (col < 3)
		{
			printf("%2.0f ",mm->rc[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
	printf("\n");
}

static double	row_multiply(t_matrix44 *m, double t[4], int row)
{
	int		col;
	double	result;

	col = 0;
	result = 0.0;
	while (col < 4)
	{
		result += m->rc[row][col] * t[col];
		col++;
	}
	printf("result: %f\n", result); 
	return (result);
}

t_tuple	mt_multiply(t_matrix44 *m, t_tuple *t)
{
	t_tuple	result;

/*
	double	temp[4];

	temp[0] = t->xyzw.x;
	temp[1] = t->xyzw.y;
	temp[2] = t->xyzw.z;
	temp[3] = t->xyzw.w;

	result.xyzw.x = row_multiply(m, temp, 0);
	result.xyzw.y = row_multiply(m, temp, 1);
	result.xyzw.z = row_multiply(m, temp, 2);
	result.xyzw.w = row_multiply(m, temp, 3);
	*/
	int	i;

	i = 0;
	while (i < 4)
	{
		result.a[i] = row_multiply(m, t->a, i);
		i++;
	}
	return (result);
}

void	matrix44_transpose(t_matrix44 *m)
{
	double	temp;
	int		row;
	int		col;

	row = 1;
	while (row < 4)
	{
		col = 0;
		while (col < row)
		{
			temp = m->rc[row][col];
			m->rc[row][col] = m->rc[col][row];
			m->rc[col][row] = temp;
			col++;
		}
		row ++;
	}
}

double	matrix22_determinant(t_matrix22 *m)
{
	return (m->rc[0][0] * m->rc[1][1] - m->rc[0][1] * m->rc[1][0]);
}

t_matrix22	submatrix33(t_matrix33 *src, int skip_row, int skip_col)
{
	int			row;
	int			col;
	int			pad_x;
	int			pad_y;
	t_matrix22	result;

	row = 0;
	pad_x = 0;
	pad_y = 0;
	while(row < 2)
	{

		if (row == skip_row)
			pad_y = 1;
		col = 0;
		while (col < 2)
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


t_matrix33	submatrix44(t_matrix44 *src, int skip_row, int skip_col)
{
	int			row;
	int			col;
	int			pad_x;
	int			pad_y;
	t_matrix33	result;

	pad_x = 0;
	pad_y = 0;
	row = 0;
	while(row < 3)
	{
		if (row == skip_row)
			pad_y = 1;
		col = 0;
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
