#include "WVP.h"

WVP::~WVP()
{}

Matrix4x4 WVP::MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip)
{
	Matrix4x4 result = {};

	float cot = 1.0f / (std::tanf(fovY / 2.0f));

	result.m[0][0] = 1.0f / aspectRatio * cot;
	result.m[1][1] = cot;
	result.m[2][2] = farClip / (farClip - nearClip);
	result.m[2][3] = 1.0f;
	result.m[3][2] = -(nearClip * farClip) / (farClip - nearClip);

	return result;
}

Matrix4x4 WVP::MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip)
{
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

Matrix4x4 WVP::MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth)
{
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

Matrix4x4 WVP::WorldViewPortMatrix()
{

	const Vector3 CameraPos = { 0.0f, 0.0f, -10.0f };
	Vector3 rotate{};
	Vector3 translate{};
	Vector3 screenVertices[3];
	const Vector3 kLocalVertices[3] = {
		{0.0f,  1.0f,  0.0f},
		{1.0f,  -1.0f, 0.0f},
		{-1.0f, -1.0f, 0.0f},
	};

	// 各種行列の計算
	Matrix4x4 cameraMatrix = wm4_.MakeAffineMatrix({ 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, CameraPos);
	Matrix4x4 worldMatrix = wm4_.MakeAffineMatrix({ 1.0f, 1.0f, 1.0f }, rotate, translate);
	Matrix4x4 viewMatrix = m4_.Inverse(cameraMatrix);
	Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.0f);

	//  WorldViewProjectionMatrix、略してWVPMatrixを作る
	Matrix4x4 wvpMatrix = m4_.Multiply(worldMatrix, m4_.Multiply(viewMatrix, projectionMatrix));
	Matrix4x4 vpMatrix = MakeViewportMatrix(0, 0, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);

	for (uint32_t i = 0; i < 3; ++i) {
		Vector3 ndcVertex = makeMatrix_.Transform(kLocalVertices[i], wvpMatrix);
		screenVertices[i] = makeMatrix_.Transform(ndcVertex, vpMatrix);
	}

	return wvpMatrix;
}
