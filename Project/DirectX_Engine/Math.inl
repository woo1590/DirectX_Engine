#pragma once

namespace math
{
	constexpr vec3 vec3::operator+(const vec3& other)const noexcept { return vec3(x + other.x, y + other.y, z + other.z); }
	constexpr vec3& vec3::operator+=(const vec3& other)noexcept
	{
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	constexpr vec3 vec3::operator-(const vec3& other)const noexcept { return vec3(x - other.x, y - other.y, z - other.z); }
	constexpr vec3& vec3::operator-=(const vec3& other)noexcept
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	constexpr vec3 vec3::operator+(float value)const noexcept { return vec3(x + value, y + value, z + value); }
	constexpr vec3& vec3::operator+=(float value)noexcept
	{
		x += value;
		y += value;
		z += value;

		return *this;
	}

	constexpr vec3 vec3::operator-(float value)const noexcept { return vec3(x - value, y - value, z - value); }
	constexpr vec3& vec3::operator-= (float value)noexcept
	{
		x -= value;
		y -= value;
		z -= value;

		return *this;
	}

	constexpr vec3 vec3::operator*(float scale)const noexcept { return vec3(x * scale, y * scale, z * scale); }
	constexpr vec3& vec3::operator*=(float scale)noexcept
	{
		x *= scale;
		y *= scale;
		z *= scale;

		return *this;
	}

	constexpr vec3 vec3::operator/(float div)const noexcept { return vec3(x / div, y / div, z / div); }
	constexpr vec3& vec3::operator/=(float div)noexcept
	{
		x /= div;
		y /= div;
		z /= div;

		return *this;
	}

	inline vec3 vec3::Normalize()const
	{
		float length = this->Length();

		return vec3(x / length, y / length, z / length);
	}

	inline float vec3::Length()const
	{
		return sqrt(x * x + y * y + z * z);
	}

	inline float Dot(const vec3& a, const vec3& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	inline vec3 Cross(const vec3& a, const vec3& b)
	{
		return vec3(a.y * b.z - a.z * b.y, a.x * b.z - a.z * b.x, a.x * b.y - a.y * b.x);
	}

	constexpr vec3 operator*(float scale, vec3& v)noexcept
	{
		return v * scale;
	}

	constexpr const float* TransformMatrix::operator[](int idx)const noexcept { return matrix[idx]; }
	constexpr TransformMatrix TransformMatrix::operator*(const TransformMatrix& other)const noexcept
	{
		TransformMatrix res;

		res.matrix[0][0] = matrix[0][0] * other[0][0] + matrix[0][1] * other[1][0] + matrix[0][2] * other[2][0] + matrix[0][3] * other[3][0];
		res.matrix[0][1] = matrix[0][0] * other[0][1] + matrix[0][1] * other[1][1] + matrix[0][2] * other[2][1] + matrix[0][3] * other[3][1];
		res.matrix[0][2] = matrix[0][0] * other[0][2] + matrix[0][1] * other[1][2] + matrix[0][2] * other[2][2] + matrix[0][3] * other[3][2];
		res.matrix[0][3] = matrix[0][0] * other[0][3] + matrix[0][1] * other[1][3] + matrix[0][2] * other[2][3] + matrix[0][3] * other[3][3];
		   
		res.matrix[1][0] = matrix[1][0] * other[0][0] + matrix[1][1] * other[1][0] + matrix[1][2] * other[2][0] + matrix[1][3] * other[3][0];
		res.matrix[1][1] = matrix[1][0] * other[0][1] + matrix[1][1] * other[1][1] + matrix[1][2] * other[2][1] + matrix[1][3] * other[3][1];
		res.matrix[1][2] = matrix[1][0] * other[0][2] + matrix[1][1] * other[1][2] + matrix[1][2] * other[2][2] + matrix[1][3] * other[3][2];
		res.matrix[1][3] = matrix[1][0] * other[0][3] + matrix[1][1] * other[1][3] + matrix[1][2] * other[2][3] + matrix[1][3] * other[3][3];
		   
		res.matrix[2][0] = matrix[2][0] * other[0][0] + matrix[2][1] * other[1][0] + matrix[2][2] * other[2][0] + matrix[2][3] * other[3][0];
		res.matrix[2][1] = matrix[2][0] * other[0][1] + matrix[2][1] * other[1][1] + matrix[2][2] * other[2][1] + matrix[2][3] * other[3][1];
		res.matrix[2][2] = matrix[2][0] * other[0][2] + matrix[2][1] * other[1][2] + matrix[2][2] * other[2][2] + matrix[2][3] * other[3][2];
		res.matrix[2][3] = matrix[2][0] * other[0][3] + matrix[2][1] * other[1][3] + matrix[2][2] * other[2][3] + matrix[2][3] * other[3][3];
		   
		res.matrix[3][0] = matrix[3][0] * other[0][0] + matrix[3][1] * other[1][0] + matrix[3][2] * other[2][0] + matrix[3][3] * other[3][0];
		res.matrix[3][1] = matrix[3][0] * other[0][1] + matrix[3][1] * other[1][1] + matrix[3][2] * other[2][1] + matrix[3][3] * other[3][1];
		res.matrix[3][2] = matrix[3][0] * other[0][2] + matrix[3][1] * other[1][2] + matrix[3][2] * other[2][2] + matrix[3][3] * other[3][2];
		res.matrix[3][3] = matrix[3][0] * other[0][3] + matrix[3][1] * other[1][3] + matrix[3][2] * other[2][3] + matrix[3][3] * other[3][3];

		return res;
	}
	constexpr TransformMatrix& TransformMatrix::operator*=(TransformMatrix& other)noexcept
	{
		(*this) = (*this) * other;

		return (*this);
	}

	inline void TransformMatrix::Identity()
	{
		matrix[0][0] = 1.f;	matrix[0][1] = 0.f;	matrix[0][2] = 0.f;	matrix[0][3] = 0.f;
		matrix[1][0] = 0.f;	matrix[1][1] = 1.f;	matrix[1][2] = 0.f;	matrix[1][3] = 0.f;
		matrix[2][0] = 0.f;	matrix[2][1] = 0.f;	matrix[2][2] = 1.f;	matrix[2][3] = 0.f;
		matrix[3][0] = 0.f;	matrix[3][1] = 0.f;	matrix[3][2] = 0.f;	matrix[3][3] = 1.f;
	}

	inline void TransformMatrix::Scaling(float x, float y, float z)
	{
		matrix[0][0] = x;	matrix[0][1] = 0.f;	matrix[0][2] = 0.f;	matrix[0][3] = 0.f;
		matrix[1][0] = 0.f;	matrix[1][1] = y;	matrix[1][2] = 0.f;	matrix[1][3] = 0.f;
		matrix[2][0] = 0.f;	matrix[2][1] = 0.f;	matrix[2][2] = z;	matrix[2][3] = 0.f;
		matrix[3][0] = 0.f;	matrix[3][1] = 0.f;	matrix[3][2] = 0.f;	matrix[3][3] = 1.f;
	}

	inline void TransformMatrix::Scaling(vec3& scale)
	{
		Scaling(scale.x, scale.y, scale.z);
	}

	inline void TransformMatrix::RotationX(float radian)
	{
		matrix[0][0] = 1.f;			matrix[0][1] = 0.f;			matrix[0][2] = 0.f;			matrix[0][3] = 0.f;
		matrix[1][0] = 0.f;			matrix[1][1] = cos(radian);	matrix[1][2] = sin(radian);	matrix[1][3] = 0.f;
		matrix[2][0] = 0.f;			matrix[2][1] = -sin(radian);matrix[2][2] = cos(radian);	matrix[2][3] = 0.f;
		matrix[3][0] = 0.f;			matrix[3][1] = 0.f;			matrix[3][2] = 0.f;			matrix[3][3] = 1.f;
	}

	inline void TransformMatrix::RotationY(float radian)
	{
		matrix[0][0] = cos(radian);	matrix[0][1] = 0.f;			matrix[0][2] = -sin(radian);matrix[0][3] = 0.f;
		matrix[1][0] = 0.f;			matrix[1][1] = 1.f;			matrix[1][2] = 0.f;			matrix[1][3] = 0.f;
		matrix[2][0] = sin(radian);	matrix[2][1] = 0.f;			matrix[2][2] = cos(radian);	matrix[2][3] = 0.f;
		matrix[3][0] = 0.f;			matrix[3][1] = 0.f;			matrix[3][2] = 0.f;			matrix[3][3] = 1.f;
	}

	inline void TransformMatrix::RotationZ(float radian)
	{
		matrix[0][0] = cos(radian);	matrix[0][1] = sin(radian);	matrix[0][2] = 0.f;			matrix[0][3] = 0.f;
		matrix[1][0] = -sin(radian);matrix[1][1] = cos(radian);	matrix[1][2] = 0.f;			matrix[1][3] = 0.f;
		matrix[2][0] = 0.f;			matrix[2][1] = 0.f;			matrix[2][2] = 1.f;			matrix[2][3] = 0.f;
		matrix[3][0] = 0.f;			matrix[3][1] = 0.f;			matrix[3][2] = 0.f;			matrix[3][3] = 1.f;
	}

	inline void TransformMatrix::Translation(float x, float y, float z)
	{
		matrix[0][0] = 1.f;	matrix[0][1] = 0.f;	matrix[0][2] = 0.f;	matrix[0][3] = 0.f;
		matrix[1][0] = 0.f;	matrix[1][1] = 1.f;	matrix[1][2] = 0.f;	matrix[1][3] = 0.f;
		matrix[2][0] = 0.f;	matrix[2][1] = 0.f;	matrix[2][2] = 1.f;	matrix[2][3] = 0.f;
		matrix[3][0] = x;	matrix[3][1] = y;	matrix[3][2] = z;	matrix[3][3] = 1.f;
	}

	void TransformMatrix::Translation(vec3& trans)
	{
		Translation(trans.x, trans.y, trans.z);
	}

	inline vec3 TransformMatrix::TransformPos(const vec3& pos)
	{
		vec4 tmp(pos, 1.f);
		
		tmp = tmp * (*this);

		return tmp.ToVec3();
	}
	inline vec3 TransformMatrix::TransformDir(const vec3& dir)
	{
		vec4 tmp(dir, 0.f);

		tmp = tmp * (*this);

		return tmp.ToVec3();
	}

	inline vec4 vec4::operator*(const TransformMatrix& mat)const noexcept
	{
		return vec4(
			x * mat[0][0] + y * mat[1][0] + z * mat[2][0] + w * mat[3][0],
			x * mat[0][1] + y * mat[1][1] + z * mat[2][1] + w * mat[3][1],
			x * mat[0][2] + y * mat[1][2] + z * mat[2][2] + w * mat[3][2],
			x * mat[0][3] + y * mat[1][3] + z * mat[2][3] + w * mat[3][3]
		);
	}

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

	inline float ToRadian(float degree)
	{
		return degree * PI / 180.f;
	}
	inline float ToDegree(float radian)
	{
		return radian * 180.f / PI;
	}
}