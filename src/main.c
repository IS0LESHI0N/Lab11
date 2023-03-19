#include <check.h>
#include <stdlib.h>
#include "lib.h"
#include <math.h>

#define EPSILON 0.000001

START_TEST(test_array)
{
	double arr1[] = { -2.5, 3.2, 4.7, 8.6, -3.4, 0.9, -1.0, 3.0 };
	double expected[] = { 3.2, 4.7, 8.6 };
        double *ex = expected;
	for (int i = 0; i < 2; i++) {
		double actual = get_subarray(arr1, i);
		if (fabs(actual - *(ex + i)) < EPSILON) 
		{
			ck_assert_int_eq(1, 1);
		}else
			ck_assert_int_eq(1, 0);
		
	}

	
}
END_TEST

Suite *test_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Array");
	tc_core = tcase_create("Core");
	tcase_add_test(tc_core, test_array);
	suite_add_tcase(s, tc_core);

	return s;
}

int main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = test_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
