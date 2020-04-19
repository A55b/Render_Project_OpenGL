#ifndef TMGVERTEX_H
#define TMGVERTEX_H

#include <glm/glm.hpp>
using namespace glm;

struct TmgVertex
{
	vec3 position;
	vec3 normal;

	TmgVertex(const vec3& pos, const vec3& norm)
	{
		position = pos;
		normal = norm;
	}
};

#endif 
