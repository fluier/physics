#pragma once

#include<iostream>

namespace Adina {
	struct mat {
		int dim;
		float **m;

		mat();
		mat(int dim);
		~mat();
		void setIdentity();
		// setM('t', and your parameters)
		void setM(float** v);
		void setM(int dim, float** v);
		/// operators
		mat &operator=(const mat &b);
		mat operator+(const mat &b);
		mat operator-(const mat &b);
		mat operator*(const mat &b);
		bool operator==(const mat&b);
		/// functions on matrix
		mat transpose();
		mat minorPrincipal(int dim);
		mat getMat(int ic) const;
		mat getMat(int ic,int jl) const;
		float det2x(const mat& b);
		float det(const mat& b);
		mat cofactor();
		mat inverse();
		friend std::ostream &operator<<(std::ostream &output, const mat& m);
	};
}