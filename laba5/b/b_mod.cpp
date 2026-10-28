#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <algorithm>
using namespace std;

const int m = 7;

//Красивый вывод матрицы: рамка, номера строк и столбцов,
//элементы главной диагонали выделены квадратными скобками
void printMatrix(int P[m][m], const char* title) {
    cout << title << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                cout << "[" << setw(3) << P[i][j] << "]";   // диагональ
            } else {
                cout << " " << setw(3) << P[i][j] << " ";
            }
        }
        cout << " " << endl;
    }
}

int main() {
    int P[m][m];

    //Генератор случайных чисел (как в методичке): диапазон [-25, 25]
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(-25, 25);

    //Заполнение матрицы
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            P[i][j] = dist(gen);
        }
    }

    printMatrix(P, "Source matrix:");

    //Обработка: в каждой строке наибольший элемент меняем с диагональным
    for (int i = 0; i < m; i++) {
        int k = max_element(P[i], P[i] + m) - P[i]; //k - индекс максимума в строке i
        swap(P[i][k], P[i][i]);                     //P[i][i] - элемент главной диагонали
    }

    printMatrix(P, "Result matrix:");

    return 0;
}