#include <iostream>
#include "Node.h"
#include "Tree.h"



int main() {
	int n = 4;
	int k = 1;
	Tree f(n, k);
	char** a = new char*[n]{ new char[k] {'a'}, new char[k] {'b'}, new char[k] {'c'}, new char[k] {'d'}};
	float* p = new float[n]{ 0.25, 0.125, 0.0625, 0.0625 };
	float* q = new float[n+1]{0.125, 0.1875,  0.0625,  0.0625, 0.0625 };
	f.KOD(a, p, q);
	f.printW();
	f.printC();
	f.printR();
	f.printTree();

}