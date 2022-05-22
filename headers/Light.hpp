//
// Created by Hazzea Charlsie on 5/22/22.
//

#ifndef RT_LIGHT_HPP
#define RT_LIGHT_HPP

#include "Ambient.hpp"
#include "Vector3f.hpp"

class Light: public Ambient
{
private:
	Vector3f	_coordinates{};
public:
	Light(): Ambient() {};
	explicit Light(const s_light& lightParams);
	~Light() = default;

//	get coordinates
public:
	[[nodiscard]] const Vector3f& getCoordinates() const;

//	print params
public:
	void PrintParams() const override;
};

#endif //RT_LIGHT_HPP
