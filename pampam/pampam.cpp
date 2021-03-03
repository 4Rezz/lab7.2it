#include <iostream>
#include <iomanip>
#include <time.h>


using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int Max(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));

	int Low = 1; // мінімальне число в массиві
	int High = 50; // максимальне число в массиві
	int rowCount; // рядки масиву
	int colCount; // колонки масиву
	cout << "k = "; cin >> rowCount;
	cout << "n = "; cin >> colCount;


	int** a = new int* [rowCount]; // обявляється динамічна матриця
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	int RowsMax = Max(a, rowCount, colCount); // RowsMax приймає в себе результат обчислення в функціїї Max
	cout << RowsMax << endl; // виводиться результат 
	for (int i = 0; i < rowCount; i++) // звільнюється пам'ять, оскільки масив a більше не потрібен
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int Max(int** a, const int rowCount, const int colCount)
{
	int max, sum = 0;
	for (int i = 0; i < rowCount; i++) // перевіряються рядки матриці
	{
		{
			max = a[i][0];
			for (int j = 1; j < colCount; j++) { // перевіряються колонки матриці
				if (a[i][j] > max) { // перевіряється кожне число в данному рядку 
					max = a[i][j]; // визначається максимальне
				}
			}
			sum += max; // максимальне добавляється до суми всіх максимальних
		}
	}
	return sum; // повертається сума максимальних чисел
}