#include "operators.h"

Adina::vec & operator*(const Adina::mat & a, const Adina::vec & b)
{
	Adina::vec* rez = new Adina::vec(a.dim);
	float sum = 0;
	for (int i = 0; i < a.dim; i++) {
		for (int j = 0; j < a.dim; j++) {
			sum+= a.m[j][i] * b.v[j];
		}
		rez->v[i] = sum;
		sum = 0;
	}
	return *rez;
}
