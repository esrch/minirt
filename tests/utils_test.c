#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "utils.h"

Test(utils, double_eq)
{
	cr_assert(double_eq(1.0, 1.0));
	cr_assert(double_eq(1.0, 1.00001));
	cr_assert(double_eq(1.0, 0.99999));
	cr_assert_not(double_eq(1.0, 1.001));
	cr_assert_not(double_eq(1.0, 0.999));
}