#pragma once
#define PI 3.14159265358979323846264338327950288419716939937
class Vector2D
{
	float X, Y, Z;

public:
	Vector2D(float x, float y)
	{
		X = x;
		Y = y;
	}

	Vector2D(float* array)
	{
		X = array[0];
		Y = array[1];
	}
};


class Vector3D
{
	float X, Y, Z;
public:
	Vector3D(float x, float y, float z)
	{
		X = x;
		Y = y;
		Z = z;
	}

	Vector3D(float* array)
	{
		X = array[0];
		Y = array[1];
		Z = array[2];
	}

	Vector3D operator -(Vector3D other_vector)
	{
		return Vector3D(X - other_vector.X, Y - other_vector.Y, Z - other_vector.Z);
	}

	Vector3D operator +(Vector3D other_vector)
	{
		return Vector3D(X + other_vector.X, Y + other_vector.Y, Z + other_vector.Z);
	}

	Vector3D operator /(float number)
	{
		return Vector3D(X / number, Y / number, Z / number);
	}

	Vector3D operator*(float number)
	{
		return Vector3D(X * number, Y * number, Z * number);
	}

	Vector3D operator /(Vector3D other_vector)
	{
		return Vector3D(X * other_vector.X, Y * other_vector.Y, Z * other_vector.Z);
	}

	Vector3D operator *(Vector3D other_vector)
	{
		return Vector3D(X / other_vector.X, Y / other_vector.Y, Z / other_vector.Z);
	}

	float Length()
	{
		return sqrt(X * X + Y * Y + Z * Z);
	}

	float DistanceTo(Vector3D other_vector)
	{
		return (*this - other_vector).Length();
	}

	Vector3D Normalize()
	{
		return *this / this->Length();
	}


	Vector2D CalculateViewAnglesTo(Vector3D vector_to_calculate_to, Vector3D view_axis[3]);
};


