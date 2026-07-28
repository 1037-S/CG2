#pragma once
#include "OBJECT.h"
#include "M4.h"
#include "MM.h"
#include "WM4.h"
#include "RTT.h"
#include "RPV2.h"


class DebugCamera
{
public:

	void Initialize();

	void Update(const uint8_t* keys);
	const Matrix4x4& GetViewProjectionMatrix() const { return viewProjectionMatrix_; }
private:
	Matrix4 matrix4_;
	MakeMatrix MM_;
	WorldM4 wm4_;
	Rotate rtt_;
	RPV2 rpv2_;

	
	Matrix4x4 matRot_ ;
	Matrix4x4 matTranslation_ ;

	Vector3 translation_ = {0,0,-50};

	Matrix4x4 cameraMatrix_;
	Matrix4x4 worldMatrix_;
	Matrix4x4 viewMatrix_;
	Matrix4x4 projectionMatrix_;

	Matrix4x4 viewProjectionMatrix_;
	Matrix4x4 viewPortMatrix_;

	Vector3 cameraTranslate_{ 0.0f, 1.9f, -6.49f };
	Vector3 cameraRotate_{ 0.26f, 0.0f, 0.0f };
};

