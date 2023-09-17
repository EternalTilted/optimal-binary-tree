#pragma once
#include <iostream>
#include "Node.h"


class Tree {
private:
	int n = 0;//���������� ������������������� �
	int o = 0;//����������� ������������������� �
	float** W;//������� ���� ������
	float** C;//������� ��������� ������
	char*** R;//������� ��� �������� ������������������� �
	int** m;//������� ��� ���������� ������� ������������������� � ������ ������� 
	Node* T;//�������� ����������� ������

	int MinC(int i, int j);//����� ��� ���������� ������������ ������� ��� ���������� ������� ���������		
	void print(float** A);
	void printT(Node* v);
	Node* POD(int i, int j);//���������� ������������ ������

public:

	Tree(int c, int k);

	void KOD(char** A, float* P, float* Q);//����� ������������ ������

	void printTree();
	void printW();
	void printC();
	void printR();

};