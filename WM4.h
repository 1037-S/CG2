#pragma once
#include "OBJECT.h"
#include "M4.h"
#include "MM.h"
#include "RTT.h"

class WorldM4 {
public:

	~WorldM4();

	// アフィン変換行列
	Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

	void Initialize();

	void Update();

	void Draw();

private:
	Matrix4 m4_;
	MakeMatrix make_;
	Rotate mRotate_;

	Matrix4x4 scaleMatrix_;
	Matrix4x4 rotateMatrix_;
	Matrix4x4 translateMatrix_;

	Vector3 scale_;
	Vector3 rotate_;
	Vector3 translate_;

	Matrix4x4 worldMatrix_;
};