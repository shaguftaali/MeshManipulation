#include "..\..\Includes\Shapes\Sphere.h"

#define PI 3.14
Sphere::Sphere(const char * vertexPath, const char * fragmentPath, Vector3 position, float m_radius, int a_totalSections, Node* a_parent) :
Object(vertexPath,fragmentPath,position,a_parent),
radius(m_radius),
totalSections(a_totalSections),
m_boundingSphere(position,m_radius),
s(
	//"D:/Shagufta/OpenGL_Workspace/MeshManupulation/MeshManupulation/Shaders/SelectionVert.vs",
	"D:/Shagufta/OpenGL_Workspace/MeshManupulation/MeshManupulation/Shaders/LightVertexShader.vs",
	"D:/Shagufta/OpenGL_Workspace/MeshManupulation/MeshManupulation/Shaders/SelectionFrag.fs"
)
{
	
	SetVertices();
	SetIndices();
	SetNormal();
	SetDrawingData();
}

void Sphere::Render(const Camera & camera)
{
	Object::Render(camera);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	shader.setVec3("lightPos", 0.0f, 0.0f, 50.0f);
	shader.setVec3("objectColor", 0.5f, 0.2f, 0.51f);
	shader.setVec3("lightColor", 1.0f, 0.5f, 1.0f);
	//shader.setInt("code", 1);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

	
}

BoundingSphere Sphere::GetBoundingSphere()
{
	return m_boundingSphere;
}

Sphere Sphere::Test()
{
	Sphere sphere(
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightVertexShader.vs",
		"D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightFragmentShader.fs",
		Vector3(0, 0, 0),
		5,
		30,
		nullptr
	);
	return sphere;
}

void Sphere::SelectionRender(Camera camera)
{
	s.use();
	if (parent == nullptr)
	{
		s.setMat4("model", transform.modelMatrix);
	}
	else
	{
		s.setMat4("model", transform.worldMatrix);
	}
	s.setMat4("view", camera.viewMatrix);
	s.setMat4("projection", camera.projectionMatrix);
	s.setInt("code", 1);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}



void Sphere::SetVertices()
{
	float phi=0;
	float theta=0;

	//Vector3 center=transform.position;
	Vector3 topCenter=Vector3(0,0,+radius);
	Vector3 bottomCenter = Vector3(0, 0,-radius);

	vertices.push_back(topCenter.x);
	vertices.push_back(topCenter.y);
	vertices.push_back(topCenter.z);
	for (int i=0;i<totalSections-1;i++)
	{
		phi+=PI/totalSections;
		theta=0;
		for (int j=0;j<totalSections;j++)
		{
			theta+=2*PI/totalSections;
			float x=radius*sin(phi)*cos(theta);
			float y=radius*sin(phi)*sin(theta);
			float z=radius*cos(phi);
			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);

		}

	}

	

	vertices.push_back(bottomCenter.x);
	vertices.push_back(bottomCenter.y);
	vertices.push_back(bottomCenter.z);
}



void Sphere::SetIndices()
{
	
	int count= totalSections;
	int lastVertexIncides=(vertices.size()/3)-1;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < totalSections; j++)
		{
			
			if(i==0)
			{

				indices.push_back(0);
				indices.push_back(j + 1);
				if (j == totalSections - 1)
				{
					indices.push_back(1);
				}
				else
				{
					indices.push_back(j + 2);
				}

			}
			//else if(i<totalSections-1)
			else if (i<count - 1)
			{

				int  index =(i-1)*totalSections+1 + j;

				if (j == totalSections - 1)
				{
					indices.push_back(index);
					indices.push_back((i-1)*totalSections+1);
					indices.push_back(index + totalSections);


					indices.push_back((i - 1)*totalSections + 1);
					indices.push_back(i *totalSections+1);
					indices.push_back(index + totalSections);
					//indices.push_back(20);
				}
				else
				{
					indices.push_back(index);
					indices.push_back(index + 1);
					indices.push_back(index + totalSections);


					indices.push_back(index + 1);
					indices.push_back(index + totalSections + 1);
					indices.push_back(index + totalSections);

					
				}
			}
			else
			{

				
				indices.push_back(lastVertexIncides);
				indices.push_back(lastVertexIncides-j - 1);
				if (j == totalSections - 1)
				{
					indices.push_back(lastVertexIncides-1);
				}
				else
				{
					indices.push_back(lastVertexIncides-j - 2);
				}

			}
			
		}
	

	}
}

void Sphere::SetDrawingData()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(vertices.size()+normal.size()),nullptr, GL_DYNAMIC_DRAW);


	glBufferSubData(GL_ARRAY_BUFFER,0,sizeof(float)*(vertices.size()),&vertices[0]);
	glBufferSubData(GL_ARRAY_BUFFER,sizeof(float)*(vertices.size()),sizeof(float)*(normal.size()),&normal[0]);
	

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*(indices.size()), &indices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(sizeof(float) * vertices.size()));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void Sphere::SetNormal()
{
	for (int i = 0; i < vertices.size()-3; )
	{
		Vector3 vertex(vertices[i],vertices[i+1],vertices[i+2]);
		Vector3 normalValue=(transform.position - vertex).Normalization();
		normal.push_back(normalValue.x);
		normal.push_back(normalValue.y);
		normal.push_back(normalValue.z);
		i+=3;
	}
}
