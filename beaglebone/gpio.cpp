#include <fstream>
#include <cstdlib>
#include "gpio.hpp"

namespace bbb {
	GPIO::GPIO(const int &id) {
		// Tratamento pra saber se existe e instanciar se necessario
		GPIO::path = "/sys/class/gpio/gpio" + std::to_string(id);
		GPIO::stream.open(path);
		if( !stream.is_open() ) {
			system(("echo " + std::to_string(id) + " > /sys/class/gpio/export").c_str());
			GPIO::stream.open(path);
		}

	}

	void GPIO::setValueOn() {
		GPIO::stream.open(path + "/value");
		GPIO::stream << 1;
		GPIO::stream.close();
	}

	void GPIO::setValueOff() {
		GPIO::stream.open(path + "/value");
		GPIO::stream << 0;
		GPIO::stream.close();
	}

	bool GPIO::getValue() {
		bool ret;
		GPIO::stream.open(path + "/value");
		GPIO::stream >> ret;
		GPIO::stream.close();
		return ret;
	}

	void GPIO::setModeIn() {
		GPIO::stream.open(path + "/direction");
		GPIO::stream << "in";
		GPIO::stream.close();
	}

	void GPIO::setModeOut() {
		GPIO::stream.open(path + "/direction");
		GPIO::stream << "out";
		GPIO::stream.close();
	}

	std::string GPIO::getMode() {
		std::string ret;
		GPIO::stream.open(path + "/direction");
		GPIO::stream >> ret;
		GPIO::stream.close();
		return ret;
	}
}