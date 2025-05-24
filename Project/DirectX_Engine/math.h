#pragma once

namespace math
{
	constexpr float PI = 3.141592f;
	constexpr float TWO_PI = 2.f * PI;

	typedef struct vec3
	{
		float x = 0.f;
		float y = 0.f;
		float z = 0.f;
	public:
		vec3() = default;
		vec3(float x, float y, float z) :x(x), y(y), z(z) {}

		constexpr vec3 operator+(const vec3& other);
		constexpr vec3& operator+=(const vec3& other)noexcept;

		constexpr vec3 operator-(const vec3& other);
		constexpr vec3& operator-=(const vec3& other)noexcept;

		constexpr vec3 operator+(float value);
		constexpr vec3& operator+=(float value)noexcept;

		constexpr vec3 operator-(float value);
		constexpr vec3& operator-= (float value)noexcept;

		constexpr vec3 operator*(float scale);
		constexpr vec3& operator*=(float scale)noexcept;
		
		constexpr vec3 operator/(float div);
		constexpr vec3& operator/=(float div)noexcept;

		constexpr bool operator==(const vec3& other);
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