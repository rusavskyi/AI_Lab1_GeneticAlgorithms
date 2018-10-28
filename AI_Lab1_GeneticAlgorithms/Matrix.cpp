#include "stdafx.h"
#include "Matrix.h"


Matrix::Matrix()
{
	columns = 3;
	rows = 3;
	Initialization();
}

Matrix::Matrix(int size)
{
	columns = size;
	rows = size;
	Initialization();
}

Matrix::Matrix(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	Initialization();
}

Matrix::~Matrix() = default;

int Matrix::GetValue(int row, int column)
{
	if (row < rows && column < columns)
		return matrix[row][column];
	throw exception("Index out of bounds.");
}

int Matrix::SetValue(int row, int column, int value)
{
	if (row < rows && column < columns)
		matrix[row][column] = value;
	else
		throw exception("Index out of bounds.");
}

void Matrix::Initialization()
{
	matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[columns];
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = 0;
		}
	}
}
