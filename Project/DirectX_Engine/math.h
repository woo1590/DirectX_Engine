#pragma once
#include <cmath>

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
		constexpr vec3() = default;
		constexpr vec3(float x, float y, float z) :x(x), y(y), z(z) {}

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

		vec3 Normalize()const;
		float Length()const;
	};

	constexpr vec3 operator*(float scale, vec3& v)noexcept;

	float Dot(const vec3& a, const vec3& b);
	vec3 Cross(const vec3& a, const vec3& b);

	struct TransformMatrix
	{
		float matrix[4][4];
	public:
		constexpr const float* operator[](int idx)const noexcept;
		constexpr TransformMatrix operator*(const TransformMatrix& other)const noexcept;
		constexpr TransformMatrix& operator*=(TransformMatrix& other)noexcept;

		void Identity();

		void Scaling(vec3& scale);
		void Scaling(float x, float y, float z);

		void RotationX(float radian);
		void RotationY(float radian);
		void RotationZ(float radian);

		void Translation(vec3& trans);
		void Translation(float x, float y, float z);

		vec3 TransformPos(const vec3& pos);	//위치
		vec3 TransformDir(const vec3& dir);	//방향 벡터
	};

	struct vec4
	{
		float x = 0.f;
		float y = 0.f;
		float z = 0.f;
		float w = 0.f;

		vec4() = default;
		vec4(float x, float y, float z, float w) :x(x), y(y), z(z), w(w) {}
		vec4(const vec3& v, float w) :x(v.x), y(v.y), z(v.z), w(w) {}
		vec3 ToVec3()const { return vec3(x, y, z); }

		vec4 operator*(const TransformMatrix& mat)const noexcept;
	};


	float NormalizeAngle(float angle);
	float Lerp(float a, float b, float t);
	float ToRadian(float degree);
	float ToDegree(float radian);
}

#include "Math.inl"