#include"mat.h"
#include<math.h>
#include<stdarg.h>
#include<iostream>

namespace Adina {
	mat::mat() {

	}
	mat::mat(int dim)
	{
		this->dim = dim;
		m = new float*[dim];
		for (int i = 0; i < dim; i++) {
			m[i] = new float[dim];
		}
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				m[i][j] = 0;
			}
		}
	}
	mat::~mat() {
		if (dim > 0) {
			for (int i = 0; i < dim; i++) {
				delete m[i];
			}
			delete m;
		}
	}
	void mat::setIdentity()
	{
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				if( i == j) m[i][j] = 1;
				else m[i][j] = 0;
			}
		}
	}
	void mat::setM(int start...)
	{
		va_list ap;
		start = 0;
		va_start(ap, start);
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				this->m[i][j] = va_arg(ap, double);
			}
		}
		va_end(ap);
	}
	mat mat::operator+(const mat & b)
	{
		mat* rez = new mat(dim);
		if (dim == b.dim) {
			for (int i = 0; i < dim; i++) {
				for (int j = 0; j < dim; j++) {
					rez->m[i][j] = m[i][j] + b.m[i][j];
				}
			}
		}
		return *rez;
	}
	mat mat::operator-(const mat & b)
	{
		mat* rez = new mat(dim);
		if (dim == b.dim) {
			for (int i = 0; i < dim; i++) {
				for (int j = 0; j < dim; j++) {
					rez->m[i][j] = m[i][j] - b.m[i][j];
				}
			}
		}
		return *rez;
	}
	mat mat::operator*(const mat & b)
	{
		float sum = 0;
		mat* rez = new mat(dim);
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				for (int k = 0; k < dim; k++) {
					sum = sum + m[i][k] * b.m[k][j];
				}
				rez->m[i][j] = sum;
				sum = 0;
			}
		}

		return *rez;
	}
	bool mat::operator==(const mat & b)
	{
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				if (m[i][j] != b.m[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	mat mat::transpose()
	{
		mat* rez = new mat(dim);
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				rez->m[i][j] = m[j][i];
			}
		}
		return *rez;
	}
	mat mat::minorPrincipal(int idim)
	{
		if (dim == 0) { dim = 1; }/// only a check for some safty
		mat* rez = new mat(idim);
		for (int i = 0; i < idim; i++) {
			for (int j = 0; j < idim; j++) {
				rez->m[i][j] = m[i][j];
			}
		}
		return *rez;
	}
	mat mat::getMat(int jr) const
	{
		mat* rez = new mat(dim - 1);

		for (int i = 0; i < rez->dim; i++) {
			for (int j = 0; j < rez->dim; j++) {
				if (j < jr) {
					rez->m[i][j] = m[i + 1][j];
				}else{
					rez->m[i][j] = m[i + 1][j + 1];
				}
			}
		}
		return *rez;
	}
	float mat::det2x(const mat & b)
	{
		float rez = b.m[0][0] * b.m[1][1] - b.m[0][1] * b.m[1][0];
		return rez;
	}
	float mat::det(const mat & b)
	{
		float rez = 0;
		if (b.dim == 2) {
			rez += det2x(b);
		}else{
			for (int i = 0; i < b.dim; i++) {
				mat aux = b.getMat(i);
				if ((i + 1) % 2 == 0) {
					rez += +b.m[0][i] * det(aux);
				}
				else {
					rez -= +b.m[0][i] * det(aux);
				}
			}
		}
		return rez;
	}
	mat mat::inverse()
	{
		return mat();
	}
	std::ostream & operator<<(std::ostream & output, const mat & m)
	{
		for (int i = 0; i < m.dim; i++) {
			output << std::endl;
			for (int j = 0; j < m.dim; j++) {
				output << m.m[i][j] << ", ";
			}
		}
		return output;
	}
}