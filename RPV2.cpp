#include "RPV2.h"
#include <cmath>

RPV2::~RPV2()
{}
// 1.透視投影行列
Matrix4x4 RPV2::MakePerspectiveFovMatrix(
	float fovY, float aspectRatio,
	float nearClip, float farClip) {
	Matrix4x4 result = {};

	float cot = 1.0f / (std::tanf(fovY / 2.0f));

	result.m[0][0] = 1.0f / aspectRatio * cot;
	result.m[1][1] = cot;
	result.m[2][2] = farClip / (farClip - nearClip);
	result.m[2][3] = 1.0f;
	result.m[3][2] = -(nearClip * farClip) / (farClip - nearClip);

	return result;
}

// 2.正射影行列
Matrix4x4 RPV2::MakeOrthographicMatrix(
	float left, float top,
	float right, float bottom,
	float nearClip, float farClip) {
	Matrix4x4 result = {};

	result.m[0][0] = 2.0f / (right - left);
	result.m[1][1] = 2.0f / (top - bottom);
	result.m[2][2] = 1.0f / (farClip - nearClip);
	result.m[3][0] = (left + right) / (left - right);
	result.m[3][1] = (top + bottom) / (bottom - top);
	result.m[3][2] = nearClip / (nearClip - farClip);
	result.m[3][3] = 1;

	return result;
}
// 3.ビューポート行列
Matrix4x4 RPV2::MakeViewportMatrix(
	float left, float top,
	float width, float height,
	float minDepth, float maxDepth) {
	Matrix4x4 result = {};

	result.m[0][0] = width / 2.0f;
	result.m[1][1] = -(height / 2.0f);
	result.m[2][2] = maxDepth - minDepth;
	result.m[3][0] = left + (width / 2.0f);
	result.m[3][1] = top + (height / 2.0f);
	result.m[3][2] = minDepth;
	result.m[3][3] = 1;
	return result;
}

