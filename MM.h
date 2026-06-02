#pragma once
#include "M4.h"
#include "V3M.h"

class MakeMatrix {
public:

	// 1.平行移動行列
	Matrix4x4 MakeTransLateMatrix(const Vector3& transLate);

	// 2.拡大縮小行列
	Matrix4x4 MakeScaleMatrix(const Vector3& scale);

	// 3.座標変換
	Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);


private:
	Vector3 translate_;
	Vector3 scale_;
	Vector3 point_;
	Matrix4x4 transformMatrix_;

	Matrix4x4 translateMatrix_;
	Matrix4x4 scaleMatrix_;
	Vector3 transformed_;

	Vector3Mas mas;
	Matrix4 m4;
};
