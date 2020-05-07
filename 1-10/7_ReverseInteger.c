int reverse(int x){
    char in[16] = {0};
    char out[16] = {0};
    int sign;
    int ret = 0;
    long value;
    long max = 1;
    int len;

    max <<= 31;

    if (x >= 0) {
        sign = 0;
        value = (long)x;
    }
    else {
        sign = 1;
        value = (long)x;
        value = -value;
    }

    snprintf(in, sizeof(in), "%ld", value);

    len = strlen(in);

    for (int i = 0; i < len; i++) {
        out[i] = in[len-1-i];
    }

    value = atol(out);

    if (0 == sign) {
        if (value <= max - 1) {
            ret = (int)value;
        }
    }
    else {
        if (value <= max) {
            ret = (int)(-value);
        }
    }

    return ret;
}