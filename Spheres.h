#pragma once
#include "V3M.h"
#include "M4.h"
#include "Polygon.h"
#include <cmath>

struct Sphere // 球
{
	Vector3 center; //!< 球の中心点
	float radius;	//!< 球の半径
};

class Ball
{
public:

	// 球体
	void DrawSphere(const Sphere& sphere);


private:

	Sphere sphere_;
	float phi_;
};

