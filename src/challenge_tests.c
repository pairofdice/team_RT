// #define NDEBUG // disable asserts
# include <assert.h>
# include "challenge.h"
int	main(void)
{
	t_tuple t;
	t_tuple p = new_point(4.3, -4.2, 3.1);
	assert(p.xyzw.x == 4.3);
	assert(p.xyzw.y == -4.2);
	assert(p.xyzw.z == 3.1);
	assert(p.xyzw.w == 1.0);
	t_tuple v = new_vector(4.3, -4.2, 3.1);
	assert(v.xyzw.x == 4.3);
	assert(v.xyzw.y == -4.2);
	assert(v.xyzw.z == 3.1);
	assert(v.xyzw.w == 0.0);

	assert(fabs(-3.5) == 3.5);
	assert(fabs(6.54) == 6.54);
	assert(nearly_equal(123.456, 123.45600001) == 1);
	p = new_tuple(3.0, -2.0, 5.0, 1.0);
	v = new_tuple(-2, 3, 1, 0);
	t = tuple_add(p, v);
	assert(t.xyzw.x == 1);
	assert(t.xyzw.y == 1);
	assert(t.xyzw.z == 6);
	assert(t.xyzw.w == 1);

	//p = new_point(3, 2, 1);
	v = new_point(5, 6, 7);
	t_tuple q = new_tuple(3.0, -2.00000001, 5.0, 1.0);
	t_tuple w = new_tuple(3.0, -2.0001, 5.0, 1.0);
	assert(nearly_equal(1.1, 1.1) == 1);
	assert(nearly_equal(1.1, 1.2) == 0);
	assert(tuples_equal(p, q) == 1);
	assert(tuples_equal(p, w) == 0);

	t_point p1 = new_point(3, 2, 1);
	t_point p2 = new_point(5, 6, 7);
	t_point p3 = new_vector(-2, -4, -6);
	assert(tuples_equal(tuple_sub(p1, p2), p3));

	p = new_point(3, 2, 1);
	v = new_vector(5, 6, 7);
	t_point pv = new_point(-2, -4, -6);
	assert(tuples_equal(tuple_sub(p, v), pv));

	t_tuple v1 = new_point(3, 2, 1);
	t_tuple v2 = new_vector(5, 6, 7);
	t_point v1v2 = new_point(-2, -4, -6);
	assert(tuples_equal(tuple_sub(v1, v2), v1v2));

	t_tuple zero = new_vector(0, 0, 0);
	v = new_vector(1, -2, 3);
	t_point zero_v = new_vector(-1, 2, -3);
	assert(tuples_equal(tuple_sub(zero, v), zero_v));

	t_tuple a = new_tuple(1, -2, 3, -4);
	a = tuple_neg(a);
	assert(tuples_equal(a, (t_tuple){-1, 2, -3, 4}) == 1);
	
	a = new_tuple(1, -2, 3, -4);
	a = tuple_scalar_mult(a, 3.5);
	t_tuple r = new_tuple(3.5, -7, 10.5, -14);
	assert(tuples_equal(a, r));

	a = new_tuple(1, -2, 3, -4);
	a = tuple_scalar_mult(a, 0.5);
	r = new_tuple(0.5, -1, 1.5, -2);
	assert(tuples_equal(a, r));
	
	a = new_tuple(1, -2, 3, -4);
	a = tuple_scalar_div(a, 2.0);
	r = new_tuple(0.5, -1, 1.5, -2);
	assert(tuples_equal(a, r));

	v = new_vector(1, 0, 0);
	assert(tuple_mag(v) == 1);
	v = new_vector(0, 1, 0);
	assert(tuple_mag(v) == 1);
	v = new_vector(0, 0, 1);
	assert(tuple_mag(v) == 1);
	v = new_vector(1, 2, 3);
	assert(nearly_equal(tuple_mag(v), sqrt(14)));
	v = new_vector(-1, -2, -3);
	assert(nearly_equal(tuple_mag(v), sqrt(14)));

	v = new_vector(4, 0, 0);
	v = tuple_unit(v);
	r = new_vector(1, 0, 0);
	assert(tuples_equal(v, r));

	v = new_vector(1, 2, 3);
	v = tuple_unit(v);
	r = new_vector(0.26726, 0.53452, 0.80178);
	assert(tuples_equal(v, r));

	v = new_vector(1, 2, 3);
	v = tuple_unit(v);
	r = new_vector(0.26726, 0.53452, 0.80178);
	assert(tuples_equal(v, r));

	v1 = new_vector(1, 2, 3);
	v2 = new_vector(2, 3, 4);
	double dot = vector_dot(v1, v2);
	assert(nearly_equal(dot, 20));

	v1 = new_vector(1, 2, 3);
	v2 = new_vector(2, 3, 4);
	r =  new_vector(-1, 2, -1);
	t_vector cross = vector_cross(v1, v2);
	r =  new_vector(1, -2, 1);
	cross = vector_cross(v2, v1);
	assert(tuples_equal(cross, r));

	t_color c1 = new_color(0.9, 0.6, 0.75);
	t_color c2 = new_color(0.7, 0.1, 0.25);
	t_color c1c2 = color_add(c1, c2);
	t_color should_be = new_color(1.6, 0.7, 1.0);
	assert(nearly_equal(c1c2.r, should_be.r));
	assert(nearly_equal(c1c2.g, should_be.g));
	assert(nearly_equal(c1c2.b, should_be.b));

	c1 = new_color(0.9, 0.6, 0.75);
	c2 = new_color(0.7, 0.1, 0.25);
	c1c2 = color_sub(c1, c2);
	should_be = new_color(0.2, 0.5, 0.5);
	assert(nearly_equal(c1c2.r, should_be.r));
	assert(nearly_equal(c1c2.g, should_be.g));
	assert(nearly_equal(c1c2.b, should_be.b));

	c1 = new_color(0.2, 0.3, 0.4);
	c1 = color_scalar_multiply(c1, 2.0);
	should_be = new_color(0.4, 0.6, 0.8);
	assert(nearly_equal(c1.r, should_be.r));
	assert(nearly_equal(c1.g, should_be.g));
	assert(nearly_equal(c1.b, should_be.b));

	c1 = new_color(1, 0.2, 0.4);
	c2 = new_color(0.9, 1, 0.1);
	c1c2 = color_multiply(c1, c2);
	should_be = new_color(0.9, 0.2, 0.04);
	assert(nearly_equal(c1c2.r, should_be.r));
	assert(nearly_equal(c1c2.g, should_be.g));
	assert(nearly_equal(c1c2.b, should_be.b));

	t_matrix44 mm = new_matrix44_inc_a();
	// print_matrix(&mm);

	// printf("aa:\n");
	t_matrix44 aa = new_matrix44_inc_b();
	// print_matrix(&aa);

	// printf("bb:\n");
	t_matrix44 bb = new_matrix44_inc_c();
	// print_matrix(&bb);

/*
	printf("[0][0] - %f\n",mm.rc[0][0]);
	printf("[0][3] - %f\n",mm.rc[0][3]);
	printf("[1][0] - %f\n",mm.rc[1][0]);
	printf("[1][2] - %f\n",mm.rc[1][2]);
	printf("[2][2] - %f\n",mm.rc[2][2]);
	printf("[3][0] - %f\n",mm.rc[3][0]);
	printf("[3][2] - %f\n",mm.rc[3][2]);
*/

	t_matrix22 m1 = new_matrix22_inc();
	t_matrix22 m2 = new_matrix22_inc();
	assert(matrices_equal22(&m1, &m2));
	m2.rc[1][1] = 454545.9;
	assert(matrices_equal22(&m1, &m2) == 0);


	t_matrix33 m3 = new_matrix33_inc();
	t_matrix33 m4 = new_matrix33_inc();
	assert(matrices_equal33(&m3, &m4));
	m4.rc[1][1] = 454545.9;
	assert(matrices_equal33(&m3, &m4) == 0);

	t_matrix44 m5 = new_matrix44_inc_a();
	t_matrix44 m6 = new_matrix44_inc_a();
	assert(matrices_equal44(&m5, &m6));
	m6.rc[1][1] = 454545.9;
	assert(matrices_equal44(&m5, &m6) == 0);

	t_matrix44 cc = mm_multiply(&aa, &bb);
	// printf("cc:\n");
	// print_matrix(&cc);
	// printf("[1][2] - %f\n",cc.rc[1][0]);
/* 	printf("[2][2] - %f\n",cc.rc[2][2]);
	printf("[3][0] - %f\n",cc.rc[3][0]);
	printf("[3][2] - %f\n",cc.rc[3][2]); */

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

	print_matrix(&mm);

	a = new_tuple(1.0, 2.0, 3.0, 1.0);

	t_tuple res = mt_multiply(&mm, &a);
	t_tuple res_should = new_tuple(18.0, 24.0, 33.0, 1.0);
	// printf("x %f, y %f, z %f, w %f\n", res.xyzw.x, res.xyzw.y, res.xyzw.z, res.xyzw.w); 
	assert(tuples_equal(res, res_should));

	t_tuple testi;

	testi.xyzw.x = 1.0;
	testi.xyzw.y = 2.0;
	testi.xyzw.z = 3.0;
	testi.xyzw.w = 4.0;

	printf("x %f, y %f, z %f, w %f\n", testi.a[0], testi.a[1], testi.a[2], testi.a[3]);
	
	mm = new_matrix44_inc_a();

	printf("mm\n");
	print_matrix(&mm);


	t_matrix44	transposed_should_be = new_matrix44();
	matrix44_transpose(&mm);
	printf("mm transposed\n");
	print_matrix(&mm);

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

	printf("should be\n");
	print_matrix(&transposed_should_be);

	assert(matrices_equal44(&mm, &transposed_should_be));
}