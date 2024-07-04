#include <vector>

#ifndef HEADERFILES_MATRIX_H_
#define HEADERFILES_MATRIX_H_
/* 3D array of nxnxnx
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
	Matrix3() : Matrix3(3) {}
	Matrix3(int n);
	~Matrix3();
	char get (int x, int y, int z);
	void set (int x, int y, int z, char symbol);
	int size();
};

//Constructor
Matrix3::Matrix3(int n){
	matrix3 = new std::vector<std::vector<std::vector<char>*>*>();
	matrix3->reserve(n);

	for (int i = 0; i < n; i++){
		matrix3->push_back(new std::vector<std::vector<char>*>());
		for (int j = 0; j < n; j++){
			(*matrix3)[i]->reserve(n);
			(*matrix3)[i]->push_back(new std::vector<char>(n, ' '));
		}
	}
}

//Destructor
Matrix3::~Matrix3() {
	for (int i = 0; i < matrix3->size(); i++){
		for (int j = 0; j < matrix3->size(); j++){
			delete (*(*matrix3)[i])[j];
		}
		delete (*matrix3)[i];
	}
	delete matrix3;
}

//Getter
char Matrix3::get(int n, int m, int h){
	return (*(*(*matrix3)[h])[n])[m];
}

//Setter
void Matrix3::set(int n, int m, int h, char symbol){
	(*(*(*matrix3)[h])[n])[m] = symbol;
}

//Returns dimension size
int Matrix3::size(){
	return matrix3->size();
}


#endif
