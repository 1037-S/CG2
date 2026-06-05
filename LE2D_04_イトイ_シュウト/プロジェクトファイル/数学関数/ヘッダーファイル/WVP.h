#pragma once
#include "OBJECT.h"
#include "M4.h"
#include "WM4.h"
#include "MM.h"
#include <cmath>

class WVP
{
public:
	~WVP();

	// 1.透視投影行列
	Matrix4x4 MakePerspectiveFovMatrix(
		float fovY, float aspectRatio,
		float nearClip, float farClip);
	// 2.正射影行列
	Matrix4x4 MakeOrthographicMatrix(
		float left, float top,
		float right, float bottom,
		float nearClip, float farClip);
	// 3.ビューポート行列
	Matrix4x4 MakeViewportMatrix(
		float left, float top,
		float width, float height,
		float minDepth, float maxDepth);

	Matrix4x4 WorldViewPortMatrix();

private:


	WorldM4 wm4_;
	Matrix4 m4_;
	MakeMatrix makeMatrix_;
};


