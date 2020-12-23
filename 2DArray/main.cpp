#include <iostream> 
#include <iomanip>
#include <ctime>

using namespace std;


int** formMatrix(int n, int m);
void printMatrix(int** matrix, int n, int m);
void fillMatrix(int** matrix, int n, int m);
void deleteMatrix(int** matrix, int n, int m);
void changeRowColumn(int** matrix, int n, int m, int k); // task 11
int getRowNumWithMaxAvg(int** matrix, int n, int m);
void fillNull(int** matrix, int n, int m);

int main() {
	srand(time(NULL));
	// task 11 - поменять местами указанные столбец и строку
	int size1 = 5;
	int index = 2; // номер строки/столбца для замены
	int** matrix1 = formMatrix(size1, size1);
	fillMatrix(matrix1, size1, size1);
	cout << "Initial martix: " << endl;
	printMatrix(matrix1, size1, size1);
	changeRowColumn(matrix1, size1, size1, index);
	cout << "Matrix after change " << index + 1 
		<< "row and column" << endl;
	printMatrix(matrix1, size1, size1);
	deleteMatrix(matrix1, size1, size1);


	// task 10 - найти номер строки, для которой средее 
	// арифметическое элементов строки наибольшее
	int size2 = 3;
	int** matrix2 = formMatrix(size2, size2);
	fillMatrix(matrix2, size2, size2);
	cout << "Martix: " << endl;
	printMatrix(matrix2, size2, size2);
	int index1 = getRowNumWithMaxAvg(matrix2, size2, size2);
	cout << "Row index with max average: " << index1 + 1 << endl;

	// img task
	int size3 = 6;
	int** matrix3 = formMatrix(size3, size3);
	fillMatrix(matrix3, size3, size3);
	cout << "Martix: " << endl;
	printMatrix(matrix3, size3, size3);
	cout << "Fill with nulls" << endl;
	fillNull(matrix3, size3, size3);
	printMatrix(matrix3, size3, size3);

	return 0;
}

int** formMatrix(int n, int m)
{
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	return arr;
}

void printMatrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(5) << matrix[i][j];
		}
		cout << endl;
	}
}

void fillMatrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrix[i][j] = rand() % 101; 
		}
	}
}

void deleteMatrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++) {
		delete matrix[i]; // delete[] matrix[i]
	}
	delete matrix; // delete[] matrix; 
}

void changeRowColumn(int** matrix, int n, int m, int k)
{
	for (int i = 0; i < n; i++) {
		int tmp = matrix[k][i];
		matrix[k][i] = matrix[i][k];
		matrix[i][k] = tmp;
	}
	/*
	for (int i = 0; i < n; i++) {
		if (i != k) {
			int tmp = matrix[k][i];
			matrix[k][i] = matrix[i][k];
			matrix[i][k] = tmp;
		}
	}
	*/
}

int getRowNumWithMaxAvg(int** matrix, int n, int m)
{
	int rowIndex = 0;
	double max = -9999;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum += matrix[i][j];
		}
		double avg = sum / m; // avg
		if (avg > max) {
			max = avg;
			rowIndex = i;
		}
	}
	return rowIndex;
}

void fillNull(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// picture 5 

			//if (i < n / 2 && (j >= i && j <= n - 1- i)) {
			//	matrix[i][j] = 0;
			//}
			//else if (i >= n / 2 && (j >= n - 1 - i
			//	&& j <= i)){
			//	matrix[i][j] = 0;
			//}

			// picture 6

			if (j < n / 2 && (j <= i && j <= n - 1 - i)) {
				matrix[i][j] = 0;
			}
			else if (j >= n / 2 && (j <= n - 1 - i
				&& j >= i)) {
				matrix[i][j] = 0;
			}
		}
	}
}


