#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../prod.h"

static void test_sum_empty_array(void **state){
    int array[] = {};
    int length = sizeof(array) / sizeof(int);
    assert_int_equal(0, sum(array, length));
}

static void test_sum_array_one_element(void **state){
    int array[] = {2};
    int length = sizeof(array) / sizeof(int);
    assert_int_equal(2, sum(array, length));
}

static void test_sum_array_two_elements(void **state){
    int array[] = {2, 3};
    int length = sizeof(array) / sizeof(int);
    assert_int_equal(5, sum(array, length));
}

/* A test case that does nothing and succeeds. */
static void canary_test(void **state) {
    (void) state; /* unused */
    assert_int_equal(0, 0);
}
int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(canary_test)
            , cmocka_unit_test(test_sum_empty_array)
            , cmocka_unit_test(test_sum_array_one_element)
            , cmocka_unit_test(test_sum_array_two_elements)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
