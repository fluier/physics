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
		void setM(int start...);
		/// operators
		mat operator+(const mat &b);
		mat operator-(const mat &b);
		mat operator*(const mat &b);
		/// functions on matrix
		mat transpose();
		mat minorPrincipal(int dim);

		friend std::ostream &operator<<(std::ostream &output, const mat& m);
	};
}