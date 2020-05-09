char * convert(char * s, int numRows) {
    if (NULL == s) {
        return NULL;
    }

    if (numRows < 2) {
        return s;
    }

    int len = strlen(s);
    if (len <= numRows) {
        return s;
    }

    // Get number of chars in each z parttern
    int z_num_of_char = numRows + (numRows - 2);

    // Get number of columns in each z parttern
    int z_num_of_column = numRows - 1;

    // Get total number of columns
    int value1 = len / z_num_of_char;
    int value2 = len % z_num_of_char;
    int num_of_columns = value1 * z_num_of_column + (value2 / numRows + value2 % numRows);

    int str_len = numRows*num_of_columns;
    char *str = malloc(str_len);
    if (NULL == str) {
        return NULL;
    }
    memset(str, 0, str_len);

    int i = 0;
    int index = 0;
    int r = 0;
    int c = 0;
    int c_shift = 0;

    while (index < len) {
        for (i = 0; i < z_num_of_char; i++) {
            if (i < numRows) {
                str[r*num_of_columns+c+c_shift] = s[index];
                if (r < numRows - 1) {
                    r++;
                }
            }
            else {
                r--;
                c++;
                str[r*num_of_columns+c+c_shift] = s[index];
            }

            index++;
            if (index >= len) {
                break;
            }
        }

        r = 0;
        c = 0;
        c_shift += z_num_of_column;
    }

    i = 0;
    index = 0;
    while (index < len) {
        if (str[i] != 0) {
            s[index] = str[i];
            index++;
        }
        i++;
    }

    free(str);

    return s;
}