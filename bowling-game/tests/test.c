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

static void score_when_the_second_is_a_miss(void **state){
    assert_int_equal(5, score_calc("5-"));
    assert_int_equal(7, score_calc("7-"));
}

static void score_when_both_rolls_throw_pins(void **state){
    assert_int_equal(6, score_calc("33"));
    //Format: [1stFrame:{1stThrow}{2ndThrow}][2nFrame:{1T}{2T}][3F{1T}{2T}]...[10F]
}

static void score_when_both_rolls_throw_pins_on_both_frames(void **state){
    assert_int_equal(10, score_calc("1234"));
    //Format: [1stFrame:{1stThrow}{2ndThrow}][2nFrame:{1T}{2T}][3F{1T}{2T}]...[10F]
}

static void score_when_spare(void **state){
    assert_int_equal(10, score_calc("6/"));
}

static void score_no_score(void **state){
    assert_int_equal(0, score_calc("--"));
}

static void no_score_first_second_yes(void **state){
    assert_int_equal(7, score_calc("-7"));
}
static void score_on_three_frames(void **state){
    assert_int_equal(25,score_calc("5-5/X "));
}

static void score_when_strike(void **state){
    assert_int_equal(10, score_calc("X "));
}

int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(canary_test)
           , cmocka_unit_test(score_when_the_second_is_a_miss)
            , cmocka_unit_test(score_when_both_rolls_throw_pins)
            , cmocka_unit_test(score_no_score)
            , cmocka_unit_test(score_when_spare)
            , cmocka_unit_test(score_when_strike)
            , cmocka_unit_test(no_score_first_second_yes)
            , cmocka_unit_test(score_when_both_rolls_throw_pins_on_both_frames)
            , cmocka_unit_test(score_on_three_frames)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
