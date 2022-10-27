

#ifndef CHALLENGE
# define CHALLENGE
#include <stdio.h>
#include <math.h>
#define EPSILON 0.00006103515625

typedef union u_tuple
{
	struct 
	{
		double x;
		double y;
		double z;
		double w;
	}xyzw;
	struct 
	{
		double r;
		double g;
		double b;
	}rgb;
	double a[4];
} t_tuple;

typedef		t_tuple t_vector;
typedef		t_tuple t_point;
typedef		t_tuple t_color;


typedef struct s_coords
{
	size_t	row;
	size_t	col;
} t_coords;

typedef struct s_matrix
{
	double rc[4][4];
	size_t	size;
} t_matrix;

double		fabs(double x);
int			nearly_equal(double a, double b);
int			tuples_equal(t_tuple a, t_tuple b);
t_tuple		tuple_add(t_tuple u, t_tuple v);
t_tuple		tuple_sub(t_tuple u, t_tuple v);
t_point		new_point(double x, double y, double z);
t_vector	new_vector(double x, double y, double z);
t_vector	new_tuple(double x, double y, double z, double w);
t_tuple		tuple_neg(t_tuple u);
t_tuple		tuple_scalar_mult(t_tuple u, double x);
t_tuple		tuple_scalar_div(t_tuple u, double x);
double		tuple_mag(t_tuple u);
t_tuple		tuple_unit(t_tuple u);
double		vector_dot(t_tuple u, t_tuple v);
t_vector	vector_cross(t_vector u, t_vector v);
t_color		new_color(double r, double g, double b);
t_color		color_add(t_color a, t_color b);
t_color		color_sub(t_color a, t_color b);
t_color		color_scalar_multiply(t_color c, double x);
t_color		color_multiply(t_color a, t_color b);

unsigned int	rgb_to_int(unsigned char r, unsigned char g, unsigned char b);
double			clamp_float(double value, double min, double max);
int				clamp_int(int value, int min, int max);
unsigned int	color_to_int(t_color color);
t_color			int_to_color(unsigned int rgba);


t_matrix	new_matrix();
int			matrices_equal(t_matrix *a, t_matrix *b);


t_matrix	new_matrix_inc(size_t size);
t_matrix	new_matrix_inc_a(size_t size);
t_matrix	new_matrix_inc_b(size_t size);
t_matrix	new_matrix_inc_c(size_t size);



t_matrix	mm_multiply(t_matrix *a, t_matrix *b);
double		row_column_multiply(
					t_matrix *a,
					t_matrix *b,
					t_coords c);
void		print_matrix(t_matrix *mm);

t_tuple		mt_multiply(t_matrix *m, t_tuple *t);
void		matrix44_transpose(t_matrix *m); // check up
double		matrix_determinant(t_matrix *m);
// t_matrix	submatrix(t_matrix *src, int skip_row, int skip_col);
t_matrix	submatrix(t_matrix *src, t_coords c);

double		minor(t_matrix *m, int skip_row, int skip_col);
double		cofactor(t_matrix *m, int row, int col);


#endif
