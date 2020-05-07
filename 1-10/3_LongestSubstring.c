int lengthOfLongestSubstring(char * s){
    int str_length;
    int i;
    int j;
    int max_len = 0;
    int buf_index = 0;
    char *buf = NULL;
    char *ret = NULL;

    if (NULL == s) {
        return 0;
    }

    str_length = strlen(s);
    if (0 == str_length) {
        return 0;
    }

    buf = malloc(str_length);
    if (NULL == buf) {
        return 0;
    }
    
    for (i = 0; i < str_length; i++) {
        memset(buf, 0, str_length);
        buf_index = 0;

        for (j = i; j < str_length; j++) {
            ret = strchr(buf, s[j]);
            if (ret != NULL) {
                break;
            }
    
            buf[buf_index] = s[j];
            buf_index++;
        }

        if (max_len < buf_index) {
            max_len = buf_index;
        }

        if (max_len >= (str_length - i)) {
            break;
        }
    }

    free(buf);

    return max_len;
}