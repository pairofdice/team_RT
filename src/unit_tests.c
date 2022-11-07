// #define NDEBUG // disable asserts


#include "object.h"

# include <assert.h>
# include "rt.h"
# include "matrix.h"

t_matrix	matrix_new_inc_a(size_t size);
t_matrix	matrix_new_inc_b(size_t size);
t_matrix	matrix_new_inc_c(size_t size);


void	test_tuples();
void	test_colors();
void	test_matrix_equal();
void	test_matrix_multiply();
void	test_matrix_transpose();
void	test_matrix_determinant();
void	test_matrix_submatrix();
void	test_matrix_minors();
void	test_matrix_determinant_large();
void	test_matrix_inversion();
void	test_matrix_translate();
void	test_matrix_scale();
void	test_matrix_rotate();
void	test_matrix_shear();
void	test_transform_chaining();
void	test_ray();
void	test_sphere_intersect();
void	test_intersection();
void	test_ray_sphere_transforms();



void	tests(void)
{
	printf("Testing tuples\n");
	test_tuples();
	printf("OK\n");
	printf("Testing colors\n");
	test_colors();
	printf("OK\n");
	printf("Testing matrix equality\n");
	test_matrix_equal();
	printf("OK\n");
	printf("Testing matrix multiply\n");
	test_matrix_multiply();
	printf("OK\n");
	printf("Testing matrix transpose\n");
	test_matrix_transpose();
	printf("OK\n");
	printf("Testing 2x2 determinant\n");
	test_matrix_determinant();
	printf("OK\n");
	printf("Testing submatrices\n");
	test_matrix_submatrix();
	printf("OK\n");
	printf("Testing minors\n");
	test_matrix_minors();
	printf("OK\n");
	printf("Testing larger determinant\n");
	test_matrix_determinant_large();
	printf("OK\n");
	printf("Testing inversions\n");
	test_matrix_inversion();
	printf("OK\n");
	printf("Testing matrix translation\n");
	test_matrix_translate();
	printf("OK\n");
	printf("Testing matrix scaling\n");
	test_matrix_scale();
	printf("OK\n");
	printf("Testing matrix rotate\n");
	test_matrix_rotate();
	printf("OK\n");
	// printf("Testing matrix shear\n");
	// test_matrix_shear();
	// printf("OK\n");
	printf("Testing transform chaining\n");
	test_transform_chaining();
	printf("OK\n");
	printf("Testing rays\n");
	test_ray();
	printf("OK\n");
	printf("Testing sphere intersection\n");
	test_sphere_intersect();
	printf("OK\n");
	printf("Testing intersection\n");
	test_intersection();
	printf("OK\n");

/* 	


	printf("Testing ray/sphere transform\n");
	test_ray_sphere_transforms();
	printf("OK\n");
*/
}

void	test_tuples()
{
	t_tuple t;
	t_tuple p = point_new(4.3, -4.2, 3.1);
	assert(p.s_xyzw.x == 4.3);
	assert(p.s_xyzw.y == -4.2);
	assert(p.s_xyzw.z == 3.1);
	assert(p.s_xyzw.w == 1.0);
	t_tuple v = vector_new(4.3, -4.2, 3.1);
	assert(v.s_xyzw.x == 4.3);
	assert(v.s_xyzw.y == -4.2);
	assert(v.s_xyzw.z == 3.1);
	assert(v.s_xyzw.w == 0.0);

	assert(fabs(-3.5) == 3.5);
	assert(fabs(6.54) == 6.54);
	assert(nearly_equal(123.456, 123.45600001) == 1);
	p = tuple_new(3.0, -2.0, 5.0, 1.0);
	v = tuple_new(-2, 3, 1, 0);
	t = tuple_add(p, v);
	assert(t.s_xyzw.x == 1);
	assert(t.s_xyzw.y == 1);
	assert(t.s_xyzw.z == 6);
	assert(t.s_xyzw.w == 1);

	//p = point_new(3, 2, 1);
	v = point_new(5, 6, 7);
	t_tuple q = tuple_new(3.0, -2.00000001, 5.0, 1.0);
	t_tuple w = tuple_new(3.0, -2.0001, 5.0, 1.0);
	assert(nearly_equal(1.1, 1.1) == 1);
	assert(nearly_equal(1.1, 1.2) == 0);
	assert(tuples_equal(p, q) == 1);
	assert(tuples_equal(p, w) == 0);

	t_point p1 = point_new(3, 2, 1);
	t_point p2 = point_new(5, 6, 7);
	t_point p3 = vector_new(-2, -4, -6);
	assert(tuples_equal(tuple_sub(p1, p2), p3));

	p = point_new(3, 2, 1);
	v = vector_new(5, 6, 7);
	t_point pv = point_new(-2, -4, -6);
	assert(tuples_equal(tuple_sub(p, v), pv));

	t_tuple v1 = point_new(3, 2, 1);
	t_tuple v2 = vector_new(5, 6, 7);
	t_point v1v2 = point_new(-2, -4, -6);
	assert(tuples_equal(tuple_sub(v1, v2), v1v2));

	t_tuple zero = vector_new(0, 0, 0);
	v = vector_new(1, -2, 3);
	t_point zero_v = vector_new(-1, 2, -3);
	assert(tuples_equal(tuple_sub(zero, v), zero_v));

	t_tuple a = tuple_new(1, -2, 3, -4);
	t_tuple a_neg = tuple_new(-1, 2, -3, 4);
	// tuple_print(a);
	// tuple_print(a_neg);
	a = tuple_neg(a);
	assert(tuples_equal(a, a_neg) == 1);

	a = tuple_new(1, -2, 3, -4);
	a = tuple_scalar_mult(a, 3.5);
	t_tuple r = tuple_new(3.5, -7, 10.5, -14);
	assert(tuples_equal(a, r));

	a = tuple_new(1, -2, 3, -4);
	a = tuple_scalar_mult(a, 0.5);
	r = tuple_new(0.5, -1, 1.5, -2);
	assert(tuples_equal(a, r));

	a = tuple_new(1, -2, 3, -4);
	a = tuple_scalar_div(a, 2.0);
	r = tuple_new(0.5, -1, 1.5, -2);
	assert(tuples_equal(a, r));

	v = vector_new(1, 0, 0);
	assert(tuple_mag(v) == 1);
	v = vector_new(0, 1, 0);
	assert(tuple_mag(v) == 1);
	v = vector_new(0, 0, 1);
	assert(tuple_mag(v) == 1);
	v = vector_new(1, 2, 3);
	assert(nearly_equal(tuple_mag(v), sqrt(14)));
	v = vector_new(-1, -2, -3);
	assert(nearly_equal(tuple_mag(v), sqrt(14)));

	v = vector_new(4, 0, 0);
	v = tuple_unit(v);
	r = vector_new(1, 0, 0);
	assert(tuples_equal(v, r));

	v = vector_new(1, 2, 3);
	v = tuple_unit(v);
	r = vector_new(0.26726, 0.53452, 0.80178);
	assert(tuples_equal(v, r));

	v = vector_new(1, 2, 3);
	v = tuple_unit(v);
	r = vector_new(0.26726, 0.53452, 0.80178);
	assert(tuples_equal(v, r));

	v1 = vector_new(1, 2, 3);
	v2 = vector_new(2, 3, 4);
	double dot = vector_dot(v1, v2);
	assert(nearly_equal(dot, 20));

	v1 = vector_new(1, 2, 3);
	v2 = vector_new(1, 5, 7);
	dot = vector_dot(v1, v2);
	assert(nearly_equal(dot, 32));

	v1 = vector_new(-8, 2, 3);
	v2 = vector_new(1, -5, 7);
	dot = vector_dot(v1, v2);
	assert(nearly_equal(dot, 3));

	v1 = vector_new(1, 2, 3);
	v2 = vector_new(2, 3, 4);
	r =  vector_new(-1, 2, -1);
	t_vector cross = vector_cross(v1, v2);
	r =  vector_new(1, -2, 1);
	cross = vector_cross(v2, v1);

	// tuple_print(cross);
	// tuple_print(r);
	assert(tuples_equal(cross, r));
}

