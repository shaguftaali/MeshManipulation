#pragma once
#include <vector>
#include "../Maths/Vector3.h"
#include "../3D/Object.h"
#include "../Physics/Collision/BoundingSphere.h"

class Sphere :public Object
{
public:

	Sphere(const char * vertexPath, const char * fragmentPath,Vector3 position,float m_radius,int a_totalSections,Node* a_parent);
	
	void Render(const Camera& camera) override;
	BoundingSphere GetBoundingSphere();
	static  Sphere Test();

	void SelectionRender(Camera camera);
;
private:

	float radius;
	int totalSections;
	BoundingSphere m_boundingSphere;

	Shader s;

protected:
	
	void SetVertices() override;
	void SetIndices() override;
	void SetDrawingData() override;
	void SetNormal() override;
};
