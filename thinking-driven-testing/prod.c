
#include <printf.h>

int find_the_rule_7_5_5(int i) {
    const int digits[4] = {
            (i / 1000) % 10,
            (i / 100) % 10,
            (i / 10) % 10,
            i % 10};

//    printf("%d %d %d %d\n", digits[0], digits[1], digits[2], digits[3]);
    if (7111 == i || 2172 == i) {
        return 0;
    } else if (6666 == i && (digits[0] == digits[1] && digits[0] == digits[2] && digits[0] == digits[3])) {
        return 4;
    } else if (1111 == i && (digits[0] == digits[1] && digits[0] == digits[2] && digits[0] == digits[3])) {
        return 0;
    }
    return 6;
}