void	test_colors()
{
	t_color c1 = color_new(0.9, 0.6, 0.75);
	t_color c2 = color_new(0.7, 0.1, 0.25);
	t_color c1c2 = tuple_add(c1, c2);
	t_color should_be = color_new(1.6, 0.7, 1.0);
	assert(nearly_equal(c1c2.s_rgb.r, should_be.s_rgb.r));
	assert(nearly_equal(c1c2.s_rgb.g, should_be.s_rgb.g));
	assert(nearly_equal(c1c2.s_rgb.b, should_be.s_rgb.b));

	c1 = color_new(0.9, 0.6, 0.75);
	c2 = color_new(0.7, 0.1, 0.25);
	c1c2 = tuple_sub(c1, c2);
	should_be = color_new(0.2, 0.5, 0.5);
	assert(nearly_equal(c1c2.s_rgb.r, should_be.s_rgb.r));
	assert(nearly_equal(c1c2.s_rgb.g, should_be.s_rgb.g));
	assert(nearly_equal(c1c2.s_rgb.b, should_be.s_rgb.b));

	c1 = color_new(0.2, 0.3, 0.4);
	c1 = tuple_scalar_mult(c1, 2.0);
	should_be = color_new(0.4, 0.6, 0.8);
	assert(nearly_equal(c1.s_rgb.r, should_be.s_rgb.r));
	assert(nearly_equal(c1.s_rgb.g, should_be.s_rgb.g));
	assert(nearly_equal(c1.s_rgb.b, should_be.s_rgb.b));

	c1 = color_new(1, 0.2, 0.4);
	c2 = color_new(0.9, 1, 0.1);
	c1c2 = color_multiply(c1, c2);
	should_be = color_new(0.9, 0.2, 0.04);
	assert(nearly_equal(c1c2.s_rgb.r, should_be.s_rgb.r));
	assert(nearly_equal(c1c2.s_rgb.g, should_be.s_rgb.g));
	assert(nearly_equal(c1c2.s_rgb.b, should_be.s_rgb.b));


// unsigned int	rgb_to_int(unsigned char r, unsigned char g, unsigned char b);
// double			clamp(double value, double min, double max);
// unsigned int	color_to_int(t_color color);

	int r = -234234;
	int g = 3204929;
	int b = 123;

	r = int_clamp(r, 0, 255);
	g = int_clamp(g, 0, 255);
	b = int_clamp(b, 0, 255);

	assert(r == 0);
	assert(g == 255);
	assert(b == 123);

	double rd = -0.5;
	double gd = 320.4929;
	double bd = 123.0;

	rd = float_clamp(rd, 0.0, 255.0);
	gd = float_clamp(gd, 0.0, 255.0);
	bd = float_clamp(bd, 0.0, 255.0);

	assert(nearly_equal(rd, 0.0) == 1);
	assert(nearly_equal(gd, 255.0) == 1);
	assert(nearly_equal(bd, 123.0) == 1);

// color_to_int
	t_color clr;
	clr.s_rgb.r = 1.0;
	clr.s_rgb.g = 1.0;
	clr.s_rgb.b = 1.0;
	int color_ref = 0xFFFFFF00;
	int color = color_to_int(clr);
	assert(color == color_ref);

	clr.s_rgb.r = 0.0;
	clr.s_rgb.g = 0.0;
	clr.s_rgb.b = 0.0;
	color_ref = 0x00000000;
	color = color_to_int(clr);
	assert(color == color_ref);

	clr.s_rgb.r = -10.0;
	clr.s_rgb.g = -20.0;
	clr.s_rgb.b = 1232130.0;
	color_ref = 0x0000FF00;
	color = color_to_int(clr);
	assert(color == color_ref);

// int_to_color

	color = 0x00000000;
	clr.s_rgb.r = 0.0;
	clr.s_rgb.g = 0.0;
	clr.s_rgb.b = 0.0;

	t_color color_test = int_to_color(color);
	assert(tuples_equal(clr, color_test));

}

void	test_matrix_equal()
{
	// t_matrix44 mm = matrix_new44_inc_a();
	// matrix_print(&mm);

	// printf("aa:\n");
	// t_matrix44 aa = matrix_new44_inc_b();
	// matrix_print(&aa);

	// printf("bb:\n");
	// t_matrix44 bb = matrix_new44_inc_c();
	// matrix_print(&bb);


	// printf("[0][0] - %f\n",mm.rc[0][0]);
	// printf("[0][3] - %f\n",mm.rc[0][3]);
	// printf("[1][0] - %f\n",mm.rc[1][0]);
	// printf("[1][2] - %f\n",mm.rc[1][2]);
	// printf("[2][2] - %f\n",mm.rc[2][2]);
	// printf("[3][0] - %f\n",mm.rc[3][0]);
	// printf("[3][2] - %f\n",mm.rc[3][2]);


	t_matrix m1 = matrix_new_inc_a(2);
	t_matrix m2 = matrix_new_inc_a(2);
	assert(matrix_equals(&m1, &m2));
	m2.rc[1][1] = 454545.9;
	assert(matrix_equals(&m1, &m2) == 0);


	t_matrix m3 = matrix_new_inc_a(3);
	t_matrix m4 = matrix_new_inc_a(3);
	assert(matrix_equals(&m3, &m4));
	m4.rc[1][1] = 454545.9;
	assert(matrix_equals(&m3, &m4) == 0);

	t_matrix m5 = matrix_new_inc_a(4);
	t_matrix m6 = matrix_new_inc_a(4);
	assert(matrix_equals(&m5, &m6));
	m6.rc[1][1] = 454545.9;
	assert(matrix_equals(&m5, &m6) == 0);

}

