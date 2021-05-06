#include <iostream>
#include <cmath>
double countF(double x) {
	return abs(5*cos(3*x)+3);
}

int main() {
	std::cout << "Matrix С:\n\n";
	double h = 4. / 20;
	double matrixC[19][19];
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (i == j) {
				matrixC[i][j] = 2 * h / 3;
			}
			if (j == i + 1) {
				matrixC[i][j] = h / 6;
			}
			if (j == i - 1) {
				matrixC[i][j] = h / 6;
			}
		}
	}

	double xVector[21];
	for (size_t i = 0; i < 21; i++)
	{
		xVector[i] = -2 + i * h;
	}
	std::cout << "\nMatrix d:\n";
	double matrixD[20];
	for (int i = 1; i < 20; i++)
	{
		double temp = (countF(xVector[i + 1]) - countF(xVector[i])) / h - (countF(xVector[i]) - countF(xVector[i - 1])) / h;
		matrixD[i] = temp;
	}

	//Gaussian method with selection of the main element by column

	double matrixA2[19][19];
	for (int i = 0; i < 19; i++)
	{
		for (int k = 0; k < 19; k++)
		{
			matrixA2[i][k] = matrixC[i][k];
		}
	}

	double matrixF2[19];
	for (int i = 0; i < 19; i++)
	{
		matrixF2[i] = matrixD[i];
	}
	int swaps = 0;
	for (int k = 0; k < 19; k++)
	{
		int j = k;

		for (int i = k + 1; i < 19; i++)
		{
			double max = matrixA2[k][k];
			if (abs(max) < abs(matrixA2[i][k])) {
				max = matrixA2[i][k];
				j = i;
			}
		}
		//swap strings
		if (j != k)
		{
			swaps++;
			double temp = matrixF2[k];
			matrixF2[k] = matrixF2[j];
			matrixF2[j] = temp;
			for (int i = k; i < 19; i++)
			{
				temp = matrixA2[k][i];
				matrixA2[k][i] = matrixA2[j][i];
				matrixA2[j][i] = temp;
			}
		}
		for (int i = k + 1; i < 19; i++)
		{
			double l = matrixA2[i][k] / matrixA2[k][k];
			matrixF2[i] = matrixF2[i] - l * matrixF2[k];
			for (int j = k + 1; j < 19; j++)
			{
				matrixA2[i][j] = matrixA2[i][j] - (l * matrixA2[k][j]);
			}
		}

	}

	//reverse motion

	double matrixX2[19];
	matrixX2[18] = matrixF2[18] / matrixA2[18][18];

	for (int i = 18; i >= 0; i--)
	{
		double gauss = 0;
		int k = 19 - i;
		for (int j = 0; j < k - 1; j++)
		{
			gauss += matrixA2[i][18 - j] * matrixX2[18 - j];
		}
		matrixX2[i] = (matrixF2[i] - gauss) / matrixA2[i][i];
	}
	std::cout << "\n\n";
	std::cout.setf(std::ios::fixed);
	std::cout.precision(5); //0 - число символов после точки
	double m[21];
	m[0] = 0;
	m[20] = 0;
	for (size_t i = 1; i < 20; i++)
	{
		m[i] = matrixX2[i - 1];
	}
	for (size_t i = 1; i < 21; i++)
	{
		std::cout << m[i - 1] / (6 * h) << "(" << xVector[i] << "-x)^3+" << m[i] / (6 * h) << "(x-" << xVector[i - 1] << ")^3+" << (countF(xVector[i - 1]) - h * h / 6 * m[i - 1]) / h << "(" << xVector[i] << "-x)+" << (countF(xVector[i]) - h * h / 6 * m[i]) / h << "(x-" << xVector[i - 1] << ")\n";
	}
	system("pause");
	return 0;
}