#include "MM.h"

// 1.平行移動行列
Matrix4x4 MakeMatrix::MakeTransLateMatrix(const Vector3& transLate) {
	Matrix4x4 result = {};

	result.m[0][0] = 1.0f;
	result.m[1][1] = 1.0f;
	result.m[2][2] = 1.0f;
	result.m[3][0] = transLate.x;
	result.m[3][1] = transLate.y;
	result.m[3][2] = transLate.z;
	result.m[3][3] = 1.0f;

	return result;
}

// 2.拡大縮小行列
Matrix4x4 MakeMatrix::MakeScaleMatrix(const Vector3& scale) {
	Matrix4x4 result = {};

	result.m[0][0] = scale.x;
	result.m[1][1] = scale.y;
	result.m[2][2] = scale.z;
	result.m[3][3] = 1.0f;

	return result;
}

// 3.座標変換
Vector3 MakeMatrix::Transform(const Vector3& vector, const Matrix4x4& matrix) {
	Vector3 result = {};

	result.x = (vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + 1.0f * matrix.m[3][0]);
	result.y = (vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + 1.0f * matrix.m[3][1]);
	result.z = (vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + 1.0f * matrix.m[3][2]);
	float w = (vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + 1.0f * matrix.m[3][3]);
	//assert(w!=0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;

	return result;
}
