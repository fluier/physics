#include "matTest.h"

#include"mat.h"



Adina::mat mat_00, mat_01, mat_02, mat_03;
Adina::mat mat_10, mat_11, mat_12, mat_13;
Adina::mat mat_20, mat_21, mat_22, mat_23;
Adina::mat mat_30, mat_31, mat_32, mat_33;

Adina::mat someMatrix[4][4];

float** initFloatTable(int dim) {
	float** val = new float*[dim];
	for (int i = 0; i < dim; i++) {
		val[i] = new float[dim];
	}
	return val;
}

void initSomeMat() {
	float** val_m00 = initFloatTable(3);
	val_m00[0][0] = 5; val_m00[0][1] = 6; val_m00[0][2] = 7;
	val_m00[1][0] = 9; val_m00[1][1] = 10; val_m00[1][2] = 11;
	val_m00[2][0] = 13; val_m00[2][1] = 14; val_m00[2][2] = 15;
	mat_00.setM(3,val_m00);

	float** val_m01 = initFloatTable(3);
	val_m01[0][0] = 4; val_m01[0][1] = 6; val_m01[0][2] = 7;
	val_m01[1][0] = 8; val_m01[1][1] = 10; val_m01[1][2] = 11;
	val_m01[2][0] = 12; val_m01[2][1] =14; val_m01[2][2] = 15;
	mat_01.setM(3,val_m01);

	float** val_m02 = initFloatTable(3);
	val_m02[0][0] = 4; val_m02[0][1] = 5; val_m02[0][2] = 7;
	val_m02[1][0] = 8; val_m02[1][1] = 9; val_m02[1][2] = 11;
	val_m02[2][0] = 12; val_m02[2][1] = 13; val_m02[2][2] = 15;
	mat_02.setM(3, val_m02);

	float** val_m03 = initFloatTable(3);
	val_m03[0][0] = 4; val_m03[0][1] = 5; val_m03[0][2] = 6;
	val_m03[1][0] = 8; val_m03[1][1] = 9; val_m03[1][2] = 10;
	val_m03[2][0] = 12; val_m03[2][1] = 13; val_m03[2][2] = 14;
	mat_03.setM(3, val_m03);

	float** val_m10 = initFloatTable(3);
	val_m10[0][0] = 1; val_m10[0][1] = 2; val_m10[0][2] = 3;
	val_m10[1][0] = 9; val_m10[1][1] = 10; val_m10[1][2] = 11;
	val_m10[2][0] = 13; val_m10[2][1] = 14; val_m10[2][2] = 15;
	mat_10.setM(3, val_m10);

	float** val_m11 = initFloatTable(3);
	val_m11[0][0] = 0; val_m11[0][1] = 2; val_m11[0][2] = 3;
	val_m11[1][0] = 8; val_m11[1][1] = 10; val_m11[1][2] = 11;
	val_m11[2][0] = 12; val_m11[2][1] = 14; val_m11[2][2] = 15;
	mat_11.setM(3, val_m11);

	float** val_m12 = initFloatTable(3);
	val_m12[0][0] = 0; val_m12[0][1] = 1; val_m12[0][2] = 3;
	val_m12[1][0] = 8; val_m12[1][1] = 9; val_m12[1][2] = 11;
	val_m12[2][0] = 12; val_m12[2][1] = 13; val_m12[2][2] = 15;
	mat_12.setM(3, val_m12);

	float** val_m13 = initFloatTable(3);
	val_m13[0][0] = 0; val_m13[0][1] = 1; val_m13[0][2] = 2;
	val_m13[1][0] = 8; val_m13[1][1] = 9; val_m13[1][2] = 10;
	val_m13[2][0] = 12; val_m13[2][1] = 13; val_m13[2][2] = 14;
	mat_13.setM(3, val_m13);

	float** val_m20 = initFloatTable(3);
	val_m20[0][0] = 1; val_m20[0][1] = 2; val_m20[0][2] = 3;
	val_m20[1][0] = 5; val_m20[1][1] = 6; val_m20[1][2] = 7;
	val_m20[2][0] = 13; val_m20[2][1] = 14; val_m20[2][2] = 15;
	mat_20.setM(3, val_m20);

	float** val_m21 = initFloatTable(3);
	val_m21[0][0] = 0; val_m21[0][1] = 2; val_m21[0][2] = 3;
	val_m21[1][0] = 4; val_m21[1][1] = 6; val_m21[1][2] = 7;
	val_m21[2][0] = 12; val_m21[2][1] = 14; val_m21[2][2] = 15;
	mat_21.setM(3, val_m21);

	float** val_m22 = initFloatTable(3);
	val_m22[0][0] = 0; val_m22[0][1] = 1; val_m22[0][2] = 3;
	val_m22[1][0] = 4; val_m22[1][1] = 5; val_m22[1][2] = 7;
	val_m22[2][0] = 12; val_m22[2][1] = 13; val_m22[2][2] = 15;
	mat_22.setM(3, val_m22);

	float** val_m23 = initFloatTable(3);
	val_m23[0][0] = 0; val_m23[0][1] = 1; val_m23[0][2] = 2;
	val_m23[1][0] = 4; val_m23[1][1] = 5; val_m23[1][2] = 6;
	val_m23[2][0] = 12; val_m23[2][1] = 13; val_m23[2][2] = 14;
	mat_23.setM(3, val_m23);

	float** val_m30 = initFloatTable(3);
	val_m30[0][0] = 1; val_m30[0][1] = 2; val_m30[0][2] = 3;
	val_m30[1][0] = 5; val_m30[1][1] = 6; val_m30[1][2] = 7;
	val_m30[2][0] = 9; val_m30[2][1] = 10; val_m30[2][2] = 11;
	mat_30.setM(3, val_m30);

	float** val_m31 = initFloatTable(3);
	val_m31[0][0] = 0; val_m31[0][1] = 2; val_m31[0][2] = 3;
	val_m31[1][0] = 4; val_m31[1][1] = 6; val_m31[1][2] = 7;
	val_m31[2][0] = 8; val_m31[2][1] = 10; val_m31[2][2] = 11;
	mat_31.setM(3, val_m31);

	float** val_m32 = initFloatTable(3);
	val_m32[0][0] = 0; val_m32[0][1] = 1; val_m32[0][2] = 3;
	val_m32[1][0] = 4; val_m32[1][1] = 5; val_m32[1][2] = 7;
	val_m32[2][0] = 8; val_m32[2][1] = 9; val_m32[2][2] = 11;
	mat_32.setM(3, val_m32);

	float** val_m33 = initFloatTable(3);
	val_m33[0][0] = 0; val_m33[0][1] = 1; val_m33[0][2] = 2;
	val_m33[1][0] = 4; val_m33[1][1] = 5; val_m33[1][2] = 6;
	val_m33[2][0] = 8; val_m33[2][1] = 9; val_m33[2][2] = 10;
	mat_33.setM(3, val_m33);

	someMatrix[0][0] = mat_00;
	someMatrix[0][1] = mat_01;
	someMatrix[0][2] = mat_02;
	someMatrix[0][3] = mat_03;

	someMatrix[1][0] = mat_10;
	someMatrix[1][1] = mat_11;
	someMatrix[1][2] = mat_12;
	someMatrix[1][3] = mat_13;

	someMatrix[2][0] = mat_20;
	someMatrix[2][1] = mat_21;
	someMatrix[2][2] = mat_22;
	someMatrix[2][3] = mat_23;

	someMatrix[3][0] = mat_30;
	someMatrix[3][1] = mat_31;
	someMatrix[3][2] = mat_32;
	someMatrix[3][3] = mat_33;


}

