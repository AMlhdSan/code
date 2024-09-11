#include <bits/stdc++.h>
using namespace std;

int T, M;
int a, b, c;

int pd(int x) {
    for(int i = sqrt(x) + 1; i >= 1; --i) {
        if(x % (i * i) == 0) {
            return i;
        }
    }
}

int main() {

    
    cin >> T >> M;

    while(T--) {
        cin >> a >> b >> c;
        
        int delta;

        delta = b * b - 4 * a * c;

        if(delta < 0) {
            cout << "NO";
        }
        else if(delta == 0) {
            if(b == 0) {
                cout << 0;
            }
            else if(a * b > 0) {
                a = abs(a);
                b = abs(b);
                cout << "-";
                if(b % (2 * a) == 0) {
                    cout << b / 2 / a;
                }
                else {
                    cout << b / __gcd(2 * a, b) << "/" << (2 * a) / __gcd(2 * a, b);
                }
            }
            else {
                a = abs(a);
                b = abs(b);
                if(b % (2 * a) == 0) {
                    cout << b / 2 / a;
                }
                else {
                    cout << b / __gcd(2 * a, b) << "/" << (2 * a) / __gcd(2 * a, b);
                }
            }
        }
        else {
            if(a < 0) {
                int mother = - 2 * a;
                int x = pd(delta);
                int y = delta / x / x;
                if(b == 0) {
                    mother = abs(mother);
                    if(y == 1) {
                        if(x == mother) {
                            cout << "1";
                        }
                        else if(x % mother == 0) {
                            cout << x / mother;
                        }
                        else {
                            cout << x / __gcd(x, mother) << "/" << mother / __gcd(x, mother);
                        }
                    }
                    else {
                        if(x == mother) {
                            cout << "sqrt(" << y << ")";
                        }
                        else if(mother % x == 0) {
                            cout << "sqrt(" << y << ")";
                            cout << "/" << mother / x;
                        }
                        else if(x % mother == 0) {
                            cout << x / mother << "*sqrt(" << y << ")";
                        }
                        else {
                            cout << x / __gcd(x, mother) << "*sqrt(" << y << ")" << "/" << mother / __gcd(x, mother);
                        }
                    }
                }
                else if(y == 1) { // 不需要sqrt
                    // 说明可以合并为同一个式子
                    int son = - b - x;
                    if(son == 0) {
                        cout << 0;
                    }
                    else if(son * mother < 0) { // 如果分子分母同号.
                        son = abs(son);
                        mother = abs(mother);
                        if(son % mother == 0) {
                            cout << son / mother;
                        }
                        else {
                            cout << son / __gcd(son, mother) << "/" << mother / __gcd(son, mother);
                        }
                    }
                    else { // 如果分子分母异号.
                        son = abs(son);
                        mother = abs(mother);
                        cout << "-";
                        if(son % mother == 0) {
                            cout << son / mother;
                        }
                        else {
                            cout << son / __gcd(son, mother) << "/" << mother / __gcd(son, mother);
                        }
                    }
                }
                else { // 需要sqrt.
                    // 1. 先输出前面的
                    if(b > 0) { // 不需要负号
                        b = abs(b);
                        mother = abs(mother);
                        if(b % mother == 0) {
                            cout << b / mother;
                        }
                        else {
                            cout << b / __gcd(b, mother) << "/" << mother / __gcd(b, mother);
                        }
                    }
                    else { // 需要负号
                        b = abs(b);
                        mother = abs(mother);
                        cout << "-";
                        if(b % mother == 0) {
                            cout << b / mother;
                        }
                        else {
                            cout << b / __gcd(b, mother) << "/" << mother / __gcd(b, mother);
                        }
                    }
                    // 2. 输出sqrt部分(不管怎样都是+)
                    cout << "+";
                    if(x == 1) { // 不需要输出前缀.
                        cout << "sqrt(" << y << ")";
                        cout << "/" << - 2 * a;
                    }
                    else {
                        if(x == mother) {
                            cout << "sqrt(" << y << ")";
                        }
                        else if(x % mother == 0) {
                            cout << x / mother << "*sqrt(" << y << ")";
                        }
                        else if(mother % x == 0) {
                            cout << "sqrt(" << y << ")";
                            cout << "/" << mother / x;
                        }
                        else {
                            cout << x / __gcd(x, mother);
                            cout << "*sqrt(" << y << ")";
                            cout << "/" << mother / __gcd(x, mother);
                        }
                    }
                }
            }
            else {
                int mother = 2 * a;
                int x = pd(delta);
                int y = delta / x / x;
                if(b == 0) {
                    mother = abs(mother);
                    if(y == 1) {
                        if(x == mother) {
                            cout << "1";
                        }
                        else if(x % mother == 0) {
                            cout << x / mother;
                        }
                        else {
                            cout << x / __gcd(x, mother) << "/" << mother / __gcd(x, mother);
                        }
                    }
                    else {
                        if(x == mother) {
                            cout << "sqrt(" << y << ")";
                        }
                        else if(mother % x == 0) {
                            cout << "sqrt(" << y << ")";
                            cout << "/" << mother / x;
                        }
                        else if(x % mother == 0) {
                            cout << x / mother << "*sqrt(" << y << ")";
                        }
                        else {
                            cout << x / __gcd(x, mother) << "*sqrt(" << y << ")" << "/" << mother / __gcd(x, mother);
                        }
                    }
                }
                else if(y == 1) { // 不需要sqrt
                    // 说明可以合并为同一个式子
                    int son = - b + x;
                    if(son == 0) {
                        cout << 0;
                    }
                    else if(son * mother > 0) { // 如果分子分母同号.
                        son = abs(son);
                        mother = abs(mother);
                        if(son % mother == 0) {
                            cout << son / mother;
                        }
                        else {
                            cout << son / __gcd(son, mother) << "/" << mother / __gcd(son, mother);
                        }
                    }
                    else { // 如果分子分母异号.
                        son = abs(son);
                        mother = abs(mother);
                        cout << "-";
                        if(son % mother == 0) {
                            cout << son / mother;
                        }
                        else {
                            cout << son / __gcd(son, mother) << "/" << mother / __gcd(son, mother);
                        }
                    }
                }
                else { // 需要sqrt.
                    // 1. 先输出前面的
                    if(b * mother < 0) { // 不需要负号
                        b = abs(b);
                        mother = abs(mother);
                        if(b % mother == 0) {
                            cout << b / mother;
                        }
                        else {
                            cout << b / __gcd(b, mother) << "/" << mother / __gcd(b, mother);
                        }
                    }
                    else { // 需要负号
                        b = abs(b);
                        mother = abs(mother);
                        cout << "-";
                        if(b % mother == 0) {
                            cout << b / mother;
                        }
                        else {
                            cout << b / __gcd(b, mother) << "/" << mother / __gcd(b, mother);
                        }
                    }
                    // 2. 输出sqrt部分(不管怎样都是+)
                    cout << "+";
                    if(x == 1) { // 不需要输出前缀.
                        cout << "sqrt(" << y << ")";
                        cout << "/" << 2 * a;
                    }
                    else {
                        mother = 2 * a;
                        if(x == mother) {
                            cout << "sqrt(" << y << ")";
                        }
                        else if(x % mother == 0) {
                            cout << x / mother << "*sqrt(" << y << ")";
                        }
                        else if(mother % x == 0) {
                            cout << "sqrt(" << y << ")";
                            cout << "/" << mother / x;
                        }
                        else {
                            cout << x / __gcd(x, mother);
                            cout << "*sqrt(" << y << ")";
                            cout << "/" << mother / __gcd(x, mother);
                        }
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}