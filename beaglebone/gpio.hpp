#include <fstream>

namespace bbb {
	class GPIO {
		std::fstream stream;
		std::string path;

	public:
		// Class constructor.
		// Takes the GPIO id and modifies the info regarding it on the board
		GPIO(const int &id);

		// sets "value" to 1
		void setValueOn();
		// sets "value" to 0
		void setValueOff();
		// returns "value"
		bool getValue();

		// sets direction to "in"
		void setModeIn();
		// sets direction to "out"
		void setModeOut();
		// returns direction ("in" or "out")
		std::string getMode();
	};
}