#include "..\..\..\Includes\MeshEditor\MeshElements\Widgets.h"
#include "Maths/Matrix3x3.h"

MeshManupulation::Widgets::Widgets()
{
	target.object=nullptr;
	target.element=nullptr;
	objectMode=false;
	transformedMode=false;
	jointMode=false;
	jointIsRoot=false;
	mode=lastMode=Mode::Translate;
}

void MeshManupulation::Widgets::setTarget(Selection & _target)
{
	auto originalObj=target.object;
	target=_target;
	if(objectMode)
	{
		if(target.object == this)
		{
			target.object=originalObj;
		}
	}
	updateGeometry();
}

void MeshManupulation::Widgets::setTranslate()
{
	if(lastMode !=Mode::Translate)
	{
		lastMode=mode;
	}
	mode=Mode::Translate;
}

void MeshManupulation::Widgets::setRotation()
{
	if(lastMode!=Mode::Rotate)
	{
		lastMode=mode;
	}
	mode=Mode::Rotate;
}

void MeshManupulation::Widgets::setScale()
{
	if(lastMode!=Mode::Scale)
	{
		lastMode=mode;
	}
	mode=Mode::Scale;
}

void MeshManupulation::Widgets::cycleMode()
{
	if(jointMode){
		return;
	}

	if(mode==Mode::Translate)
	{
		mode=Mode::Rotate;
	}
	else if(mode==Mode::Rotate)
	{
		mode=Mode::Scale;
	}
	else if(mode==Mode::Scale)
	{
		mode=Mode::Translate;
	}
}

void MeshManupulation::Widgets::restoreLastMode()
{
	mode=lastMode;
}

void MeshManupulation::Widgets::setClickPosition(const Vector2 & position)
{
	clickPosition=position;
}

void MeshManupulation::Widgets::draw()
{
	if(target.object==nullptr)
	{
		return;
	}


}

void MeshManupulation::Widgets::drawGhost()
{}

MeshManupulation::BBox MeshManupulation::Widgets::get_bbox()
{
	return bounds;
}

MeshManupulation::Info MeshManupulation::Widgets::getInfo()
{
	Info info;
	if(target.element!=nullptr)
	{
		info=target.element->getInfo();
		return info;
	}

	if(target.object!=nullptr)
	{
		info=target.object->getInfo();
		return info;
	}

	info.push_back("TRANSFORMATION");
	return info;

}

void MeshManupulation::Widgets::drag(double x, double y, double dx, double dy, const Matrix4 & modelViewProj)
{}

MeshManupulation::SceneObject * MeshManupulation::Widgets::get_static_object()
{
	return nullptr;
}

void MeshManupulation::Widgets::draw_pick(int & pickID, bool transformed)
{}

void MeshManupulation::Widgets::setSelection(int pickID, Selection & selection)
{}

void MeshManupulation::Widgets::updateGeometry()
{}

void MeshManupulation::Widgets::enterObjectMode()
{}

void MeshManupulation::Widgets::exitObjectMode()
{}

void MeshManupulation::Widgets::enterJointMode(bool isRoot)
{}

void MeshManupulation::Widgets::exitJointMode()
{}

void MeshManupulation::Widgets::enterTransformedMode()
{}

void MeshManupulation::Widgets::exitTransformMode()
{}

void MeshManupulation::Widgets::directionalTransform(Vector3 & position, std::vector<int> tranformAxes, Vector3 center,
													 double x, double y, double dx, double dy, const Matrix4 & modelViewProj)
{
	int i=0;
	for (int p = 0; p < 3; ++p)
	{
		if(tranformAxes[p])
		{
			i=p;
			break;
		}
	}

	Matrix3x3 E(axes[0],axes[1],axes[2]);

	if(mode==Mode::Rotate)
	{
		Vector4 d(center,1.0);
		d=modelViewProj*d;
		d.x=d.x/d.w;
		d.y=d.y/d.w;
		d.z=d.z/d.w;


	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT,viewport);

	Vector2 A(x,y);
	Vector2 B=clickPosition;
	Vector2 C(viewport[2]*(d.x+1.0)/2.0,viewport[3]*(1.0-(d.y+1.0)/2.0));

	Vector2 U=(A-C).Normalization();
	Vector2 V=(B-C).Normalization();

		double m=atan2(Vector2::CrossProduct(U,V),Vector2::DotProduct(U,V));

	}

	
}

void MeshManupulation::Widgets::drawHandles() const
{
	switch (mode)
	{
	case Mode::Translate:
		drawTranslateHandles();
		break;

	case Mode::Rotate:
		drawRotateHandles();
		break;

	case Mode::Scale:
		drawScaleHandles();
		break;

	default:
		break;
	}
}

void MeshManupulation::Widgets::drawTranslateHandles() const
{}

void MeshManupulation::Widgets::drawRotateHandles() const
{}

void MeshManupulation::Widgets::drawScaleHandles() const
{}

void MeshManupulation::Widgets::drawCenterHandle() const
{}
