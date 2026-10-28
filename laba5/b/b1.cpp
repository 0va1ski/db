#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
using namespace std;

int main() {
    const int m = 7;
    int P[m][m];

    //Генератор случайных чисел (как в методичке): диапазон [-25, 25]
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(-25, 25);

    //Заполнение и вывод исходной матрицы
    cout << "Source matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            P[i][j] = dist(gen);
            cout << P[i][j] << " ";
        }
        cout << endl;
    }

    //Обработка: в каждой строке наибольший элемент меняем с диагональным
    for (int i = 0; i < m; i++) {
        int k = 0;                       // k - индекс максимума в строке i
        for (int j = 1; j < m; j++) {
            if (P[i][j] > P[i][k]) k = j;
        }
        swap(P[i][k], P[i][i]);          // P[i][i] - элемент главной диагонали
    }

    //Вывод результата
    cout << "Result matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << P[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}