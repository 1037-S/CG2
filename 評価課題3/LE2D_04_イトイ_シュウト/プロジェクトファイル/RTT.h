#pragma once
#include "OBJECT.h"
#include "M4.h"
#include <cmath>

class Rotate {
public:

	~Rotate();

	// 1.X軸回転行列
	Matrix4x4 MakeRotateXMatrix(float radian);

	// 2.Y軸回転行列
	Matrix4x4 MakeRotateYMatrix(float radian);

	// 3.Z軸回転行列
	Matrix4x4 MakeRotateZMatrix(float radian);

	// 4.2次元回転行列
	Matrix3x3 MakeRotateMatrix(float radian);
	void Update();

	void SetRotate(const Vector3& rotate3) { rotate3_ = rotate3; }
	const Matrix4x4& GetRotateXYZMatrix() const { return rotateXYZMatrix_; }
	void SetRotate(const Vector2& rotate2) { rotate2_ = rotate2; }
	const Matrix3x3& GetRotateMatrix() const { return rotateMatrix_; }

private:
	Matrix4 m4_;

	Vector3 rotate3_;
	Vector2 rotate2_;

	Matrix3x3 rotateMatrix_;
	Matrix4x4 rotateMatrixX_;
	Matrix4x4 rotateMatrixY_;
	Matrix4x4 rotateMatrixZ_;
	Matrix4x4 rotateXYZMatrix_;
};