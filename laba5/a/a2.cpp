#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

int main() {
    //Размер массива должен быть известен при компиляции,
    //поэтому задаём максимум, а реальную длину m вводит пользователь
    const int MAX_SIZE = 100;
    int Y[MAX_SIZE];
    int m;

    //Ввод длины вектора с проверкой
    do {
        cout << "Enter length m (from 1 to " << MAX_SIZE << "): ";
        cin >> m;
        if (cin.fail()) { 
            cin.clear();
            cin.ignore();
            m = 0;
        }
        if (m < 1 || m > MAX_SIZE) {
            cout << "Error! Length must be from 1 to " << MAX_SIZE << "." << endl;
        }
    } while (m < 1 || m > MAX_SIZE);

    //Генератор случайных чисел (как в методичке): диапазон [-25, 25]
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(-25, 25);

    //Заполнение и вывод исходного вектора
    cout << "Source vector:" << endl;
    for (int i = 0; i < m; i++) {
        Y[i] = dist(gen);
        cout << Y[i] << " ";
    }
    cout << endl;

    // 1) ищем максимум и ставим его на первое место
    int imax = max_element(Y, Y + m) - Y; //индекс максимального элемента
    swap(Y[0], Y[imax]);

    // 2) ищем минимум (уже в изменённом векторе) и ставим его на последнее место
    int imin = min_element(Y, Y + m) - Y; //индекс минимального элемента
    swap(Y[m - 1], Y[imin]);

    //Вывод результата
    cout << "Result:" << endl;
    for (int i = 0; i < m; i++) {
        cout << Y[i] << " ";
    }
    cout << endl;

    return 0;
}