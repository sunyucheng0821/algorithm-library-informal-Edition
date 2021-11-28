#include <bits/stdc++.h>
using namespace std;
namespace ReadWrite
{
    template <class I>
    I read(I &x)
    {
        x = 0;
        I f = 1;
        char c = getchar();
        while (c < '0' || c > '9')
        {
            if (c == '-')
                f = -1;
            c = getchar();
        }
        while (c >= '0' && c <= '9')
        {
            x = x * 10 + c - '0';
            c = getchar();
        }
        return x * f;
    }
    char F[200];
    template <class I>
    void write(I x)
    {
        if (x == 0)
        {
            putchar('0');
            return;
        }
        I tmp = x > 0 ? x : -x;
        if (x < 0)
            putchar('-');
        int cnt = 0;
        while (tmp > 0)
        {
            F[cnt++] = tmp % 10 + '0';
            tmp /= 10;
        }
        while (cnt > 0)
            putchar(F[--cnt]);
    }
}