#include <fstream>
#include "adc.hpp"

namespace bbb {
	ADC::ADC(const int &id){
		ADC::path = "/sys/bus/iio/devices/iio:device0/in_voltage" + std::to_string(id) + "_raw";
	}

	int ADC::getValue() {
		int ret;
		ADC::stream.open(path);
		ADC::stream >> ret;
		ADC::stream.close();
		return ret;
	}
}