#pragma once
#include <iostream>
#include "Node.h"


class Tree {
private:
	int n = 0;//количество последовательностей а
	int o = 0;//размерность последовательностей а
	float** W;//матрица веса вершин
	float** C;//матрица стоимости вершин
	char*** R;//матрица для хранения последовательностей а
	int** m;//матрица для сохранения номеров последовательностей а каждой вершины 
	Node* T;//двоичное оптимальное дерево

	int MinC(int i, int j);//метод для нахождения минимального индекса для построения матрицы стоимости		
	void print(float** A);
	void printT(Node* v);
	Node* POD(int i, int j);//построение оптимального дерева

public:

	Tree(int c, int k);

	void KOD(char** A, float* P, float* Q);//корни оптимального дерева

	void printTree();
	void printW();
	void printC();
	void printR();

};