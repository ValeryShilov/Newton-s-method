#include <iostream>
#include <cmath>
using namespace std;
double f(double n) {
    return pow(n, 3) + 47 * n - 15;  //уравнение
}
double fp(double n) {
    return 3 * pow(n, 2) + 47;      //производная
}
double fpp(double n) {
    return 6 * n;                  //вторая производная
}
int main()
{
    setlocale(LC_ALL, "Rus");
    float a, b, e, x1 = 0.0, x2 = 0.0;
    int cnt = 0;
    bool flag = 1;
    cin >> a >> b >> e;
    if (f(a) * fpp(a) >= 0) {
        x1 = a;
    }
    else {
        if (f(b) * f(a) >= 0) {
            x1 = b;
        }
        else {
            cout << "На заданном промежутке корней нет" << endl;
            flag = 0;
        }
    }
    if (flag = 1){ 
        do {
            x1 = x2;
            x2 = x1 - (f(x1) / fp(x1));
            cnt++;
        } while (abs(x1 - x2) > e);
        cout << "x = " << x1 << endl;
        cout << "Количество итераций = " << cnt << endl;
    }
    return 0;
}
