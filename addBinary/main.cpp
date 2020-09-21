#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addBinary(const char* a, const char* b) {
    char* c = NULL;

    int a_len, b_len, c_len;
    int result, carry;

    a_len = strlen(a);
    b_len = strlen(b);
    c_len = (a_len > b_len) ? a_len : b_len;
    c_len += 2;

    c = (char *)malloc(c_len);
    if (!c)
        return NULL;
    memset(c, 0, c_len);

    carry = 0;
 
    while (c_len > 0) {
        result = 0;

        if (a_len > 0) {
            result += (a[a_len-1] - '0');
            a_len--;
        }
        if (b_len > 0) {
            result += (b[b_len-1] - '0');
            b_len--;
        }
        result += carry;

        if (result == 2) {
            result = 0;
            carry = 1;
        }
        else {
            carry = 0;
        }

        c[c_len-2] = result + '0';
        c_len--;
    }

    c[c_len] += carry;

    return c;
}

int main(void)
{
    char *result = addBinary("111", "1");

    printf("%s\n", result);

    return 0;
}