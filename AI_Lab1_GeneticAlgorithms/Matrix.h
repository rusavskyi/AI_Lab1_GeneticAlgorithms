#pragma once
class Matrix
{
public:
	Matrix();
	Matrix(int size);
	Matrix(int rows, int columns);
	~Matrix();

	int GetValue(int row, int column);
	int SetValue(int row, int column, int value);

protected:
	int ** matrix;
	int rows, columns;

private:
	void Initialization();
};
