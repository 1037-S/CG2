#include "WM4.h"

WorldM4::~WorldM4()
{}

// アフィン変換行列
Matrix4x4 WorldM4::MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	Matrix4x4 result = {};

	scaleMatrix4_ = make_.MakeScaleMatrix(scale);
	mRotate_.SetRotate(rotate);
	mRotate_.Update();
	rotateMatrix4_ = mRotate_.GetRotateXYZMatrix();
	translateMatrix4_ = make_.MakeTransLateMatrix(translate);

	result = m4_.Multiply(scaleMatrix4_, m4_.Multiply(rotateMatrix4_, translateMatrix4_));

	return result;
}

Matrix3x3 WorldM4::MakeAffineMatrix(const Vector2& scale, const Vector2& rotate, const Vector2& translate)
{
	Matrix3x3 result = {};

	scaleMatrix3_ = make_.MakeScaleMatrix(scale);
	mRotate_.SetRotate(rotate);
	rotateMatrix3_ = mRotate_.GetRotateMatrix();
	translateMatrix3_ = make_.MakeTransLateMatrix(translate);

	result = m4_.Multiply(scaleMatrix3_,m4_.Multiply(rotateMatrix3_,translateMatrix3_));

	return result;
}
