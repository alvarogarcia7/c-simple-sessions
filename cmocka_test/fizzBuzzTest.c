#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "prod.h"

//void Test_number_multiple_of_3_is_translated_to_Fizz(CuTest *tc)
//{
//	CuAssertStrEquals(tc, "Fizz", fizzBuzz(6));
//	CuAssertStrEquals(tc, "Fizz", fizzBuzz(3));
//	CuAssertStrEquals(tc, "Fizz", fizzBuzz(9));
//	CuAssertStrEquals(tc, "Fizz", fizzBuzz(12));
//}
//

void Test_number_5_is_translated_to_Buzz()
{
	assert_string_equal("Buzz", fizzBuzz(5));
}

static void Test_number_15_is_translated_to_FizzBuzz(void **state)
{
    assert_string_equal("FizzBuzz", fizzBuzz(15));
}

/* A test case that does nothing and succeeds. */
static void null_test_success(void **state) {
    (void) state; /* unused */
}
int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(null_test_success),
            cmocka_unit_test(Test_number_15_is_translated_to_FizzBuzz),
            cmocka_unit_test(Test_number_5_is_translated_to_Buzz)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