void	test_matrix_multiply()
{
	t_matrix mm = matrix_new_inc_a(4);
	// matrix_print(&mm);
	// printf("aa:\n");
	t_matrix aa = matrix_new_inc_b(4);
	// matrix_print(&aa);
	// printf("bb:\n");
	t_matrix bb = matrix_new_inc_c(4);
	t_matrix cc = matrix_multiply(&aa, &bb);
	// printf("cc:\n");
	// matrix_print(&cc);
	// printf("[1][2] - %f\n",cc.rc[1][0]);
 	// printf("[2][2] - %f\n",cc.rc[2][2]);
	// printf("[3][0] - %f\n",cc.rc[3][0]);
	// printf("[3][2] - %f\n",cc.rc[3][2]);

	assert(nearly_equal(cc.rc[0][0], 24.0) == 1);
	assert(nearly_equal(cc.rc[1][1], 64.0) == 1);
	assert(nearly_equal(cc.rc[2][2], 158.0) == 1);
	assert(nearly_equal(cc.rc[3][3], 376.0) == 1);
	assert(nearly_equal(cc.rc[1][0], 31.0) == 1);
	assert(nearly_equal(cc.rc[2][0], 38.0) == 1);
	assert(nearly_equal(cc.rc[3][0], 45.0) == 1);
	assert(nearly_equal(cc.rc[0][1], 49.0) == 1);
	assert(nearly_equal(cc.rc[0][2], 98.0) == 1);
	assert(nearly_equal(cc.rc[0][3], 196.0) == 1);

	mm.rc[0][0] = 1.0;
	mm.rc[0][1] = 2.0;
	mm.rc[0][2] = 3.0;
	mm.rc[0][3] = 4.0;

	mm.rc[1][0] = 2.0;
	mm.rc[1][1] = 4.0;
	mm.rc[1][2] = 4.0;
	mm.rc[1][3] = 2.0;

	mm.rc[2][0] = 8.0;
	mm.rc[2][1] = 6.0;
	mm.rc[2][2] = 4.0;
	mm.rc[2][3] = 1.0;

	mm.rc[3][0] = 0.0;
	mm.rc[3][1] = 0.0;
	mm.rc[3][2] = 0.0;
	mm.rc[3][3] = 1.0;

	// matrix_print(&mm);

	t_tuple a = tuple_new(1.0, 2.0, 3.0, 1.0);

	t_tuple res = matrix_tuple_multiply(&mm, &a);
	t_tuple res_should = tuple_new(18.0, 24.0, 33.0, 1.0);
	// printf("x %f, y %f, z %f, w %f\n", res.s_xyzw.x, res.s_xyzw.y, res.s_xyzw.z, res.s_xyzw.w);
	assert(tuples_equal(res, res_should));
}

void	test_matrix_transpose()
{

	t_matrix mm = matrix_new_inc_a(4);

	mm = matrix_new_inc_a(4);

	// printf("mm\n");
	// matrix_print(&mm);


	t_matrix	transposed_should_be = matrix_new(4);
	matrix_transpose(&mm);
	// printf("mm transposed\n");
	// matrix_print(&mm);

	transposed_should_be.rc[0][0] = 1.0;
	transposed_should_be.rc[0][1] = 5.0;
	transposed_should_be.rc[0][2] = 9.0;
	transposed_should_be.rc[0][3] = 13.0;

	transposed_should_be.rc[1][0] = 2.0;
	transposed_should_be.rc[1][1] = 6.0;
	transposed_should_be.rc[1][2] = 10.0;
	transposed_should_be.rc[1][3] = 14.0;

	transposed_should_be.rc[2][0] = 3.0;
	transposed_should_be.rc[2][1] = 7.0;
	transposed_should_be.rc[2][2] = 11.0;
	transposed_should_be.rc[2][3] = 15.0;

	transposed_should_be.rc[3][0] = 4.0;
	transposed_should_be.rc[3][1] = 8.0;
	transposed_should_be.rc[3][2] = 12.0;
	transposed_should_be.rc[3][3] = 16.0;

	// printf("should be\n");
	// matrix_print(&transposed_should_be);

	assert(matrix_equals(&mm, &transposed_should_be));
}

void	test_matrix_determinant()
{
	// printf("1\n");
	t_matrix m22;
	m22 = matrix_new(2);

	m22.rc[0][0] = 1.0;
	m22.rc[0][1] = 5.0;
	m22.rc[1][0] = -3.0;
	m22.rc[1][1] = 2.0;

	// printf("2\n");
	double determinant = matrix_determinant(&m22);
	assert(nearly_equal(determinant, 17.0));
	m22.rc[0][0] = -33.0;
	m22.rc[0][1] = 42.0;
	m22.rc[1][0] = 11.0;
	m22.rc[1][1] = 1.0;

	// printf("3\n");
	determinant = matrix_determinant(&m22);
	assert(nearly_equal(determinant, -495.0));
}

void	test_matrix_submatrix()
{

	t_matrix m33;

	m33 = matrix_new(3);

	m33.rc[0][0] = 1.0;
	m33.rc[0][1] = 5.0;
	m33.rc[0][2] = 0.0;

	m33.rc[1][0] = -3.0;
	m33.rc[1][1] = 2.0;
	m33.rc[1][2] = 7.0;

	m33.rc[2][0] = 0.0;
	m33.rc[2][1] = 6.0;
	m33.rc[2][2] = -3.0;
	// matrix_print(&m33);

	t_matrix m22sm = matrix_submatrix(&m33, (t_coords){0, 0});
	// matrix_print(&m22sm);
	// printf("m22 %2.0f %2.0f\n", m22sm.rc[0][0], m22sm.rc[0][1]);
	// printf("m22 %2.0f %2.0f\n\n", m22sm.rc[1][0], m22sm.rc[1][1]);
	assert(nearly_equal(m22sm.rc[0][0], 2.0));
	assert(nearly_equal(m22sm.rc[0][1], 7.0));
	assert(nearly_equal(m22sm.rc[1][0], 6.0));
	assert(nearly_equal(m22sm.rc[1][1], -3.0));

	m22sm = matrix_submatrix(&m33, (t_coords){1, 0});
	assert(nearly_equal(m22sm.rc[0][0], 5.0));
	assert(nearly_equal(m22sm.rc[0][1], 0.0));
	assert(nearly_equal(m22sm.rc[1][0], 6.0));
	assert(nearly_equal(m22sm.rc[1][1], -3.0));

	m22sm = matrix_submatrix(&m33, (t_coords){2, 0});
	assert(nearly_equal(m22sm.rc[0][0], 5.0));
	assert(nearly_equal(m22sm.rc[0][1], 0.0));
	assert(nearly_equal(m22sm.rc[1][0], 2.0));
	assert(nearly_equal(m22sm.rc[1][1], 7.0));

	m22sm = matrix_submatrix(&m33, (t_coords){0, 1});
	assert(nearly_equal(m22sm.rc[0][0], -3.0));
	assert(nearly_equal(m22sm.rc[0][1], 7.0));
	assert(nearly_equal(m22sm.rc[1][0], 0.0));
	assert(nearly_equal(m22sm.rc[1][1], -3.0));

	m22sm = matrix_submatrix(&m33, (t_coords){0, 2});
	assert(nearly_equal(m22sm.rc[0][0], -3.0));
	assert(nearly_equal(m22sm.rc[0][1], 2.0));
	assert(nearly_equal(m22sm.rc[1][0], 0.0));
	assert(nearly_equal(m22sm.rc[1][1], 6.0));

	m22sm = matrix_submatrix(&m33, (t_coords){1, 1});
	assert(nearly_equal(m22sm.rc[0][0], 1.0));
	assert(nearly_equal(m22sm.rc[0][1], 0.0));
	assert(nearly_equal(m22sm.rc[1][0], 0.0));
	assert(nearly_equal(m22sm.rc[1][1], -3.0));

	m22sm = matrix_submatrix(&m33, (t_coords){2, 1});
	assert(nearly_equal(m22sm.rc[0][0], 1.0));
	assert(nearly_equal(m22sm.rc[0][1], 0.0));
	assert(nearly_equal(m22sm.rc[1][0], -3.0));
	assert(nearly_equal(m22sm.rc[1][1], 7.0));

	m22sm = matrix_submatrix(&m33, (t_coords){1, 2});
	assert(nearly_equal(m22sm.rc[0][0], 1.0));
	assert(nearly_equal(m22sm.rc[0][1], 5.0));
	assert(nearly_equal(m22sm.rc[1][0], 0.0));
	assert(nearly_equal(m22sm.rc[1][1], 6.0));

	m22sm = matrix_submatrix(&m33, (t_coords){2, 2});
	assert(nearly_equal(m22sm.rc[0][0], 1.0));
	assert(nearly_equal(m22sm.rc[0][1], 5.0));
	assert(nearly_equal(m22sm.rc[1][0], -3.0));
	assert(nearly_equal(m22sm.rc[1][1], 2.0));

	t_matrix m44;

	m44 = matrix_new(4);

	m44.rc[0][0] = -6.0;
	m44.rc[0][1] = 1.0;
	m44.rc[0][2] = 1.0;
	m44.rc[0][3] = 6.0;

	m44.rc[1][0] = -8.0;
	m44.rc[1][1] = 5.0;
	m44.rc[1][2] = 8.0;
	m44.rc[1][3] = 6.0;

	m44.rc[2][0] = -1.0;
	m44.rc[2][1] = 0.0;
	m44.rc[2][2] = 8.0;
	m44.rc[2][3] = 2.0;

	m44.rc[3][0] = -7.0;
	m44.rc[3][1] = 1.0;
	m44.rc[3][2] = -1.0;
	m44.rc[3][3] = 1.0;

	// matrix_print(&m44);

	t_matrix	m33_b = matrix_new_inc_a(3);

	m33_b =matrix_submatrix(&m44, (t_coords){0, 1});
	// matrix_print(&m33_b);

 	// printf("m33 %2.0f %2.0f %2.0f\n", m33.rc[0][0], m33.rc[0][1],  m33.rc[0][2]);
	// printf("m33 %2.0f %2.0f %2.0f\n", m33.rc[1][0], m33.rc[1][1],  m33.rc[1][2]);
	// printf("m33 %2.0f %2.0f %2.0f\n", m33.rc[2][0], m33.rc[2][1],  m33.rc[2][2]); 

}

