//задание 1. Решить СЛАУ методом Гаусса с выбором главного элемента

#include <iostream>
#include <math.h>
using namespace std;

void print(double** mas, int num, int* index) {
	for (int i = 0; i < num; i++) {
		cout << "x" << index[i] << "\t";
	}
	cout << endl;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num + 1; j++) {
			if (mas[i][j] == -0) cout << 0 << "\t"; else cout << mas[i][j] << "\t";
			if (j == num - 1) cout << "|\t";
		}
		cout << endl;
	}
	cout << endl << endl;
}
int divisionStr(double** mas, int num, int str, double value, int*& index) {
	if (value == 0) return 0;
	for (int i = 0; i < num + 1; i++) mas[str][i] /= value;
	if (value != 1) print(mas, num, index);
	return 0;

}
void subtractionMas(double** mas, int num, int str, double value) {
	double temp;
	for (int i = 0; i < num; i++) {
		if (i != str) {
			temp = mas[i][str];
			for (int j = str; j < num + 1; j++) {
				mas[i][j] -= mas[str][j] * temp;
			}
		}
	}
}
void deform(double**& mas, int& num, int str, int*& index) {
	for (int i = 0; i < num; i++) {
		for (int j = str; j < num; j++) {
			swap(mas[i][j], mas[i][j + 1]);
		}
	}
	for (int j = str; j < num; j++) {
		swap(index[j], index[j + 1]);
	}
	num--;
	print(mas, num, index);
}
void swapStr(double**& mas, int& num, int str, int rerecursion, int*& index) {
	if (mas[str][str] == 0) {
		for (int i = str; i < num - 1; i++) {
			for (int j = i; j < num + 1; j++) {
				swap(mas[i][j], mas[i + 1][j]);
			}
		}
		if (mas[str][str] == 0 && rerecursion != num - str) swapStr(mas, num, str, rerecursion + 1, index);
		if (mas[str][str] == 0 && rerecursion == num - str) deform(mas, num, str, index);
	}
}
void maxcolum(double**& mas, int& num, int str, int*& index) {
	int temp = str;
	for (int i = str; i < num; i++) {
		if (fabs(mas[i][str]) > fabs(mas[temp][str])) temp = i;
	}
	if (mas[temp][str] == 0) swapStr(mas, num, str, 0, *&index);
	if (temp != str) {
		for (int i = str; i < num + 1; i++) {
			swap(mas[str][i], mas[temp][i]);
		}
		print(mas, num, index);
	}
}

int main() {
	cout.precision(3);
	int num;
	cin >> num;
	bool run = true;
	double** mas;
	mas = new double* [num];
	for (int i = 0; i < num + 1; i++) mas[i] = new double[num];
	for (int i = 0; i < num; i++) for (int j = 0; j < num + 1; j++) cin >> mas[i][j];



	int* index = new int[num];
	for (int i = 0; i < num; i++) index[i] = i + 1;

	print(mas, num, index);

	//////////////////////////////////////////////// приводим к диагональному виду
	for (int i = 0; i < num && run; i++) {

		maxcolum(mas, num, i, index); // находим максимальный элемент в столбце и ставим его на главную диагональ
		//swapStr(mas, num, i, 0, index); //делаем циклический сдвиг по строкам, если мешает ноль. Если весь столбец из нулей, то сокращяем матрицу (deform)



		divisionStr(*&mas, num, i, mas[i][i], index); //делаем единицу в строке
		subtractionMas(*&mas, num, i, mas[i][i]); //отнимаем все последующие строки
		print(mas, num, index); //выводим массив на экран
	}


	system("pause");
	return 0;
}

//3 1.24 -0.87 -3.17 0.46 2.11 -0.45 1.44 1.5 0.48 1.25 -0.63 0.35