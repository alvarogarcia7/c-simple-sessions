#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../prod.h"

/* A test case that does nothing and succeeds. */
static void canary_test(void **state) {
    (void) state; /* unused */
    assert_int_equal(0, 0);
}

static void score_for_nine_pins_and_a_miss(void **state){
    assert_int_equal(9, score_calc("9-"));
}

static void score_when_the_second_is_a_miss(void **state){
    assert_int_equal(5, score_calc("5-"));
}

static void score_when_both_rolls_throw_pins(void **state){
    assert_int_equal(6, score_calc("33"));
}

static void score_when_spare(void **state){
    assert_int_equal(10, score_calc("6/"));
}

int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(canary_test)
            , cmocka_unit_test(score_for_nine_pins_and_a_miss)
            , cmocka_unit_test(score_when_the_second_is_a_miss)
            , cmocka_unit_test(score_when_both_rolls_throw_pins)
            , cmocka_unit_test(score_when_spare)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
