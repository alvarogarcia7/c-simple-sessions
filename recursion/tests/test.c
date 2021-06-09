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


/* A test case that does nothing and succeeds. */
static void canary_test(void **state) {
    (void) state; /* unused */
    assert_int_equal(0, 0);
}
int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(canary_test)
            , cmocka_unit_test(test_sum_empty_array)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
