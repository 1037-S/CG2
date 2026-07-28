#pragma once
#include "OBJECT.h"

class RPV2
{
public:

	~RPV2();

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

};

