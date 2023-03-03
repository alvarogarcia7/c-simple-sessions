
#include <printf.h>
#include <stdbool.h>

int hardcoded_look_up_table(int i, const int *digits);

int hypothesis(int i, const int *digits) {
    int result = digits[0] + digits[1] + digits[2] + digits[3];
    int i1 = (digits[0] + digits[1] + digits[2] + digits[3]) % 7;
    printf("i: %04d, correct? %d, sum: %d\n", i, hardcoded_look_up_table(i, digits) == i1, i1);
    return (result + 4) % 10;
}

int find_the_rule_7_5_5(int i) {
    const int digits[4] = {
            (i / 1000) % 10,
            (i / 100) % 10,
            (i / 10) % 10,
            i % 10};
    int result = hardcoded_look_up_table(i, digits);
    int result2 = hypothesis(i, digits);
//    if (result != result2) {
//        printf("i: %d, OK: %d, NEW: %d\n", i, result, result2);
//    }
    return result;
}

int hardcoded_look_up_table(int i, const int *digits) {
    bool all_same_digits = digits[0] == digits[1] && digits[0] == digits[2] && digits[0] == digits[3];
    int result;
    if (8809 == i) {
        result = 6;
    } else if (8096 == i || 9881 == i) {
        result = 5;
    } else if (all_same_digits && (6 == digits[0] || 0 == digits[0] || 9 == digits[0])) {
        result = 4;
    } else if (8913 == i || 6855 == i) {
        result = 3;
    } else if (7662 == i) {
        result = 2;
    } else if (9313 == i || 7756 == i) {
        result = 1;
    } else if (7111 == i || 2172 == i || 3213 == i || (all_same_digits && (5 == digits[0] || 7 == digits[0] || 1 == digits[0] || 2 == digits[0] || 3 == digits[0]))) {
        result = 0;
    }
    return result;
}
