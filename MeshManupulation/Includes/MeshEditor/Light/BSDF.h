#pragma once
#include "Maths/Vector3.h"

class BSDF
{
public:
	virtual Spectrum f(const Vector3D& wo, const Vector3D& wi) = 0;

	virtual Spectrum sample_f(const Vector3D& wo, Vector3D* wi, float* pdf) = 0;

	virtual Spectrum get_emission() const = 0;

	virtual bool is_delta() const = 0;

	virtual void reflect(const Vector3& wo, Vector3* wi);

	virtual bool refract(const Vector3& wo, Vector3* wi, float ior);

	Spectrum rasterize_color;
};
