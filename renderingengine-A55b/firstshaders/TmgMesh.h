#pragma once
#ifndef TMGMESH_H
#define TMGMESH_H

#include <string>
#include <fstream>
#include <vector>

#include "TmgVertex.h"
using namespace std;

class TmgMesh
{
public:
	vec3 convertStrToVec(string str);
	bool loadFromObj(string path);
	vector<TmgVertex>& getVertices();

private:
	vector<TmgVertex> vertices;
};


inline vector<TmgVertex>& TmgMesh::getVertices()
{
	return vertices;
}

#endif 