void	test_matrix_minors()
{

	t_matrix	m33m = matrix_new(3);
	double		minor_result;
	double		cofact;

	m33m.rc[0][0] = 3.0;
	m33m.rc[0][1] = 5.0;
	m33m.rc[0][2] = 0.0;

	m33m.rc[1][0] = 2.0;
	m33m.rc[1][1] = -1.0;
	m33m.rc[1][2] = -7.0;

	m33m.rc[2][0] = 6.0;
	m33m.rc[2][1] = -1.0;
	m33m.rc[2][2] = 5.0;


	assert(nearly_equal(m33m.rc[0][0], 3.0));
	assert(nearly_equal(m33m.rc[1][0], 2.0));
	assert(nearly_equal(m33m.rc[2][0], 6.0));
	assert(nearly_equal(m33m.rc[2][2], 5.0));
	minor_result = matrix_minor(&m33m, 0, 0);
	cofact = matrix_cofactor(&m33m, 0, 0);

	assert(nearly_equal(minor_result, -12));
	assert(nearly_equal(cofact, -12));

	minor_result = matrix_minor(&m33m, 1, 0);
	cofact = matrix_cofactor(&m33m, 1, 0);
	assert(nearly_equal(minor_result, 25));
	assert(nearly_equal(cofact, -25));

	m33m.rc[0][0] = 1.0;
	m33m.rc[0][1] = 2.0;
	m33m.rc[0][2] = 6.0;
	m33m.rc[1][0] = -5.0;
	m33m.rc[1][1] = 8.0;
	m33m.rc[1][2] = -4.0;
	m33m.rc[2][0] = 2.0;
	m33m.rc[2][1] = 6.0;
	m33m.rc[2][2] = 4.0;

	cofact = matrix_cofactor(&m33m, 0, 0);
	assert(nearly_equal(cofact, 56.0));

	cofact = matrix_cofactor(&m33m, 0, 1);
	assert(nearly_equal(cofact, 12.0));

	cofact = matrix_cofactor(&m33m, 0, 2);
	assert(nearly_equal(cofact, -46.0));

}

void	test_matrix_determinant_large()
{
 	t_matrix	m33m = matrix_new(3);
	double		minorr;
	double		cofactr;

	m33m.rc[0][0] = 3.0;
	m33m.rc[0][1] = 5.0;
	m33m.rc[0][2] = 0.0;

	m33m.rc[1][0] = 2.0;
	m33m.rc[1][1] = -1.0;
	m33m.rc[1][2] = -7.0;

	m33m.rc[2][0] = 6.0;
	m33m.rc[2][1] = -1.0;
	m33m.rc[2][2] = 5.0;


	assert(nearly_equal(m33m.rc[0][0], 3.0));
	assert(nearly_equal(m33m.rc[1][0], 2.0));
	assert(nearly_equal(m33m.rc[2][0], 6.0));
	assert(nearly_equal(m33m.rc[2][2], 5.0));
	minorr =matrix_minor(&m33m, 0, 0);
	cofactr =matrix_cofactor(&m33m, 0, 0);

	assert(nearly_equal(minorr, -12));
	assert(nearly_equal(cofactr, -12));

	minorr =matrix_minor(&m33m, 1, 0);
	cofactr =matrix_cofactor(&m33m, 1, 0);
	assert(nearly_equal(minorr, 25));
	assert(nearly_equal(cofactr, -25));

	m33m.rc[0][0] = 1.0;
	m33m.rc[0][1] = 2.0;
	m33m.rc[0][2] = 6.0;

	m33m.rc[1][0] = -5.0;
	m33m.rc[1][1] = 8.0;
	m33m.rc[1][2] = -4.0;

	m33m.rc[2][0] = 2.0;
	m33m.rc[2][1] = 6.0;
	m33m.rc[2][2] = 4.0;

	cofactr =matrix_cofactor(&m33m, 0, 0);
	assert(nearly_equal(cofactr, 56.0));

	cofactr =matrix_cofactor(&m33m, 0, 1);
	assert(nearly_equal(cofactr, 12.0));

	cofactr =matrix_cofactor(&m33m, 0, 2);
	assert(nearly_equal(cofactr, -46.0));


	double determinantr = matrix_determinant(&m33m);
	assert(nearly_equal(determinantr, -196));


	t_matrix	m44 = matrix_new(4);


	m44.rc[0][0] = -2.0;
	m44.rc[0][1] = -8.0;
	m44.rc[0][2] = 3.0;
	m44.rc[0][3] = 5.0;

	m44.rc[1][0] = -3.0;
	m44.rc[1][1] = 1.0;
	m44.rc[1][2] = 7.0;
	m44.rc[1][3] = 3.0;

	m44.rc[2][0] = 1.0;
	m44.rc[2][1] = 2.0;
	m44.rc[2][2] = -9.0;
	m44.rc[2][3] = 6.0;

	m44.rc[3][0] = -6.0;
	m44.rc[3][1] = 7.0;
	m44.rc[3][2] = 7.0;
	m44.rc[3][3] = -9.0;
 
	// cofac
	cofactr = matrix_cofactor(&m44, 0, 0);
	assert(nearly_equal(cofactr, 690));

	cofactr = matrix_cofactor(&m44, 0, 1);
	assert(nearly_equal(cofactr, 447));

	cofactr = matrix_cofactor(&m44, 0, 2);
	assert(nearly_equal(cofactr, 210));

	cofactr = matrix_cofactor(&m44, 0, 3);
	assert(nearly_equal(cofactr, 51));

	determinantr =  matrix_determinant(&m44);
	assert(nearly_equal(determinantr, -4071));

}

