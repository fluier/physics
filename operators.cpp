#include "operators.h"

#include<iostream>

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

Adina::mat& operator*(const Adina::vec & a, const Adina::vec & b)
{
	Adina::mat* rez = 0;
	if (a.dim == b.dim) {
		rez = new Adina::mat(a.dim);
		for (int i = 0; i < rez->dim; i++) {
			for (int j = 0; j < rez->dim; j++) {
				rez->m[i][j] = a.v[i] * b.v[j];
			}
		}
		return *rez;
	}
	return *rez;
}
