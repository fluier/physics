#include "mat4.h"

#include "mat3.h"

namespace Adina {
	mat4::mat4():
		m00(0), m01(0), m02(0), m03(0),
		m10(0), m11(0), m12(0), m13(0),
		m20(0), m21(0), m22(0), m23(0),
		m30(0), m31(0), m32(0), m33(0)
	{
	}
	void mat4::addTo(const mat4 b)
	{
		m00 += b.m00; m01 += b.m01; m02 += b.m02; m03 += b.m03;
		m10 += b.m10; m11 += b.m11; m12 += b.m12; m13 += b.m13;
		m20 += b.m20; m21 += b.m21; m22 += b.m22; m23 += b.m23;
		m30 += b.m30; m31 += b.m31; m32 += b.m32; m33 += b.m33;
	}
	void mat4::setIdentity()
	{
		m00 = 1; m01 = 0; m02 = 0; m03 = 0;
		m10 = 0; m11 = 1; m12 = 0; m13 = 0;
		m20 = 0; m21 = 0; m22 = 1; m23 = 0;
		m30 = 0; m31 = 0; m32 = 0; m33 = 1;
	}
	float mat4::determinant()
	{
		return 0.0f;
	}
	float mat4::det1()
	{
		mat3 m(m11, m12, m12, m21, m22, m23, m31, m32, m33);
		return 0.0f;
	}
	float mat4::det2()
	{
		return 0.0f;
	}
	float mat4::det3()
	{
		return 0.0f;
	}
	float mat4::det4()
	{
		return 0.0f;
	}
}
