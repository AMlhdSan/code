#include <iostream>

#include <cmath>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int count = 0;  // 记录操作次数
    int p = 1;      // 处理每一位时的进位权值（个位，十位，百位...）

    while (a > 0 || b > 0) {
        int digit_a = a % 10;  // 获取a的当前最低位
        int digit_b = b % 10;  // 获取b的当前最低位

        int diff = abs(digit_a - digit_b);  // 计算两位的差值
        int cnt = 0;
        if (diff != 0) {
            // 如果差值不为0，说明需要一次操作使两位的差值归零
            count += diff;
        }
        
        // 去掉当前位，处理下一位
        a /= 10;
        b /= 10;
    }

    cout << count << endl;  // 输出操作次数
    return 0;
}
