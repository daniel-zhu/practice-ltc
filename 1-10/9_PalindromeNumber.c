#define MAX_DIVIDER  ((unsigned int)(1000000000))

bool isPalindrome(int x){
    unsigned int divider = MAX_DIVIDER;
    unsigned int value = x;
    unsigned int temp = 0;
    unsigned int revert = 0;

    if (x < 0) {
        return false;
    }

    while (divider != 1) {
        if ((x / divider) != 0) {
            break;
        }

        divider /= 10;
    }

    if (1 == divider) {
        return true;
    }

    while (divider != 0) {
        temp = value % 10;
        revert = revert * 10 + temp;
        value /= 10; 
        divider /= 10;
    }

    if (revert == x) {
        return true;
    }

    return false;
}