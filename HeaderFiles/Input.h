#include <iostream>

#ifndef HEADERFILES_INPUT_H_
#define HEADERFILES_INPUT_H_

class tttInput {
public:
	int getN();
	int getH();
	int getM();
};

int tttInput::getN(){
	int n;
	std::cin >> n;
	return n;
}
int tttInput::getH(){
	int h;
	std::cin >> h;
	return h;
}
int tttInput::getM(){
	int m;
	std::cin >> m;
	return m;
}
#endif
