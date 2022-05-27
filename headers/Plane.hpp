//
// Created by Hazzea Charlsie on 5/22/22.
//

#ifndef RT_PLANE_HPP
#define RT_PLANE_HPP

#include "AFigure.hpp"

class Plane: public AFigure
{
public:
	Plane() = default;
	explicit Plane(const s_plane& planeParams);
	~Plane() override = default;

private:
	void setN(const Vector3f& P) override {};

public:
	[[nodiscard]] std::pair<float, float> intersectRay(const Vector3f& O, const Vector3f& D) override;

//	print params
public:
	void PrintParams() const override;
};

#endif //RT_PLANE_HPP
