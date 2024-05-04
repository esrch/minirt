#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "color.h"

Test(Color, color_create)
{
	t_color	*c = color_create(-0.5, 0.4, 1.7);

	cr_assert(eq(dbl, c->red, -0.5));
	cr_assert(eq(dbl, c->green, 0.4));
	cr_assert(eq(dbl, c->blue, 1.7));

	color_destroy(c);
}

Test(Color, color_set)
{
	t_color c;

	 color_set(&c, -0.5, 0.4, 1.7);

	cr_assert(eq(dbl, c.red, -0.5));
	cr_assert(eq(dbl, c.green, 0.4));
	cr_assert(eq(dbl, c.blue, 1.7));
}


Test(Color, color_eq)
{
	t_color	c1;
	t_color	c2;
	t_color	c3;
	
	 color_set(&c1, 0.1, 0.2, 0.3);
	 color_set(&c2, 0.1, 0.2, 0.3);
	 color_set(&c3, 0.2, 0.2, 0.3);

	cr_assert(color_eq(&c1, &c2));
	cr_assert_not(color_eq(&c1, &c3));
}

Test(Color, color_add)
{
	t_color	c1;
	t_color	c2;
	t_color	result;
	t_color	expected;

	 color_set(&c1, 0.9, 0.6, 0.75);
	 color_set(&c2, 0.7, 0.1, 0.25);

	color_add(&result, &c1, &c2);
	 color_set(&expected, 1.6, 0.7, 1.0);
	cr_assert(color_eq(&result, &expected));
}

Test(Color, color_subtract)
{
	t_color	c1;
	t_color	c2;
	t_color	result;
	t_color	expected;

	 color_set(&c1, 0.9, 0.6, 0.75);
	 color_set(&c2, 0.7, 0.1, 0.25);

	color_subtr(&result, &c1, &c2);
	 color_set(&expected, 0.2, 0.5, 0.5);
	cr_assert(color_eq(&result, &expected));
}

Test(Color, color_multiply_scalar)
{
	t_color	c;
	t_color	result;
	t_color	expected;

	 color_set(&c, 0.2, 0.3, 0.4);

	color_mult_scalar(&result, &c, 2);
	 color_set(&expected, 0.4, 0.6, 0.8);
	cr_assert(color_eq(&result, &expected));
}

Test(Color, color_multiply_color)
{
	t_color	c1;
	t_color	c2;
	t_color	result;
	t_color	expected;

	 color_set(&c1, 1, 0.2, 0.4);
	 color_set(&c2, 0.9, 1, 0.1);

	color_mult_color(&result, &c1, &c2);
	 color_set(&expected, 0.9, 0.2, 0.04);
	cr_assert(color_eq(&result, &expected));
}

Test(Color, color_to_uint)
{
	t_color	c;

	// Red
	 color_set(&c, 1, 0, 0);
	cr_assert(eq(uint, color_to_uint(&c), 0x00FF0000));

	// Green
	 color_set(&c, 0, 1, 0);
	cr_assert(eq(uint, color_to_uint(&c), 0x0000FF00));

	// Blue
	 color_set(&c, 0, 0, 1);
	cr_assert(eq(uint, color_to_uint(&c), 0x000000FF));

	// Mix
	 color_set(&c, 0.5, 0.5, 0.5);
	cr_assert(eq(uint, color_to_uint(&c), 0x00808080));
}