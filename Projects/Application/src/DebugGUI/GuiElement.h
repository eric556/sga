#pragma once

namespace Debug {
	class GuiElement {
	public:
		virtual void Draw() = 0;
		bool visible = true;
	};
}
