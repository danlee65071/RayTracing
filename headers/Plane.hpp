//
// Created by Hazzea Charlsie on 5/22/22.
//

#ifndef RT_PLANE_HPP
#define RT_PLANE_HPP

#include "IFigure.hpp"
#include "Vector3f.hpp"

class Plane: public IFigure
{
private:
	Vector3f	_direction{};
public:
	Plane() = default;
	explicit Plane(const s_plane& planeParams);
	~Plane() override = default;

//	print params
public:
	void PrintParams() const override;
};

#endif //RT_PLANE_HPP
