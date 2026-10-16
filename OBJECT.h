#pragma once

struct Matrix3x3
{
	float m[3][3];
};

struct Matrix4x4 {
	float m[4][4];
};

struct Vector2
{
	float x;
	float y;

	Vector2 operator+(Vector2 obj) {
		Vector2 result;

		result.x = x + obj.x;
		result.y = y + obj.y;
		return result;
	}
	Vector2 operator-(Vector2 obj) {
		Vector2 result;

		result.x = x - obj.x;
		result.y = y - obj.y;
		return result;
	}
};

struct Vector3 {
	float x;	// 横
	float y;	// 縦
	float z;	// 前後

	Vector3 operator+(Vector3 obj) {
		Vector3 result;

		result.x = x + obj.x;
		result.y = y + obj.y;
		result.z = z + obj.z;
		return result;
	}
	Vector3 operator-(Vector3 obj) {
		Vector3 result;

		result.x = x - obj.x;
		result.y = y - obj.y;
		result.z = z - obj.z;
		return result;
	}
};

struct Vector4
{
	float x;
	float y;
	float z;
	float w;

	Vector4 operator+(Vector4 obj) {
		Vector4 result;

		result.x = x + obj.x;
		result.y = y + obj.y;
		result.z = z + obj.z;
		result.w = w + obj.w;
		return result;
	}
	Vector4 operator-(Vector4 obj) {
		Vector4 result;

		result.x = x - obj.x;
		result.y = y - obj.y;
		result.z = z - obj.z;
		result.w = w - obj.w;
		return result;
	}
};

struct Transform
{
	Vector3 scale;
	Vector3 rotate;
	Vector3 translate;
};

struct Particle {
	Transform transform;
	Vector3 velocity;
};

enum BlendMode
{
	//!< ブレンドなし
	kBlendModeNone,
	//!< 通常αブレンド。デフォルト。SrcColor(以下Srcと呼称) * SrcAlpha(以下SrcAと呼称) + DestColor(以下Destと呼称) * (1 - srcA)
	kBlendModeNormal,
	//!< 加算ブレンド。Src * SrcA + Dest * 1
	kBlendModeAdd,
	//!< 減算ブレンド。Dest * 1 - Src * SrcA
	kBlendModeSubtract,
	//!< 乗算ブレンド。Src * 0 + Dest * SrcA
	kBlendModeMultiply,
	//!< スクリーンブレンド。Src * (1 - Dest) + Dest * 1
	kBlendModeScreen,
	// 利用してはいけない
	kCountOfBlendMode,
};

inline int currentBlendMode = kBlendModeNormal;

static const int kColumnWidth = 60;
static const int kRowHeight = 20;

const int kWindowWidth = 1280;
const int kWindowHeight = 720;
