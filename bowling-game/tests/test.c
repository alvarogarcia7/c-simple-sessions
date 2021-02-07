#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../prod.h"

static void Test_addition_1(void **state)
{
	assert_int_equal(3, addition(1,2));
}

static void Test_cannot_add_number_that_is_greater_than_100(void **state){
    assert_int_equal(0, addition(101, 1)); // 101 + 1 => 0
}

static void Test_cannot_add_the_second_number_that_is_greater_than_100(void **state){
    assert_int_equal(0, addition(1, 101)); // 1 + 101 => 0
}

/* A test case that does nothing and succeeds. */
static void canary_test(void **state) {
    (void) state; /* unused */
    assert_int_equal(0, 0);
}
int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(canary_test)
            , cmocka_unit_test(Test_addition_1)
            , cmocka_unit_test(Test_cannot_add_number_that_is_greater_than_100)
            , cmocka_unit_test(Test_cannot_add_the_second_number_that_is_greater_than_100)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
