#pragma once

namespace Adina {
	struct mat4
	{
		float m00, m01, m02, m03;
		float m10, m11, m12, m13;
		float m20, m21, m22, m23;
		float m30, m31, m32, m33;
		mat4();
		void addTo(const mat4 b);
		void setIdentity();
		float determinant();
	private:
		float det1();
		float det2();
		float det3();
		float det4();
	};
}