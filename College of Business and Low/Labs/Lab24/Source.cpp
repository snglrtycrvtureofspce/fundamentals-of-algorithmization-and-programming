#include <iostream>

class Matrix {
private:
	int n;
	int** m;
public:
	Matrix(int n) {
		this->n = n;
		this->m = new int* [this->n];
		if (this->m == NULL) {
			return;
		}
		for (int i = 0; i < this->n; i++) {
			(this->m)[i] = new int[n];
			if ((this->m)[i] == NULL) {
				return;
			}
			for (int j = 0; j < this->n; j++) {
				this->setInt(i, j, rand());
			}
		}
	}
	Matrix(Matrix* matrix) {
		this->n = matrix->getN();
		this->m = new int* [this->n];
		if (this->m == NULL) {
			return;
		}
		for (int i = 0; i < this->n; i++) {
			(this->m)[i] = new int[n];
			if ((this->m)[i] == NULL) {

				return;
			}
			for (int j = 0; j < this->n; j++) {
				this->setInt(i, j, matrix->getInt(i, j));
			}
		}
	}
	int getInt(int i, int j) {
		return (this->m)[i][j];
	}
	void setInt(int i, int j, int num) {
		(this->m)[i][j] = num;
	}
	int getN() {
		return this->n;
	}
	void show() {
		std::cout << "Matrix\n";
		for (int i = 0; i < this->n; i++) {
			for (int j = 0; j < this->n; j++) {
				std::cout << this->getInt(i, j) << "  ";
			}
			std::cout << "\n";
		}
	}
	Matrix operator*(Matrix& matrix) {
		Matrix* matrix_ = new Matrix(&matrix);
		if (this->getN() != matrix.getN()) {
			return NULL;
		}
		for (int i = 0; i < this->n; i++) {
			for (int j = 0; j < this->n; j++) {
				matrix_->setInt(i, j, this->getInt(i, j) * matrix_->getInt(i, j));
			}
		}
		return *matrix_;
	}
	~Matrix() {
		for (int i = 0; i < (this->n); i++) {
			delete[](this->m)[i];
		}
		delete[](this->m);
	}
};

int main() {
	srand(time(NULL));
	Matrix matrix1(5);
	matrix1.show();
	Matrix matrix2(5);
	matrix2.show();
	Matrix matrix3 = matrix1 * matrix2;
	matrix3.show();
	return 0;
}