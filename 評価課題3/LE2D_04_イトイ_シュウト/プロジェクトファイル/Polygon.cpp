#include "Polygon.h"

Vector3 Polygon::Closs(const Vector3& v1, const Vector3& v2)
{
	Vector3 result = {};

	result.x = (v1.y * v2.z - v1.z * v2.y);
	result.y = (v1.z * v2.x - v1.x * v2.z);
	result.z = (v1.x * v2.y - v1.y * v2.x);

	return result;
}
