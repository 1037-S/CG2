#pragma once
#include "OBJECT.h"

class Vector3Mas {
public:

	~Vector3Mas();

	// 加算
	Vector3 Add(const Vector3& v1, const Vector3& v2);
	// 減算
	Vector3 Subtract(const Vector3& v1, const Vector3& v2);
	// スカラー倍
	Vector3 Multiply(float scalar, const Vector3& v);
	// 内積
	float Dot(const Vector3& v1, const Vector3& v2);
	// 長さ(ノルム)
	float Length(const Vector3& v);
	// 正規化
	Vector3 Normalize(const Vector3& v);

private:
	
};