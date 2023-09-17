#include "Tree.h"
#include <iomanip>

Tree::Tree(int c, int k) {
	n = c + 1;
	o = k;
	W = new float* [n];
	C = new float* [n];
	R = new char** [n];
	m = new int* [n];

	for (int i = 0; i < n; i++) {
		W[i] = new float[n] {};
		C[i] = new float[n] {};
		m[i] = new int[n] {};
		R[i] = new char* [n];
		for (int j = 0; j < n; j++) {
			R[i][j] = new char[o];
		}

	}
}

int Tree::MinC(int i, int j) {
	int res = i + 1;

	for (int k = i + 1; k <= j; k++) {
		if (C[i][k - 1] + C[k][j] <= C[i][res - 1] + C[res][j]) res = k;
	}
	return res;
}

void Tree::print(float** A) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout <<std::setw(8) << std::setprecision(8) << A[i][j] << " ";
		}
		std::cout << "\n";
	}

}

void Tree::printT(Node * v) {


	if (v != 0) {
		std::cout << "(";
		for (int i = 0; i < o; i++) {
			std::cout << v->a[i] << " ";
		}
		

		if (v->leftSon != 0) {
			std::cout << " LS:";
			printT(v->leftSon);
		}

		if (v->rightSon != 0) {
			std::cout << " RS:";
			printT(v->rightSon);
		}
		std::cout << ")";
	}

}

Node* Tree::POD(int i, int j) {
	Node* v = new Node;
	v->a = new char[o];
	for (int k = 0; k < o; k++) {		
		v->a[k] = R[i][j][k];
	}

	if (i < m[i][j]) {
		v->leftSon = POD(i, m[i][j]);

	}
	if (m[i][j] < j - 1) {
		v->rightSon = POD(m[i][j] + 1, j);
	}
	return v;

}

void Tree::KOD(char** A, float* P, float* Q) {

	//ј - это набор псоледовательностей
	//P - веро€тность обращени€ к заданной вершине
	//Q - веро€тности поиска некоторого элемента в данном поддереве

	for (int i = 0; i < n; i++) {
		W[i][i] = Q[i];
		C[i][i] = 0;

	}


	for (int l = 1; l < n; l++) {
		for (int i = 0; i < n - l; i++) {
			int j = i + l;
			W[i][j] = W[i][j - 1] + P[j - 1] + Q[j];

			int k = MinC(i, j);
			C[i][j] = W[i][j] + C[i][k - 1] + C[k][j];

			for (int t = 0; t < o; t++) {
				R[i][j][t] = A[k - 1][t];
			}
			m[i][j] = k - 1;
		}
	}

	T = POD(0, n - 1);
}

void Tree::printTree() {
	std::cout << "Tree:\n";
	printT(T);
	std::cout << "\n";
}

void Tree::printW() {
	std::cout << "W:\n";
	print(W);
	std::cout << "\n";
}

void Tree::printC() {
	std::cout << "C:\n";
	print(C);
	std::cout << "\n";
}

void Tree::printR() {
	std::cout << "R:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int c = 0; c < o; c++) {
				std::cout  << R[i][j][c] << " ";
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}