#include "DebugCamera.h"
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

void DebugCamera::Initialize()
{
	matRot_ = matrix4_.MakeIdentity4x4();
	viewMatrix_ = matrix4_.MakeIdentity4x4();

	projectionMatrix_ = matrix4_.MakeIdentity4x4();
}

void DebugCamera::Update(const uint8_t* keys)
{
	Matrix4x4 matRotDelta = matrix4_.MakeIdentity4x4();
	
	if (keys[DIK_W])
	{
		const float speed = 1.0f;

		Vector3 move = {0,0,speed};
		//rotation_.x += move.x;
		//rotation_.y += move.y;
		//rotation_.z += move.z;

		translation_.x -= move.x;
		translation_.y -= move.y;
		translation_.z -= move.z;
	}
	if (keys[DIK_S])
	{
		const float speed = 1.0f;

		Vector3 move = {0,0,speed};
		//rotation_.x -= move.x;
		//rotation_.y -= move.y;
		//rotation_.z -= move.z;

		translation_.x += move.x;
		translation_.y += move.y;
		translation_.z += move.z;
	}
	if (keys[DIK_D])
	{
		const float speed = 0.5f;
		Vector3 move = { speed,0,0 };
		

		translation_.x += move.x;
		translation_.y += move.y;
		translation_.z += move.z;


	}
	if (keys[DIK_A])
	{
		const float speed = 0.5f;
		Vector3 move = { speed,0,0 };
		

		translation_.x -= move.x;
		translation_.y -= move.y;
		translation_.z -= move.z;


	}
	if (keys[DIK_UP])
	{
		
		const float speed = 0.01f;
		Vector3 move = { speed,0,0 };
		matRotDelta = rtt_.MakeRotateXMatrix(move.x);
		
	
	}
	if (keys[DIK_DOWN])
	{
		const float speed = 0.01f;
		Vector3 move = { speed,0,0 };
		matRotDelta =  rtt_.MakeRotateXMatrix(-move.x);
		

		
	}
	if (keys[DIK_LEFT])
	{
		const float speed = 0.01f;
		Vector3 move = { 0,speed,0 };
		
		matRotDelta = rtt_.MakeRotateYMatrix(-move.y);
		
	
	}
	if (keys[DIK_RIGHT])
	{
		const float speed = 0.01f;
		Vector3 move = { 0,speed,0 };
		
		matRotDelta =  rtt_.MakeRotateYMatrix(move.y);
		

		
	}
	if (keys[DIK_Z])
	{
		const float speed = 0.01f;
		Vector3 move = { 0,0,speed };
		
		matRotDelta = rtt_.MakeRotateZMatrix(move.z);

		
	}
	if (keys[DIK_C])
	{
		const float speed = 0.01f;
		Vector3 move = { 0,0,speed };
		
		matRotDelta =rtt_.MakeRotateZMatrix(-move.z);

		
	}

	// 各種行列の計算
	//rpv2_.WorldViewPortMatrix(cameraMatrix_, worldMatrix_, viewMatrix_, projectionMatrix_);
	//cameraMatrix_ = wm4_.MakeAffineMatrix({ 1.0f, 1.0f, 1.0f }, rotation_ ,translation_);
	
	matTranslation_ = MM_.MakeTransLateMatrix(translation_);
	matRot_ = matrix4_.Multiply(matRot_, matRotDelta);
	worldMatrix_ = matrix4_.Multiply( matTranslation_, matRot_);
	viewMatrix_ = matrix4_.Inverse(worldMatrix_);
	projectionMatrix_ = rpv2_.MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.0f);

	viewProjectionMatrix_ = matrix4_.Multiply(viewMatrix_, projectionMatrix_);
	//viewPortMatrix_ = rpv2_.MakeViewportMatrix(0, 0, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);
}
