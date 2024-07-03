#include <vector>

#ifndef HEADERFILES_MATRIX_H_
#define HEADERFILES_MATRIX_H_
/* 3D array
 * Example of mapping
 * 2x2x2
 *
 * h1 			h2
 * |n1m1|n1m2|  |n1m1|n1m2|
 * |n2m1|n2m2|	|n2m1|n2m2|
 *
 *	Implemented as a 3d array.
 *	matrix3[h][n][m]
 */
class Matrix3 {
private:
	std::vector<std::vector<std::vector<char>*>*>* matrix3;
public:
	Matrix3();
	Matrix3(int n, int m, int h);
	~Matrix3();
	int get (int n, int m, int h);
	void set (int n, int m, int h, char symbol);
	int sizeN();
	int sizeM();
	int sizeH();
};

Matrix3::Matrix3(){
	matrix3 = nullptr;
}

//Constructor
Matrix3::Matrix3(int n, int m, int h){
	matrix3 = new std::vector<std::vector<std::vector<char>*>*>(h);
	for (int i = 0; i < h; i++){
		(*matrix3)[i] = new std::vector<std::vector<char>*>(n);
		for (int j = 0; j < n; j++)
			(*(*matrix3)[i])[j] = new std::vector<char>(m);
	}
}

//Destructor
Matrix3::~Matrix3() {
	for (int i = 0; i < (*matrix3).size(); i++){
		for (int j = 0; j < (*(*matrix3)[i]).size(); j++){
			delete (*(*matrix3)[i])[j];
		}
		delete (*matrix3)[i];
	}
	delete matrix3;
}

//Getter
int Matrix3::get(int n, int m, int h){
	return (*(*(*matrix3)[h])[n])[m];
}

//Setter
void Matrix3::set(int n, int m, int h, char symbol){
	(*(*(*matrix3)[h])[n])[m] = symbol;
}

int Matrix3::sizeN(){
	return (*matrix3)[0]->size();
}
int Matrix3::sizeM(){
	return (*(*matrix3)[0])[0]->size();
}
int Matrix3::sizeH(){
	return matrix3->size();
}


#endif
