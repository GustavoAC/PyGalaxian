#include <fstream>

namespace bbb {
	class ADC {
		std::fstream stream;
		std::string path;
	
	public:
		ADC(const int &id);
		int getValue();
	};
}