void	test_matrix_inversion()
{
	
	t_matrix invertible = matrix_new(4);
	t_matrix non_invertible = matrix_new(4);


	invertible.rc[0][0] = 6.0;
	invertible.rc[0][1] = 4.0;
	invertible.rc[0][2] = 4.0;
	invertible.rc[0][3] = 4.0;

	invertible.rc[1][0] = 5.0;
	invertible.rc[1][1] = 5.0;
	invertible.rc[1][2] = 7.0;
	invertible.rc[1][3] = 6.0;

	invertible.rc[2][0] = 4.0;
	invertible.rc[2][1] = -9.0;
	invertible.rc[2][2] = 3.0;
	invertible.rc[2][3] = -7.0;
	
	invertible.rc[3][0] = 9.0;
	invertible.rc[3][1] = 1.0;
	invertible.rc[3][2] = 7.0;
	invertible.rc[3][3] = -6.0;

	double det;

	det = matrix_determinant(&invertible);
	assert(nearly_equal(det, -2120));

	non_invertible.rc[0][0] = -4.0;
	non_invertible.rc[0][1] = 2.0;
	non_invertible.rc[0][2] = -2.0;
	non_invertible.rc[0][3] = -3.0;

	non_invertible.rc[1][0] = 9.0;
	non_invertible.rc[1][1] = 6.0;
	non_invertible.rc[1][2] = 2.0;
	non_invertible.rc[1][3] = 6.0;

	non_invertible.rc[2][0] = 0.0;
	non_invertible.rc[2][1] = -5.0;
	non_invertible.rc[2][2] = 1.0;
	non_invertible.rc[2][3] = -5.0;

	non_invertible.rc[3][0] = 0.0;
	non_invertible.rc[3][1] = 0.0;
	non_invertible.rc[3][2] = 0.0;
	non_invertible.rc[3][3] = 0.0;
	

	det = matrix_determinant(&non_invertible);
	assert(nearly_equal(det, 0.0));

	t_matrix A = matrix_new(4);

	A.rc[0][0] = -5.0;
	A.rc[0][1] = 2.0;
	A.rc[0][2] = 6.0;
	A.rc[0][3] = -8.0;

	A.rc[1][0] = 1.0;
	A.rc[1][1] = -5.0;
	A.rc[1][2] = 1.0;
	A.rc[1][3] = 8.0;

	A.rc[2][0] = 7.0;
	A.rc[2][1] = 7.0;
	A.rc[2][2] = -6.0;
	A.rc[2][3] = -7.0;

	A.rc[3][0] = 1.0;
	A.rc[3][1] = -3.0;
	A.rc[3][2] = 7.0;
	A.rc[3][3] = 4.0;

	t_matrix B = matrix_new(4);
	B = matrix_inverse(&A);
	det = matrix_determinant(&A);
	assert(nearly_equal(532, det));
	double	cofactr =matrix_cofactor(&A, 2, 3);
	assert(nearly_equal(cofactr, -160));
	assert(nearly_equal(B.rc[3][2], -160.0/532.0));

	cofactr =matrix_cofactor(&A, 3, 2);
	assert(nearly_equal(cofactr, 105));
	// printf("105.0/532.0 = %f\n", 105.0/532.0);
	// printf("B.rc[3][2] = %f\n", B.rc[3][2]);
	assert(nearly_equal(B.rc[2][3], 105.0/532.0));

	t_matrix B_should_be = matrix_new(4);

	B_should_be.rc[0][0] = 0.21805;
	B_should_be.rc[0][1] = 0.45113;
	B_should_be.rc[0][2] = 0.24060;
	B_should_be.rc[0][3] = -0.04511;

	B_should_be.rc[1][0] = -0.80827;
	B_should_be.rc[1][1] = -1.45677;
	B_should_be.rc[1][2] = -0.44361;
	B_should_be.rc[1][3] = 0.52068;

	B_should_be.rc[2][0] = -0.07895;
	B_should_be.rc[2][1] = -0.22368;
	B_should_be.rc[2][2] = -0.05263;
	B_should_be.rc[2][3] = 0.19737;

	B_should_be.rc[3][0] = -0.52256;
	B_should_be.rc[3][1] = -0.81391;
	B_should_be.rc[3][2] = -0.30075;
	B_should_be.rc[3][3] = 0.30639;

	assert(matrix_equals(&B, &B_should_be));
	// matrix_print(&B_should_be);
	// matrix_print(&B);

	A.rc[0][0] = 8.0;
	A.rc[0][1] = -5.0;
	A.rc[0][2] = 9.0;
	A.rc[0][3] = 2.0;

	A.rc[1][0] = 7.0;
	A.rc[1][1] = 5.0;
	A.rc[1][2] = 6.0;
	A.rc[1][3] = 1.0;

	A.rc[2][0] = -6.0;
	A.rc[2][1] = 0.0;
	A.rc[2][2] = 9.0;
	A.rc[2][3] = 6.0;

	A.rc[3][0] = -3.0;
	A.rc[3][1] = 0.0;
	A.rc[3][2] = -9.0;
	A.rc[3][3] = -4.0;

	t_matrix	A_inverted_should_be = matrix_new(4);

	A_inverted_should_be.rc[0][0] = -0.15385;
	A_inverted_should_be.rc[0][1] = -0.15385;
	A_inverted_should_be.rc[0][2] = -0.28205;
	A_inverted_should_be.rc[0][3] = -0.53846;
	A_inverted_should_be.rc[1][0] = -0.07692;
	A_inverted_should_be.rc[1][1] = 0.12308;
	A_inverted_should_be.rc[1][2] = 0.02564;
	A_inverted_should_be.rc[1][3] = 0.03077;
	A_inverted_should_be.rc[2][0] = 0.35897;
	A_inverted_should_be.rc[2][1] = 0.35897;
	A_inverted_should_be.rc[2][2] = 0.43590;
	A_inverted_should_be.rc[2][3] = 0.92308;
	A_inverted_should_be.rc[3][0] = -0.69231;
	A_inverted_should_be.rc[3][1] = -0.69231;
	A_inverted_should_be.rc[3][2] = -0.76923;
	A_inverted_should_be.rc[3][3] = -1.92308;

	B = matrix_inverse(&A);

	assert(matrix_equals(&B, &A_inverted_should_be));


	// ---------

	A.rc[0][0] = 9.0;
	A.rc[0][1] = 3.0;
	A.rc[0][2] = 0.0;
	A.rc[0][3] = 9.0;

	A.rc[1][0] = -5.0;
	A.rc[1][1] = -2.0;
	A.rc[1][2] = -6.0;
	A.rc[1][3] = -3.0;

	A.rc[2][0] = -4.0;
	A.rc[2][1] = 9.0;
	A.rc[2][2] = 6.0;
	A.rc[2][3] = 4.0;

	A.rc[3][0] = -7.0;
	A.rc[3][1] = 6.0;
	A.rc[3][2] = 6.0;
	A.rc[3][3] = 2.0;


	A_inverted_should_be.rc[0][0] = -0.04074;
	A_inverted_should_be.rc[0][1] = -0.07778;
	A_inverted_should_be.rc[0][2] = 0.14444;
	A_inverted_should_be.rc[0][3] = -0.22222;

	A_inverted_should_be.rc[1][0] = -0.07778;
	A_inverted_should_be.rc[1][1] = 0.03333;
	A_inverted_should_be.rc[1][2] = 0.36667;
	A_inverted_should_be.rc[1][3] = -0.33333;

	A_inverted_should_be.rc[2][0] = -0.02901;
	A_inverted_should_be.rc[2][1] = -0.14630;
	A_inverted_should_be.rc[2][2] = -0.10926;
	A_inverted_should_be.rc[2][3] = 0.12963;

	A_inverted_should_be.rc[3][0] = 0.17778;
	A_inverted_should_be.rc[3][1] = 0.06667;
	A_inverted_should_be.rc[3][2] = -0.26667;
	A_inverted_should_be.rc[3][3] = 0.33333;

	A = matrix_inverse(&A);

	// matrix_print(&A);
	// matrix_print(&A_inverted_should_be);
	assert(matrix_equals(&A,&A_inverted_should_be));
	
	
	//========

	A.rc[0][0] = 3.0;
	A.rc[0][1] = -9.0;
	A.rc[0][2] = 7.0;
	A.rc[0][3] = 3.0;

	A.rc[1][0] = 3.0;
	A.rc[1][1] = -8.0;
	A.rc[1][2] = 2.0;
	A.rc[1][3] = -9.0;

	A.rc[2][0] = -4.0;
	A.rc[2][1] = 4.0;
	A.rc[2][2] = 4.0;
	A.rc[2][3] = 1.0;

	A.rc[3][0] = -6.0;
	A.rc[3][1] = 5.0;
	A.rc[3][2] = -1.0;
	A.rc[3][3] = 1.0;

//-
	B.rc[0][0] = 8.0;
	B.rc[0][1] = 2.0;
	B.rc[0][2] = 2.0;
	B.rc[0][3] = 2.0;

	B.rc[1][0] = 3.0;
	B.rc[1][1] = -1.0;
	B.rc[1][2] = 7.0;
	B.rc[1][3] = 0.0;

	B.rc[2][0] = 0.0;
	B.rc[2][1] = 0.0;
	B.rc[2][2] = 5.0;
	B.rc[2][3] = 4.0;

	B.rc[3][0] = 6.0;
	B.rc[3][1] = -2.0;
	B.rc[3][2] = 0.0;
	B.rc[3][3] = 5.0;

	t_matrix C = matrix_multiply(&A, &B);
	t_matrix inv_B = matrix_inverse(&B);
	t_matrix C_mult_invB = matrix_multiply(&C, &inv_B);

	// matrix_print(&C_mult_invB);
	// matrix_print(&A);

	assert(matrix_equals(&C_mult_invB, &A));
}

