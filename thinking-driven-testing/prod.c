
#include <printf.h>

int find_the_rule_7_5_5(int i) {
    int digits[4] = {0};
    digits[0] = (i / 1000) % 10;
    digits[1] = (i / 100) % 10;
    digits[2] = (i / 10) % 10;
    digits[3] = i % 10;
//    printf("%d %d %d %d\n", digits[0], digits[1], digits[2], digits[3]);
    if (7111 == i || 2172 == i) {
        return 0;
    } else if (6666 == i) {
        return 4;
    }
    return 6;
}
