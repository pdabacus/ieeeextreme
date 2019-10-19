#include <iostream>

using namespace std;

int main() {
    long int a, b;
    cin >> a >> b;
    if (2*a <= b) {
        cout << a;
    }
    else if (2*b <= a) {
        cout << b;
    }
    else {
        cout << (a+b)/3;
    }
    return 0;
}
