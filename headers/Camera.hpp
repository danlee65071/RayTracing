//
// Created by Hazzea Charlsie on 5/22/22.
//

#ifndef RT_CAMERA_HPP
#define RT_CAMERA_HPP

#include <iostream>
#include "Vector3f.hpp"
#include "utils.hpp"

class Camera
{
private:
	std::string		_key;
	Vector3f		_coordinates{};
	Vector3f		_direction{};
	float			_fov{};
public:
	Camera() = default;
	explicit Camera(const s_camera& cameraParams);
	~Camera() = default;

public:
	void setCoordinates(float x, float y, float z);
	void setCoordinateX(float x);
	void setCoordinateY(float y);
	void setCoordinateZ(float z);

public:
	[[nodiscard]] const Vector3f& getCoordinates() const;
	[[nodiscard]] const Vector3f& getDirection() const;

//	Print params
public:
	void PrintParams() const;
};

#endif //RT_CAMERA_HPP
