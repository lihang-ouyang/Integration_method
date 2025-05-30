#include <iostream>

using namespace std;

// 被積分函數 f(x) = -x^2 + 16
double f(double x) {
    return -x * x + 16;
}

// 下矩形（左端點）
double lower(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 0; i < n; i++) {//i=0
        double xi = a + i * h;//i=0時取左邊(lower)
        sum += f(xi);//
    }
    return sum * h;
}

// 上矩形（右端點）
double upper(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 1; i <= n; i++) {//i=1
        double xi = a + i * h;//i=1時取右邊(upper)
        sum += f(xi);
    }
    return sum * h;
}

// 中矩形（中點）
double center(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        double mid = a + (i + 0.5) * h;//+0.5取中間
        sum += f(mid);
    }
    return sum * h;
}

// 梯形法
double stair(double a, double b, int n) {
    double h = (b - a) / n;//每一段的寬度(高)
    double sum = f(a) + f(b);//上底+下底
    for (int i = 1; i < n; i++) {
        double xi = a + i * h;
        sum += 2 * f(xi);//(x=-4到0加上0到+4)
    }
    return (h / 2) * sum;
}

int main() {
    double a = -4;  // 積分下限
    double b = 4;   // 積分上限
    int n = 10;    //切割次數

    for (int i = 0; i < 3; i++) {
        cout << "切成" << n << "個等寬區間" << endl;
        cout << "函數 f(x) = -x^2 + 16 在 [" << a << ", " << b << "] 的數值積分結果：" << endl;
        cout << "下矩形（左端點）：  " << lower(a, b, n) << endl;
        cout << "上矩形（右端點）：  " << upper(a, b, n) << endl;
        cout << "中矩形（中點）：    " << center(a, b, n) << endl;
        cout << "梯形法：            " << stair(a, b, n) << endl<<endl;
        n = n * n;
    }

    system("pause");
    return 0;
}
