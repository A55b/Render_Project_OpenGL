#include "TmgMesh.h"
#include <sstream>
#include <map>
#include <iostream>
#include <assert.h>
#include <string>
#include <fstream>

using namespace std;
using namespace glm;

vec3 TmgMesh::convertStrToVec(string str)
{
	stringstream strObj(str.substr(2));
	float x, y, z;
	strObj >> x; 
	strObj >> y;
	strObj >> z;
	vec3 newVec = vec3(x, y, z);

	return newVec;
}

bool TmgMesh::loadFromObj(string path)
{
	string line;
	vec3 pos;
	vec3 normal;
	vector<vec3>vertexPositions;
	vector<vec3>vertexNormals;
	ifstream myfile(path); 
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (!line.find("v "))
			{
				pos = convertStrToVec(line);
				vertexPositions.push_back(pos); 
			}
			else if (!line.find("vn"))
			{
				normal = convertStrToVec(line);
				vertexNormals.push_back(normal);
			}
			else if (!line.find("f")) 
			{
				int position;
				int normal;
				char slash; 
				stringstream strObj(line.substr(2));
				//strObj.ignore(line.length(), '//');
				for (int i = 0; i < 3; i++) 
				{
					strObj >> position; 
					strObj >> slash;
					strObj >> slash;
					strObj >> normal; 

					TmgVertex vertex(vertexPositions[position - 1], vertexNormals[normal - 1]);					
					vertices.push_back(vertex);	
				}
			}
		}
		myfile.close();
		return true;
	}
	else
	{
		cout << "Unable to open file";
		return false;
	}

	return false;
}

//vector <string> stringSplit(string content, string sep) {
//	char* cstr = const_cast<char*>(content.c_str());
//	char* current;
//	vector<string> arr;
//	current = strtok(cstr, sep.c_str());
//	while (current != NULL) {
//		arr.push_back(current);
//		current = strtok(NULL, sep.c_str());
//	}
//	return arr;
//
//}

/*
bool TmgMesh::loadFromObj(string path)
{
	vector <vec3> vertTemp, normalTemp;
	vector <unsigned int> vertIndex, normalIndex;
	char *cstr = new char[path.length() + 1];
	strcpy(cstr, path.c_str());


	ifstream in(path);
	stringstream buffer;
	buffer << in.rdbuf();
	std::string contents(buffer.str());

	vector <string> linebyline = stringSplit(contents, "\n");


	cout << linebyline[1];

	for (int i = 0; i < linebyline.size(); i++) {
		if (linebyline[i].at(0) == 'v'  && linebyline[i].at(1) != 'n') {
			vector <string>  temp = stringSplit(linebyline[i], " ");
			vec3 vertex;
			vertex.x = stof(temp[1]);
			vertex.y = stof(temp[2]);
			vertex.z = stof(temp[3]);
			vertTemp.push_back(vertex);

		}
		else if (linebyline[i].at(0) == 'v' && linebyline[i].at(1) == 'n') {
			vector <string>  temp = stringSplit(linebyline[i], " ");
			vec3 normal;
			normal.x = stof(temp[1]);
			normal.y = stof(temp[2]);
			normal.z = stof(temp[3]);
			normalTemp.push_back(normal);
		}
		else if (linebyline[i].at(0) == 'f') {
			unsigned int vIndex[3], vtIndex[3];
			vector <string> temp = stringSplit(linebyline[i], " ");

			vIndex[0] = stoi(stringSplit(temp[1], "//")[0]);
			vtIndex[0] = stoi(stringSplit(temp[1], "//")[1]);

			vIndex[1] = stoi(stringSplit(temp[2], "//")[0]);
			vtIndex[1] = stoi(stringSplit(temp[2], "//")[1]);

			vIndex[2] = stoi(stringSplit(temp[3], "//")[0]);
			vtIndex[2] = stoi(stringSplit(temp[3], "//")[1]);

			vertIndex.push_back(vIndex[0]);
			vertIndex.push_back(vIndex[1]);
			vertIndex.push_back(vIndex[2]);

			normalIndex.push_back(vtIndex[0]);
			normalIndex.push_back(vtIndex[1]);
			normalIndex.push_back(vtIndex[2]);

		}
	}

	for (int i = 0; i < vertIndex.size(); i++) {
		unsigned int indexVActual = vertIndex[i];
		unsigned int indexNActual = normalIndex[i];

		vec3 vert = vertTemp[indexVActual - 1];
		vec3 norm = normalTemp[indexNActual - 1];
		TmgVertex vert_final(vert, norm);
		vertices.push_back(vert_final);
	}
	return true;
}
*/