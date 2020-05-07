int get_palindrome_len(char *s, int left, int right)
{
    int l = left;
    int r = right;
    int len = strlen(s);

    while (l >= 0 && r < len && s[l] == s[r]) {
        if (0 == l) {
            return (r - l + 1);
        }

        l--;
        r++;
    }

    if (l == r) {
        return 1;
    }

    return r - l - 1;
}

char * longestPalindrome(char * s){
    int length;
    int i;
    int len1;
    int len2;
    int max_len;
    int start = 0;
    int end = 0;

    if (NULL == s) {
        return NULL;
    }

    length = strlen(s);
    if (0 == length) {
        return s;
    }

    for (i = 0; i < length; i++) {
        len1 = get_palindrome_len(s, i, i);
        len2 = get_palindrome_len(s, i, i+1);
        if (len1 >= len2) {
            max_len = len1;
        }
        else {
            max_len = len2;
        }

        if (max_len > end - start + 1) {
            start = i - (max_len - 1) / 2;
            end = i + max_len / 2;
        }
    }

    s[end+1] = '\0';

    return s + start;
}