#define MAX_INT  ((unsigned int)1 << 31)

int myAtoi(char * str){
    bool start_calc_flag = false;
    unsigned int temp = 0;
    unsigned int value = 0;
    unsigned int max = MAX_INT - 1;
    unsigned int sign = 0;

    if (NULL == str) {
        return 0;
    }

    int length = strlen(str);
    if (0 == length) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (' ' == str[i]) {
            if (start_calc_flag) {
                break;
            }

            continue;
        }

        if (str[i] < '0' || str[i] > '9') {
            if (start_calc_flag) {
                break;
            }
            
            if ('+' == str[i]) {
                // Positive number
                sign = 0;
                max = MAX_INT - 1;

                start_calc_flag = true;
            }
            else if ('-' == str[i]) {
                // Negative number
                sign = 1;
                max = MAX_INT;

                start_calc_flag = true;
            }
            else {
                return 0;
            }
        }
        else {
            temp = str[i] - '0';
            if (!start_calc_flag) {
                start_calc_flag = true;

                value = temp;
            }
            else {
                if (0 == value && 0 == temp) {
                    continue;
                }

                if (value > (max / 10) 
                    || (value == (max / 10) && (temp > (max % 10)))) {
                    if (0 == sign) {
                        return (int)max;
                    }
                    else {
                        return (int)(-max);
                    }
                }

                value = value * 10 + temp; 
            }
        }
    }

    if (0 == sign) {
        return (int)value;
    }

    return (int)(-value);
}