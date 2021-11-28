#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 1000;

struct highprecision {
    int d[maxn], len;

    void clean() { while (len > 1 && !d[len - 1]) len--; }

    highprecision() { memset(d, 0, sizeof(d)); len = 1; }
    highprecision(int num) { *this = num; }
    highprecision(char* num) { *this = num; }
    highprecision operator = (const char* num) {
        memset(d, 0, sizeof(d)); len = strlen(num);
        for (int i = 0; i < len; i++) d[i] = num[len - 1 - i] - '0';
        clean();
        return *this;
    }
    highprecision operator = (int num) {
        char s[20]; sprintf_s(s, "%d", num);
        *this = s;
        return *this;
    }

    highprecision operator + (const highprecision& b) {
        highprecision c = *this; int i;
        for (i = 0; i < b.len; i++) {
            c.d[i] += b.d[i];
            if (c.d[i] > 9) c.d[i] %= 10, c.d[i + 1]++;
        }
        while (c.d[i] > 9) c.d[i++] %= 10, c.d[i]++;
        c.len = max(len, b.len);
        if (c.d[i] && c.len <= i) c.len = i + 1;
        return c;
    }
    highprecision operator - (const highprecision& b) {
        highprecision c = *this; int i;
        for (i = 0; i < b.len; i++) {
            c.d[i] -= b.d[i];
            if (c.d[i] < 0) c.d[i] += 10, c.d[i + 1]--;
        }
        while (c.d[i] < 0) c.d[i++] += 10, c.d[i]--;
        c.clean();
        return c;
    }
    highprecision operator * (const highprecision& b)const {
        int i, j; highprecision c; c.len = len + b.len;
        for (j = 0; j < b.len; j++) for (i = 0; i < len; i++)
            c.d[i + j] += d[i] * b.d[j];
        for (i = 0; i < c.len - 1; i++)
            c.d[i + 1] += c.d[i] / 10, c.d[i] %= 10;
        c.clean();
        return c;
    }
    highprecision operator / (const highprecision& b) {
        int i, j;
        highprecision c = *this, a = 0;
        for (i = len - 1; i >= 0; i--)
        {
            a = a * 10 + d[i];
            for (j = 0; j < 10; j++) if (a < b * (j + 1)) break;
            c.d[i] = j;
            a = a - b * j;
        }
        c.clean();
        return c;
    }
    highprecision operator % (const highprecision& b) {
        int i, j;
        highprecision a = 0;
        for (i = len - 1; i >= 0; i--)
        {
            a = a * 10 + d[i];
            for (j = 0; j < 10; j++) if (a < b * (j + 1)) break;
            a = a - b * j;
        }
        return a;
    }
    highprecision operator += (const highprecision& b) {
        *this = *this + b;
        return *this;
    }

    bool operator <(const highprecision& b) const {
        if (len != b.len) return len < b.len;
        for (int i = len - 1; i >= 0; i--)
            if (d[i] != b.d[i]) return d[i] < b.d[i];
        return false;
    }
    bool operator >(const highprecision& b) const { return b < *this; }
    bool operator<=(const highprecision& b) const { return !(b < *this); }
    bool operator>=(const highprecision& b) const { return !(*this < b); }
    bool operator!=(const highprecision& b) const { return b < *this || *this < b; }
    bool operator==(const highprecision& b) const { return !(b < *this) && !(b > *this); }

    string str() const {
        char s[maxn] = {};
        for (int i = 0; i < len; i++) s[len - 1 - i] = d[i] + '0';
        return s;
    }
};

istream& operator >> (istream& in, highprecision& x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}

ostream& operator << (ostream& out, const highprecision& x)
{
    out << x.str();
    return out;
}