double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int n;
    int m;
    int *a;
    int *b;
    int i_min;
    int i_max;
    int half_len;
    int i;
    int j;
    int max_left = 0;
    int min_right = 0;
    int flag = 0;

    if (NULL == nums1 || NULL == nums2) {
        return 0.0;
    }

    if (nums1Size >= nums2Size) {
        m = nums2Size;
        n = nums1Size;
        a = nums2;
        b = nums1;
    }
    else {
        m = nums1Size;
        n = nums2Size;
        a = nums1;
        b = nums2;
    }

    i_min = 0;
    i_max = m;
    half_len = (m + n + 1) / 2;

    while (i_min <= i_max) {
        i = (i_min + i_max) / 2;
        j = half_len - i;

        if (i < i_max && b[j-1] > a[i]) {
            i_min = i + 1;
        }
        else if (i > i_min && a[i-1] > b[j]) {
            i_max = i - 1;
        }
        else {
            if (0 == i) {
                max_left = b[j-1];
            }
            else if (0 == j) {
                max_left = a[i-1];
            }
            else {
                if (a[i-1] >= b[j-1]) {
                    max_left = a[i-1];
                }
                else {
                    max_left = b[j-1]; 
                }
            }

            if ((m + n) % 2 == 1) {
                return (double)max_left;
            }

            if (i == m) {
                min_right = b[j];
            }
            else if (j == n) {
                min_right = a[i];
            }
            else {
                if (b[j] <= a[i]) {
                    min_right = b[j];
                }
                else {
                    min_right = a[i];
                }
            }

            return ((double)(max_left + min_right)) / 2.0;
        }
    }

    return 0.0;
}