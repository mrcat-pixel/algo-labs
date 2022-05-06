#include <iostream>
#include <cmath>

using namespace std;

double process() {
    uint16_t a, b, c, d;
    uint64_t k;

    cin >> a >> b >> c >> d >> k;

    if (a*(b-1) == c) return a;

    int64_t res = a;

    for (uint16_t i = 0; i < k; i++) {
        res = res*b - c;
        if (res >= d) return d;
        if (res <= 0) return 0;
    }
    return res;
}

int main() {
    cout << process();
}