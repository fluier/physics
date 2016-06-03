#include"mat.h"

#include<stdarg.h>

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
		if (dim == 0) {
			dim = 1;
		}
		mat* rez = new mat(idim);
		for (int i = 0; i < idim; i++) {
			for (int j = 0; j < idim; j++) {
				rez->m[i][j] = m[i][j];
			}
		}
		return *rez;
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