#pragma once

namespace math
{
	constexpr float PI = 3.141592f;
	constexpr float TWO_PI = 2.f * PI;

	struct vec3
	{
		float x = 0.f;
		float y = 0.f;
		float z = 0.f;
	public:
		vec3() = default;
		vec3(float x, float y, float z) :x(x), y(y), z(z) {}

		constexpr vec3 operator+(const vec3& other)const noexcept;
		constexpr vec3& operator+=(const vec3& other)noexcept;

		constexpr vec3 operator-(const vec3& other)const noexcept;
		constexpr vec3& operator-=(const vec3& other)noexcept;

		constexpr vec3 operator+(float value)const noexcept;
		constexpr vec3& operator+=(float value)noexcept;

		constexpr vec3 operator-(float value)const noexcept;
		constexpr vec3& operator-= (float value)noexcept;

		constexpr vec3 operator*(float scale)const noexcept;
		constexpr vec3& operator*=(float scale)noexcept;
		
		constexpr vec3 operator/(float div)const noexcept;
		constexpr vec3& operator/=(float div)noexcept;

		void Normalize();
		void Length();
	};

	float Dot(vec3& a, vec3& b);
	vec3 Cross(vec3& a, vec3& b);

	struct TransformMatrix
	{
		float matrix[4][4];

	public:
		constexpr float* operator[](int idx)const noexcept;
		constexpr TransformMatrix operator*(TransformMatrix& other)const noexcept;
		constexpr TransformMatrix& operator*=(TransformMatrix& other)noexcept;
		vec3 operator*(vec3& v)const noexcept;

		void Identity();
		void Scale(float x, float y, float z);
		void RotateX(float radian);
		void RotateY(float radian);
		void RotateZ(float radian);
		void Traslate(float x, float y, float z);
	};

	inline float NormalizeAngle(float angle)
	{
		if (angle < -PI)
		{
			angle += TWO_PI;
		}
		else if (angle > PI)
		{
			angle -= TWO_PI;
		}

		return angle;
	}

	inline float Lerp(float a, float b, float t)
	{
		return a + (b - a) * t;
	}
}

#include "Math.inl"