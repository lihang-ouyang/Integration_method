#include <iostream>

using namespace std;

// �Q�n����� f(x) = -x^2 + 16
double f(double x) {
    return -x * x + 16;
}

// �U�x�Ρ]�����I�^
double lower(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 0; i < n; i++) {//i=0
        double xi = a + i * h;//i=0�ɨ�����(lower)
        sum += f(xi);//
    }
    return sum * h;
}

// �W�x�Ρ]�k���I�^
double upper(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 1; i <= n; i++) {//i=1
        double xi = a + i * h;//i=1�ɨ��k��(upper)
        sum += f(xi);
    }
    return sum * h;
}

// ���x�Ρ]���I�^
double center(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        double mid = a + (i + 0.5) * h;//+0.5������
        sum += f(mid);
    }
    return sum * h;
}

// ��Ϊk
double stair(double a, double b, int n) {
    double h = (b - a) / n;//�C�@�q���e��(��)
    double sum = f(a) + f(b);//�W��+�U��
    for (int i = 1; i < n; i++) {
        double xi = a + i * h;
        sum += 2 * f(xi);//(x=-4��0�[�W0��+4)
    }
    return (h / 2) * sum;
}

int main() {
    double a = -4;  // �n���U��
    double b = 4;   // �n���W��
    int n = 10;    //���Φ���

    for (int i = 0; i < 3; i++) {
        cout << "����" << n << "�ӵ��e�϶�" << endl;
        cout << "��� f(x) = -x^2 + 16 �b [" << a << ", " << b << "] ���ƭȿn�����G�G" << endl;
        cout << "�U�x�Ρ]�����I�^�G  " << lower(a, b, n) << endl;
        cout << "�W�x�Ρ]�k���I�^�G  " << upper(a, b, n) << endl;
        cout << "���x�Ρ]���I�^�G    " << center(a, b, n) << endl;
        cout << "��Ϊk�G            " << stair(a, b, n) << endl<<endl;
        n = n * n;
    }

    system("pause");
    return 0;
}
