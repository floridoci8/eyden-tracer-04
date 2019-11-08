#include "Scene.h"

#include "ShaderEyelight.h"
#include "ShaderEyelightTextured.h"
#include "ShaderPhong.h"
#include "PrimTriangle.h"
#include "PrimTriangleSmooth.h"
#include "PrimTriangleSmoothTextured.h"

#include <fstream> 


void CScene::ParseOBJ(const std::string& fileName)
{
	std::ifstream file(fileName);

	if (file.is_open()) {
		std::cout << "Parsing OBJFile : " << fileName << std::endl;

		std::shared_ptr<IShader> pShader = std::make_shared<CShaderEyelight>(RGB(1, 0.5f, 0));
		std::vector<Vec3f> vVertexes;
		std::vector<Vec3f> v_textures;
		std::vector<Vec3f> v_normal;
		std::string line;

		for (;;) {
			if (!getline(file, line)) break;
			std::stringstream ss(line);
			getline(ss, line, ' ');
			if (line == "v") {
				Vec3f v;
				for (int i = 0; i < 3; i++) ss >> v.val[i];
				// std::cout << "Vertex: " << v << std::endl;
				vVertexes.emplace_back(v);
			}
			else if (line == "vt") {
				Vec3f vt;
				for (int i = 0; i < 2; i++) ss >> vt.val[i];
				v_textures.emplace_back(vt);
			}
			else if (line == "vn") {
				Vec3f vn;
				for (int i = 0; i < 3; i++) ss >> vn.val[i];
				v_normal.emplace_back(vn);
			}
			else if (line == "f") {
				Vec3i f, ft, fn; char slash;
				for (int i = 0; i < 3; i++) {
					ss >> f.val[i] >> slash >> ft.val[i] >> slash >> fn.val[i];
					// std::cout << "Face: " << f << std::endl;	
				}
				Add(std::make_shared<CPrimTriangleSmooth>(vVertexes[f.val[0] - 1], vVertexes[f.val[1] - 1], vVertexes[f.val[2] - 1], v_normal[fn.val[0] - 1], v_normal[fn.val[1] - 1], v_normal[fn.val[2] - 1], pShader));
			}
			else if (line == "#") {
				
			}
			else {
				std::cout << "Unknown key [" << line << "] met in the OBJ file" << std::endl;
			}
		}

		file.close();
		std::cout << "Finished Parsing" << std::endl;
	} else
		std::cout << "ERROR: Can't open OBJFile" << std::endl;
}
