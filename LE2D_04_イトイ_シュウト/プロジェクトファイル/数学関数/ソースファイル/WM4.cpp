#include "WM4.h"

WorldM4::~WorldM4()
{}

// アフィン変換行列
Matrix4x4 WorldM4::MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	Matrix4x4 result = {};

	scaleMatrix_ = make_.MakeScaleMatrix(scale);
	mRotate_.SetRotate(rotate);
	mRotate_.Update();
	rotateMatrix_ = mRotate_.GetRotateXYZMatrix();
	translateMatrix_ = make_.MakeTransLateMatrix(translate);

	result = m4_.Multiply(scaleMatrix_, m4_.Multiply(rotateMatrix_, translateMatrix_));

	return result;
}
