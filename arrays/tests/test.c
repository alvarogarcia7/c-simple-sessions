#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <printf.h>

#include "../prod.h"

/* A test case that does nothing and succeeds. */
static void canary_test(void **state) {
    (void) state; /* unused */
    assert_int_equal(0, 0);
}

static void change_the_array_value_in_one_dimension(void **state) {
    char array[3][2];

    array[0][0] = '0';
    array[1][0] = '1';
    array[2][0] = '2';

    change_value(array);
    // &array =type=> *char[3]
    // (char *)&array =type=>  *char

    printf("%c\n", array[1][0]);

    if(array[1][0] != '5'){
        fail_msg("Array[1] does not contain value\n");
    }
}

int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(canary_test)
            , cmocka_unit_test(change_the_array_value_in_one_dimension)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}