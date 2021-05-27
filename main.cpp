#include<iostream>
#include <vector>
#include <cmath>
double fx1(double x) {
	return 1. / (log(pow(x, 2) + x + 1));
}
double iTrap(double a, double b,int n) {
	double h = (b - a) * 1. / n;
	std::vector<double> xVector;
	for (int i = 0; i < n; i++)
	{
		xVector.push_back(a + i * h);
	}
	double I=0;
	for (size_t i = 0; i < n-1; i++)
	{

		I += fx1(xVector[i]);
		I += fx1(xVector[i + 1]);

	}
	return I * h / 2;
}

double iSimpson(double a, double b, int n) {
	double h = (b - a) * 1. / n;
	std::vector<double> xVector;
	for (int i = 0; i < n; i++)
	{
		xVector.push_back(a + i * h);
	}
	double I = 0;
	double middle;
	for (size_t i = 0; i < n - 1; i++)
	{
		middle = (xVector[i] + xVector[i + 1]) / 2;
		I += fx1(xVector[i]);
		I += fx1(xVector[i + 1]);
		I += 4 * fx1(middle);
	}
	return I * h / 6;
}
const double e = 0.000001;
int mTrap = 2;
int mSim = 4;
int main() {
	double h = (3 - 2) / 2.;
	double I1,I2;
	double R;
	int n = 2;
	std::cout << "trapezoid\n";
	while (true) {
		I1 = iTrap(2, 3, n);
		std::cout <<"I1 "<< I1 << "\n";
		n *= 2;
		I2 = iTrap(2, 3, n);
		std::cout <<"I2 "<< I2  << "\n";
		R = abs(I2-I1) / 3;
		std::cout << "R "<<R << "\n";
		if (R<=e) {
			break;
		}
	}
	std::cout << "\n\nSimpson\n";
	n = 2;
	while (true) {
		I1 = iSimpson(2, 3, n);
		std::cout << "I1 " << I1 << "\n";
		n *= 2;
		I2 =iSimpson(2, 3, n);
		std::cout << "I2 " << I2 << "\n";
		R = abs(I2-I1) / 15;
		std::cout << "R " << R << "\n";
		if (R <= e) {
			break;
		}
	}

	std::cout << "\n\nNAST\n\n\n";
	double A1, A2, A3, A4, A5;
	A1 = A5 = 0.2369268851;
	A2 = A4 = 0.4786286705;
	A3 = 0.5688888899;
	std::vector<double> xVector;
	xVector.push_back(-0.9061798459);
	xVector.push_back(-0.5384693101);
	xVector.push_back(0);
	xVector.push_back(0.5384693101);
	xVector.push_back(0.9061798459);
	std::vector<double> aKoef;
	aKoef.push_back(A1);
	aKoef.push_back(A2);
	aKoef.push_back(A3);
	aKoef.push_back(A4);
	aKoef.push_back(A5);
	double I = 0;
	for (int i = 0; i < 5; i++)
	{
		I += aKoef[i] * fx1((1. / 2) * xVector[i] + 2.5);
	}
	I *= (3 - 2) / 2.;
	std::cout << I;
	return 0;
}