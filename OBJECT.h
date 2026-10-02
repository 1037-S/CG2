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
};

struct Vector3 {
	float x;
	float y;
	float z;
};

struct Vector4
{
	float x;
	float y;
	float z;
	float w;
};

struct Transform
{
	Vector3 scale;
	Vector3 rotate;
	Vector3 translate;
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
	//!< 乗算ブレンド。Src * 0 + Dest * Src
	kBlendModeMultiply,
	//!< スクリーンブレンド。Src * (1 - Dest) + Dest * 1
	kBlendModeScreen,
	// 利用してはいけない
	kCountOfBlendMode,
};


static const int kColumnWidth = 60;
static const int kRowHeight = 20;

const int kWindowWidth = 1280;
const int kWindowHeight = 720;
