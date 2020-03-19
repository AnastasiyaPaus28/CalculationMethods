// lb2(MW).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <iomanip> 

using namespace std;


int main()
{
	SetConsoleOutputCP(1251);

	double array[4][5] = {
	{ 14.4, -5.3, 14.3, -12.7, -14.4 },
	{ 23.4, -14.2, -5.4, 2.1, 6.6 },
	{ 6.3, -13.2, -6.5, 14.3, 9.4 },
	{ 5.6, 8.8, -6.7, -23.8, 7.3 }
	};

	cout << "Исходная матрица: " << endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			cout << setw(10) << array[i][j];
		}
		cout << endl;
	}

	cout << endl;


	double p;

	for (int s = 0; s < 4; s++) {

		cout << "Разделим " << s + 1 << " строку на " << array[s][s] << endl;

		for (int j = s + 1; j < 5; j++) {
			array[s][j] /= array[s][s];
		}
		array[s][s] = 1;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 5; j++) {
				cout << setw(10) << array[i][j];
			}
			cout << endl;
		}
		cout << endl;


		cout << "Вычитаем " << s + 1 << " строку из нижестоящих так, чтобы привести к верхей треугольной матрице: " << endl;

		for (int i = s + 1; i < 4; i++) {
			p = array[i][s];
			for (int j = s; j < 5; j++) {
				array[i][j] -= (array[s][j] * p);
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 5; j++) {
				cout << setw(10) << array[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}


	cout << "Полученная ступенчатая матрица имеет вид: " << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			cout << setw(10) << array[i][j];
		}
		cout << endl;
	}
	cout << endl;

	double* mas = new double[4];
	mas[3] = array[3][4];

	for (int i = 2; i >= 0; i--) {
		mas[i] = array[i][4];
		for (int j = 3; j >= i + 1; j--) {
			mas[i] -= array[i][j] * mas[j];
		}
	}

	cout << "Корни уравнения: " << endl;
	for (int i = 0; i < 4; i++) {
		cout << "X" << (i + 1) << ": " << round(mas[i] * 1000.0) / 1000.0 << endl;
	}

	system("pause");
	return 0;
}