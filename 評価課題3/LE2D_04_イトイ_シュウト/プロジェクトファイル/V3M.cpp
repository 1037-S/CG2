#include "V3M.h"
#include <cmath>

Vector3Mas::~Vector3Mas() {}

// 加算
Vector3 Vector3Mas::Add(const Vector3& v1, const Vector3& v2) {
	Vector3 result = {};

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;

	return result;
}

// 減算
Vector3 Vector3Mas::Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 result = {};

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;

	return result;
}

// スカラー倍
Vector3 Vector3Mas::Multiply(float scalar, const Vector3& v) {
	Vector3 result = {};

	result.x = scalar * v.x;
	result.y = scalar * v.y;
	result.z = scalar * v.z;

	return result;
}
// 内積
float Vector3Mas::Dot(const Vector3& v1, const Vector3& v2) {
	float result = {};

	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;

	return result;
}
// 長さ(ノルム)
float Vector3Mas::Length(const Vector3& v) {
	float result = {};

	result = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);

	return result;
}
// 正規化
Vector3 Vector3Mas::Normalize(const Vector3& v) {
	Vector3 result = {};

	float len = Length(v);

	if (len == 0.0f) {
		return { 0.0f, 0.0f, 0.0f };
	}

	result.x = v.x / len;
	result.y = v.y / len;
	result.z = v.z / len;

	return result;
}