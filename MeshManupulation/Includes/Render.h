#pragma once
#include <string>

namespace MeshManupulation
{
	class Renderer
	{
	public:
		virtual ~Renderer(void)
		{
			
		}

		virtual  void init(void)=0;

		virtual  void render(void )=0;

		virtual  void resize(size_t w, size_t h)=0;

		virtual std::string info(void)=0;

		virtual  void cursor_event(float x,float y);

		virtual  void scroll_event(float offset_x, float offdet_y);

		virtual  void mouse_event(int key,int event,unsigned char mods);

		virtual  void keyboard_event(int key,int event,unsigned char mods);

		virtual void char_event(unsigned int codepoint);

		void use_hdpi_render_target()
		{
			use_hdpi=true;
		}

	protected:
		bool use_hdpi;


	};
}