void matTest::afisare()
{
	Adina::mat a(4);


	//a.setIdentity();

	//a.setM('t', 1.0f, 2.0f, 3.0f, 4.0f, 4.0f, 3.0f, 2.0f, 1.0f, 0.0f, 1.0f, 3.0f, 0.0f, 1.0f, 6.0f, 2.0f, 1.0f);
	//a.setM('t', 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	//b.setM('t', 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	///result = 0
	//a.setM('t', 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
	//b.setM('t', 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);

	//std::cout << a << std::endl;
	std::cout << a.det(a) << std::endl;
}

void matTest::add()
{
}

void matTest::determinant()
{
}

void matTest::inv()
{
}
//#define JUST_SOME_AFIS
void matTest::minorCuIsiJ()
{
	initSomeMat();
#ifdef JUST_SOME_AFIS
	for (int i = 0; i < 16; i++) {
		std::cout << "Matrice: " << i << std::endl;
		std::cout << someMatrix[i] << std::endl;
	}
#endif // JUST_SOME_AFIS

#define TEST_CU_MINORI_I_SI_J
#ifdef TEST_CU_MINORI_I_SI_J
	const int  dimMat = 4;
	Adina::mat a(dimMat);
	float **someVal;
	someVal = new float*[dimMat];
	for (int i = 0; i < dimMat; i++) {
		someVal[i] = new float[dimMat];
	}
	float val = 0.0f;
	for (int i = 0; i < dimMat; i++) {
		for (int j = 0; j < dimMat; j++) {
			someVal[i][j] = val++;
		}
	}
	a.setM(someVal);
	std::cout << a << std::endl;
	for (int i = 0; i < dimMat; i++) {
		for (int j = 0; j < dimMat; j++) {
			if (someMatrix[i][j] == a.getMat(i, j)) {
				std::cout << someMatrix[i][j] << std::endl;
				std::cout << "Test: ["<<i <<"]["<<j<<"] trecut: " << std::endl;
			}
			else {
				std::cout << someMatrix[i][j] << std::endl;
				std::cout << "Test: [" << i << "][" << j << "] esuat" << std::endl;
			}
		}
	}
#endif //TEST_CU_MINORI_I_SI_J
}