void	test_matrix_translate()
{
	t_point point_A = point_new(-3, 4, 5);
	t_matrix	transform = matrix_translate(5, -3, 2);
	t_point	point_B  = point_new(2, 1, 7);
	t_point	A_translated = matrix_tuple_multiply(&transform, &point_A);
	// tuple_print(A_translated);
	// tuple_print(point_B);
	assert(tuples_equal(A_translated, point_B));


	transform = matrix_translate(5, -3, 2);
	t_matrix	inv_transform = matrix_inverse(&transform);

	point_A = point_new(-3, 4, 5);
	point_B  = point_new(-8, 7, 3);
	t_tuple B_inv = matrix_tuple_multiply(&inv_transform, &point_A);
	// tuple_print(B_inv);
	// tuple_print(point_B);
	assert(tuples_equal(B_inv, point_B));
	printf("- Translation does not affect vectors\n");
	transform = matrix_translate(5, -3, 2);
	t_vector vec = vector_new(-3, 4, 5);
	vec = matrix_tuple_multiply(&transform, &vec);
	t_vector not_transformed = vector_new(-3, 4, 5);
	assert(tuples_equal(vec, not_transformed));

}

void	test_matrix_scale()
{
	t_matrix	transform = matrix_scale(2, 3, 4);

	t_point p = point_new(-4, 6, 8);

	t_point	result  = point_new(-8, 18, 32);
	t_point	A_translated = matrix_tuple_multiply(&transform, &p);
	// tuple_print(A_translated);
	// tuple_print(result);
	assert(tuples_equal(A_translated, result));
	// OK

	t_vector vec = vector_new(-4, 6, 8);
	t_vector vec_result = vector_new(-8, 18, 32);

	vec = matrix_tuple_multiply(&transform, &vec);
	printf("- Scaling does affect vectors\n");

	// tuple_print(vec);
	// tuple_print(vec_result);
	assert(tuples_equal(vec, vec_result));

	printf("- multiplying a tuple by the inverse of a scaling matrix will scale the tuple in the opposite way\n");

	vec = vector_new(-4, 6, 8);
	transform = matrix_scale(2, 3, 4);
	t_matrix inv_transform = matrix_inverse(&transform);
	t_vector vec_inverted = matrix_tuple_multiply(&inv_transform, &vec);
	t_vector v_should_be = vector_new(-2, 2, 2);
	// tuple_print(vec_inverted);
	// tuple_print(v_should_be);
	assert(tuples_equal(vec_inverted, v_should_be));


	printf("- Reflection is essentially the same thing as scaling by a negative value.\n");

	transform = matrix_scale(-1, 1, 1);
	p = point_new(2, 3, 4);
	t_point p_should_be = point_new(-2, 3, 4);
	result = matrix_tuple_multiply(&transform, &p);
	// tuple_print(result);
	// tuple_print(p_should_be);
	assert(tuples_equal(result, p_should_be));

}

