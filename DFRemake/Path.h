#pragma once

//Includes
#include "Object.h"

class Path : public df::Object {
private:

public:
	//Constructor
	Path();

	//Constructor with preset positon
	Path(df::Vector position);

	int draw() override;
};