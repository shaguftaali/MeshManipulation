#pragma once
#include "SceneObject.h"
#include "Polymesh_info.h"
#include "Selection.h"
#include "MeshEditor/MeshElements/Vertex.h"
#include "MeshEditor/MeshElements/HalfEdge.h"
#include "MeshEditor/Light/BSDF.h"

class Mesh: public MeshManupulation::SceneObject
{
public:
	Mesh(PolymeshInfo& polymesh, const Matrix4& transform);

	~Mesh();

	void set_draw_styles(DrawStyle* defaultStyle, DrawStyle* hoveredStyle,
						 DrawStyle* selectedStyle) override;

	virtual  void draw() override;
	virtual void drawGhost() override;

	void draw_pretty() override;

	SceneObject *get_transformed_static_object(double t) override;

	MeshManupulation::BBox get_bbox() override;

	virtual MeshManupulation::Info getInfo() override;

	void bevelComputeNewPositions(double inset,double shift);

	virtual void drag(double x, double y,double dx,double dy, const Matrix4& modelViewProj) override;

	BSDF* get_bsdf() const override;

	void collapse_selected_element();
	void flip_selectd_edge();
	void split_selected_edge();
	void erase_selected_element();
	void bevel_selected_element();
	void upsample();
	void downsample();
	void resample();
	void triangulate();

	MeshManupulation::HalfEdgeMesh mesh;

	virtual void draw_pick(int &pickID, bool transformed=false) override;

	virtual void setSelection(int pickID, MeshManupulation::Selection& selection) override;

private:
	void draw_faces(bool smooth=false) const;
	void draw_edge() const;
	void draw_feature_if_needed(MeshManupulation::Selection* s) const;
	void draw_vertex(const MeshManupulation::Vertex* v) const;
	void draw_halfedge_arrow(const MeshManupulation::HalfEdge* h) const;
	DrawStyle *get_draw_style(const MeshManupulation::HalfEdgeElement* element) const;

	BSDF *bsdf;
};