void	test_matrix_rotate()
{
	/// x
	t_tuple		p = point_new(0, 1, 0);
	t_matrix	rotate_half_quarter = matrix_rotate_x(M_PI_4);
	t_matrix	rotate_full_quarter = matrix_rotate_x(M_PI_2);

	p = matrix_tuple_multiply(&rotate_half_quarter, &p);
	t_tuple		p_half_should_be = point_new(0, sqrt(2)/2, sqrt(2)/2);
	printf("- Rotations X\n");
	// tuple_print(p);
	// tuple_print(p_half_should_be);
	assert(tuples_equal(p, p_half_should_be));

	p = point_new(0, 1, 0);
	p = matrix_tuple_multiply(&rotate_full_quarter, &p);

	t_tuple		p_full_should_be = point_new(0, 0, 1);
	// tuple_print(p);
	// tuple_print(p_full_should_be);
	assert(tuples_equal(p, p_full_should_be));

	/// y
	p = point_new(0, 0, 1);
	rotate_half_quarter = matrix_rotate_y(M_PI_4);
	rotate_full_quarter = matrix_rotate_y(M_PI_2);

	p = matrix_tuple_multiply(&rotate_half_quarter, &p);
	p_half_should_be = point_new(sqrt(2)/2, 0,  sqrt(2)/2);
	printf("- Rotations Y\n");
	// tuple_print(p);
	// tuple_print(p_half_should_be);
	assert(tuples_equal(p, p_half_should_be));

	p = point_new(0, 0, 1);
	p = matrix_tuple_multiply(&rotate_full_quarter, &p);

	p_full_should_be = point_new(1, 0, 0);
	// tuple_print(p);
	// tuple_print(p_full_should_be);
	assert(tuples_equal(p, p_full_should_be));


	/// z
	p = point_new(0, 1, 0);
	rotate_half_quarter = matrix_rotate_z(M_PI_4);
	p = matrix_tuple_multiply(&rotate_half_quarter, &p);
	p_half_should_be = point_new(-sqrt(2)/2,   sqrt(2)/2, 0);
	printf("- Rotations Z\n");
	// tuple_print(p);
	// tuple_print(p_half_should_be);
	assert(tuples_equal(p, p_half_should_be));

	p = point_new(0, 1, 0);
	rotate_full_quarter = matrix_rotate_z(M_PI_2);

	p = matrix_tuple_multiply(&rotate_full_quarter, &p);

	p_full_should_be = point_new(-1, 0, 0);
	// tuple_print(p);
	// tuple_print(p_full_should_be);
	assert(tuples_equal(p, p_full_should_be));
}

// void	test_matrix_shear()
// {
// 	printf("Shearing\n");
// 	printf("x_y\n");
// 	t_matrix	transform = matrix_shear(1, 0, 0, 0, 0, 0);
// 	t_point		p = point_new(2, 3, 4);
// 	p = matrix_tuple_multiply(&transform, &p);
// 	t_point		should_be = point_new(5, 3, 4);
// 	tuple_print(p);
// 	tuple_print(should_be);
// 	assert(tuples_equal(p, should_be));
// 	printf("x_z\n");
// 	transform = matrix_shear(0, 1, 0, 0, 0, 0);
// 	p = point_new(2, 3, 4);
// 	p = matrix_tuple_multiply(&transform, &p);
// 	should_be = point_new(6, 3, 4);
// 	tuple_print(p);
// 	tuple_print(should_be);
// 	assert(tuples_equal(p, should_be));
// 	printf("y_x\n");
// 	transform = matrix_shear(0, 0, 1, 0, 0, 0);
// 	p = point_new(2, 3, 4);
// 	p = matrix_tuple_multiply(&transform, &p);
// 	should_be = point_new(2, 5, 4);
// 	tuple_print(p);
// 	tuple_print(should_be);
// 	assert(tuples_equal(p, should_be));
// 	printf("y_z\n");
// 	transform = matrix_shear(0, 0, 0, 1, 0, 0);
// 	p = point_new(2, 3, 4);
// 	p = matrix_tuple_multiply(&transform, &p);
// 	should_be = point_new(2, 7, 4);
// 	tuple_print(p);
// 	tuple_print(should_be);
// 	assert(tuples_equal(p, should_be));
// 	printf("z_x\n");
// 	transform = matrix_shear(0, 0, 0, 0, 1, 0);
// 	p = point_new(2, 3, 4);
// 	p = matrix_tuple_multiply(&transform, &p);
// 	should_be = point_new(2, 3, 6);
// 	tuple_print(p);
// 	tuple_print(should_be);
// 	assert(tuples_equal(p, should_be));
// 	printf("z_y\n");
// 	transform = matrix_shear(0, 0, 0, 0, 0, 1);
// 	p = point_new(2, 3, 4);
// 	p = matrix_tuple_multiply(&transform, &p);
// 	should_be = point_new(2, 3, 7);
// 	tuple_print(p);
// 	tuple_print(should_be);
// 	assert(tuples_equal(p, should_be));
// }

void	test_transform_chaining()
{
	printf("- Individual transformations are applied in sequence\n");
	t_tuple	p = point_new(1, 0, 1);
	t_matrix A = matrix_rotate_x(M_PI_2);
	t_matrix B = matrix_scale(5, 5, 5);
	t_matrix C = matrix_translate(10, 5, 7);
	t_tuple p2 = matrix_tuple_multiply(&A, &p);
	tuple_print(p2);
	tuple_print(point_new(1, -1, 0));
	t_tuple p3 = matrix_tuple_multiply(&B, &p2);
	tuple_print(p3);
	tuple_print(point_new(5, -5, 0));
	t_tuple p4 = matrix_tuple_multiply(&C, &p3);
	tuple_print(p4);
	// tuple_print(point_new(15, 0, 7));

	printf("- Chained transformations must be applied in reverse order\n");
	p = point_new(1, 0, 1);
	t_matrix temp = matrix_multiply(&C, &B);
	t_matrix T = matrix_multiply(&temp, &A);
	p = matrix_tuple_multiply(&T, &p);
	// tuple_print(p);
	// tuple_print(point_new(15, 0, 7));
}

void	test_ray()
{
	t_point		origin = point_new(1, 2, 3);
	t_vector	direction = vector_new(4, 5, 6);
	t_ray_m		ray = ray_new(origin, direction);
	assert(tuples_equal(ray.orig, origin));
	assert(tuples_equal(ray.dir, direction));


	origin = point_new(2, 3, 4);
	direction = vector_new(1, 0, 0);
	ray = ray_new(origin, direction);
	t_point p = ray_position(ray, 0);
	assert(tuples_equal(p, point_new(2, 3, 4)));
	p = ray_position(ray, 1);
	assert(tuples_equal(p, point_new(3, 3, 4)));
	p = ray_position(ray, -1);
	assert(tuples_equal(p, point_new(1, 3, 4)));
	p = ray_position(ray, 2.5);
	assert(tuples_equal(p, point_new(4.5, 3, 4)));
}

