

#ifndef CHALLENGE
# define CHALLENGE
#include <stdio.h>
#include <math.h>
#define EPSILON 0.00006103515625
/* 
typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
} t_tuple;
 */
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

typedef struct s_matrix44
{
	double rc[4][4];
} t_matrix44;

typedef struct s_matrix33
{
	double rc[3][3];
} t_matrix33;

typedef struct s_matrix22
{
	double rc[2][2];
} t_matrix22;

// typedef double t_matrix44[4][4];

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef		t_tuple t_vector;
typedef		t_tuple t_point;

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

t_matrix44	new_matrix44();
t_matrix33	new_matrix33();
t_matrix22	new_matrix22();
int			matrices_equal44(t_matrix44 *a, t_matrix44 *b);
int			matrices_equal33(t_matrix33 *a, t_matrix33 *b);
int			matrices_equal22(t_matrix22 *a, t_matrix22 *b);

t_matrix44	new_matrix44_inc_a();
t_matrix44	new_matrix44_inc_b();
t_matrix44	new_matrix44_inc_c();
t_matrix33	new_matrix33_inc();
t_matrix22	new_matrix22_inc();

t_matrix44	mm_multiply(t_matrix44 *a, t_matrix44 *b);
double		row_column_multiply(
					t_matrix44 *a,
					t_matrix44 *b,
					int row,
					int col);
void	print_matrix(t_matrix44 *mm);

t_tuple	mt_multiply(t_matrix44 *m, t_tuple *t);
void	matrix44_transpose(t_matrix44 *m);


#endif