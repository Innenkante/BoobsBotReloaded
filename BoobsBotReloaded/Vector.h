#pragma once
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
};

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