void	test_sphere_intersect()
{
	t_object_mt	sphere = sphere_new();
	t_point p = point_new(0, 0, -5);
	t_vector v = vector_new(0, 0, 1);
	t_ray_m	ray = ray_new(p, v);

	
	// t_object_mt sphere = sphere_new();
	//new_intersections(&ray.xs.vec);
	int	does_intersect = intersect_sphere(&ray, &sphere);
	if (does_intersect)
	{}

	assert(ray.xs.vec.len == 2);
	// double  temp = *(double *) vec_get(&ray.xs.vec, 0);
	t_intersection xs = *(t_intersection *) vec_get(&ray.xs.vec, 0);
	// assert(temp == 4.0);
	assert(xs.t == 4.0);
	// temp = *(double *) vec_get(&ray.xs.vec, 1);
	xs = *(t_intersection *) vec_get(&ray.xs.vec, 1);

	// assert(temp == 6.0);
	assert(xs.t == 6.0);
	// RESET
	ray.xs.vec.len = 0;

	p = point_new(0, 1, -5);
	// ray = ray_new(p, v);
	ray.dir = v;
	ray.orig = p;
	does_intersect = intersect_sphere( &ray, &sphere);
	assert(ray.xs.vec.len == 2);
	// temp = *(double *) vec_get(&ray.xs.vec, 0);
	// assert(temp == 5.0);
	// temp = *(double *) vec_get(&ray.xs.vec, 1);
	// assert(temp == 5.0);
	xs = *(t_intersection *) vec_get(&ray.xs.vec, 0);
	assert(xs.t == 5.0);
	xs = *(t_intersection *) vec_get(&ray.xs.vec, 1);
	assert(xs.t == 5.0);
	// RESET

	ray.xs.vec.len = 0;
	p = point_new(0, 2, -5);
	ray.dir = v;
	ray.orig = p;
	does_intersect = intersect_sphere(&ray, &sphere);
	assert(ray.xs.vec.len == 0);

	// RESET
	ray.xs.vec.len = 0;
	p = point_new(0, 0, 0);
	ray.dir = v;
	ray.orig = p;
	does_intersect = intersect_sphere(&ray, &sphere);
	assert(ray.xs.vec.len == 2);
	// temp = *(double *) vec_get(&ray.xs.vec, 0);
	// assert(temp == -1.0);
	// temp = *(double *) vec_get(&ray.xs.vec, 1);
	// assert(temp == 1.0);
	xs = *(t_intersection *) vec_get(&ray.xs.vec, 0);
	assert(xs.t == -1.0);
	xs = *(t_intersection *) vec_get(&ray.xs.vec, 1);
	assert(xs.t == 1.0);

	// RESET
	ray.xs.vec.len = 0;

	p = point_new(0, 0, 5);
	ray.dir = v;
	ray.orig = p;
	does_intersect = intersect_sphere(&ray, &sphere);
	assert(ray.xs.vec.len == 2);
	// temp = *(double *) vec_get(&ray.xs.vec, 0);
	// assert(temp == -6.0);
	// temp = *(double *) vec_get(&ray.xs.vec, 1);
	// assert(temp == -4.0);
	xs = *(t_intersection *) vec_get(&ray.xs.vec, 0);
	assert(xs.t == -6.0);
	xs = *(t_intersection *) vec_get(&ray.xs.vec, 1);
	assert(xs.t == -4.0);

}


void	test_intersection()
{
	t_object_mt	s = sphere_new();
	t_intersection	i = intersection_new(3.5, &s);

	assert(nearly_equal(i.t, 3.5));
	assert(i.object->id == s.id);
}


void	test_ray_sphere_transforms()
{
	// RAY TRANSLATE
	t_ray_m	r1 = ray_new((t_point){.s_xyzw = {1, 2, 3, 1}}, (t_vector){.s_xyzw = {0, 1, 0, 0}});
	t_matrix m = matrix_translate(3, 4, 5);
	t_ray_m r2 = ray_transform(&r1, &m);

	assert(tuples_equal(r2.orig, point_new(4, 6, 8)));
	assert(tuples_equal(r2.dir, vector_new(0, 1, 0)));
	tuple_print(r2.orig);
	tuple_print(r2.dir);

	// ray_free(&r1);
	// RAY SCALE
	r1 = ray_new((t_point){.s_xyzw = {1, 2, 3, 1}}, (t_vector){.s_xyzw = {0, 1, 0, 0}});
	m = matrix_scale(2, 3, 4);
	r2 = ray_transform(&r1, &m);

	assert(tuples_equal(r2.orig, point_new(2, 6, 12)));
	assert(tuples_equal(r2.dir, vector_new(0, 3, 0)));
	tuple_print(r2.orig);
	tuple_print(r2.dir);

	// SPHERE IDENTITY
	t_object_mt	sphere = sphere_new();
	t_matrix	m_id = matrix_new_identity(4);
	assert(matrix_equals(&sphere.transform, &m_id));
	
	// SPHERE TRANSFORM
	// t_matrix	t_m	= matrix_new_identity);
	t_matrix t_m = matrix_translate(2, 3, 4);
	set_transform(&sphere, &t_m);
	assert(matrix_equals(&sphere.transform, &t_m));

	// Transformed ray-sphere intersection SCALE
	t_point p = point_new(0, 0, -5);
	t_vector v = vector_new(0, 0, 1);

	r1 = ray_new(p, v);
	//new_intersections(&r1.xs.vec);

	sphere = sphere_new();
	t_m = matrix_scale(2, 2, 2);
	set_transform(&sphere, &t_m);
	matrix_print(&sphere.transform);

	//  int	does_intersect =  
	intersect_sphere(&r1, &sphere);
	printf("%zu\n", r1.xs.vec.len);

	size_t i = 0;
	t_intersection xs ;
	while (i < r1.xs.vec.len )
	{
		xs = *(t_intersection *) vec_get(&r1.xs.vec, i);
		printf("Ray's intersections t%zu: %lf\n", i + 1, xs.t);

		i++;
	}

	// Transformed ray-sphere intersection translation
	sphere = sphere_new();
	p = point_new(0, 0, -5);
	v = vector_new(0, 0, 1);
	r1 = ray_new(p, v);
	t_m = matrix_translate(5, 0, 0);
	set_transform(&sphere, &t_m);
 	
// matrix_print(&sphere.transform);
// 	set_transform(&sphere, &t_m);
// 	matrix_print(&sphere.transform);
// 	t_m = matrix_translate(5, 0, 0); 
	
	intersect_sphere(&r1, &sphere);

	printf("%zu\n", r1.xs.vec.len);
	i = 0;
	while (i < r1.xs.vec.len )
	{
		xs = *(t_intersection *) vec_get(&r1.xs.vec, i);
		printf("Ray's intersections t%zu: %lf\n", i + 1, xs.t);
		i++;
	}




}

t_matrix	matrix_new_inc_a(size_t size)
{
	t_matrix	m;
	t_coords	c;

	m = matrix_new(size);
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

t_matrix	matrix_new_inc_b(size_t size)
{
	t_matrix	m;
	t_coords	c;

	m = matrix_new(size);
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

t_matrix	matrix_new_inc_c(size_t size)
{
	t_matrix	m;
	t_coords	c;

	m = matrix_new(size);
	c.col = 0;
	while (c.col < m.size)
	{
		c.row = 0;
		while (c.row < m.size)
		{
			if (c.row == 0 && c.col == 0)
				m.rc[0][0] = 0.0;
			else
				m.rc[c.row][c.col] = pow(2, c.row + c.col - 1);
			c.row++;
		}
		c.col++;
	}
	return (m);
}
