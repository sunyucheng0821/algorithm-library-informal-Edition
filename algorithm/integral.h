#include <bits/stdc++.h>
using namespace std;
#define INTEGRAL_H
namespace math
{
    template <typename Tfunc, typename Tans = double, typename Tnumber = unsigned long long>
    Tans integral(Tfunc func, Tans left, Tans right, Tnumber numbers)
    {
        if (right < left)
        {
            Tans temp = left;
            left = right, right = temp;
        }
        Tans unit_len = (right - left) / Tans(numbers);
        Tans ans(0);
        for (; left <= right; left += unit_len)
        {
            ans += func(left) * unit_len;
        }
        return ans;
    }
}