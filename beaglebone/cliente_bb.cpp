#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <netinet/in.h> //htons
#include <arpa/inet.h>  //inet_addr
#include <sys/socket.h> //socket
#include <cstring> 

#include "adc.hpp"
#include "gpio.hpp"

std::mutex potMutex;
std::mutex ldrMutex;
std::mutex butMutex;

struct Package {
	int potenciometro;
	int ldr;
	bool button;
};

void updatePotenciometer(int &pot) {
	bbb::ADC adc_pot(0);

	while (true) {
		potMutex.lock();
		pot = adc_pot.getValue();
		potMutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(12));
	}
}

void updateLDR(int &ldr) {
	bbb::ADC adc_ldr(1);
	
	while (true) {
		ldrMutex.lock();
		ldr = adc_ldr.getValue();
		ldrMutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(12));
	}	
}

void updateButton(bool &button) {
	bbb::GPIO gpio_but(115);
	gpio_but.setModeIn();
	
	while (true) {
		butMutex.lock();
		button = gpio_but.getValue();
		butMutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(12));
	}
}

int main(int argc, char const *argv[]) {
	
	Package pack;
	std::thread potThread(updatePotenciometer, std::ref(pack.potenciometro));
	std::thread ldrThread(updateLDR, std::ref(pack.ldr));
	std::thread buttonThread(updateButton, std::ref(pack.button));

	char ip[16] = "192.168.7.1";
	int PORTNUM = 11100;
	int bytesenviados;

	struct sockaddr_in endereco;
    int socketId;

    memset(&endereco, 0, sizeof(endereco));
    endereco.sin_family = AF_INET;
    endereco.sin_port = htons(PORTNUM);
    endereco.sin_addr.s_addr = inet_addr(ip);

	socketId = socket(AF_INET, SOCK_DGRAM, 0);

    //Verificar erros
    if (socketId == -1) {
        printf("Falha ao executar socket()\n");
        exit(EXIT_FAILURE);
    }
    
	while (true) {
		potMutex.lock();
		ldrMutex.lock();
		butMutex.lock();

	    bytesenviados = sendto(socketId, &pack, sizeof(pack), 0, (sockaddr *) &endereco, sizeof(struct sockaddr));
	 
	    if (bytesenviados == -1) {
	        printf("Falha ao executar send()");
	        exit(EXIT_FAILURE);
	    }

		butMutex.unlock();
		ldrMutex.unlock();
		potMutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}

	return 0;
}
