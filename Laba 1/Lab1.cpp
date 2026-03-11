#include <iostream>
#include <clocale>

using namespace std;

// Расширенный алгоритм Евклида
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long g = extended_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

int main() {
    setlocale(LC_ALL, ".UTF-8");

    long long a, b, c;
    
    if (!(cin >> a >> b >> c)) return 0;

    long long x, y;
    long long g = extended_gcd(a, b, x, y);

    if (c % g != 0) {
        cout << "Impossible" << endl;
    } else {
        x *= (c / g);
        long long step_x = b / g;
        x = ((x % step_x) + step_x) % step_x;
        y = (c - a * x) / b;

       
        cout << x << " " << y << endl;
    }

    // Мои данные после выполнения работа программы
    cout << "\n Дружинин Максим Андреевич" << endl;
    cout << "Группа РПИа о-25" << endl;
    
    getchar();
    while(getchar()!= '\n');

    return 0;
}