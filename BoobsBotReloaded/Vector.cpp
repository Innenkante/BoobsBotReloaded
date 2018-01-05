#include "stdafx.h"
#include "Vector.h"

Vector2D Vector3D::CalculateViewAnglesTo(Vector3D vector_to_calculate_to, Vector3D view_axis[3])
{
	Vector3D aimAt = *this - vector_to_calculate_to;
	Vector3D normalized = aimAt.Normalize();

	aimAt = view_axis[1] * normalized;
	float yaw = asin(aimAt.X + aimAt.Y + aimAt.Z) * (180 / PI);
	aimAt = view_axis[2] * normalized;
	float pitch = -asin(aimAt.X + aimAt.Y + aimAt.Z) * (180 / PI);

	return Vector2D(yaw, pitch);
}
