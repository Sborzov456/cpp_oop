#include <iostream>
#include <vector>
#include <exception>

typedef struct Node
{
	int data;
	int index;
}Node; //вот такая структура послужит хранением ненулевого элемента и его индекса, так как не эффективно писать в матрицу нули из-за их кол-ва

class SpraceMatrix
{
private:
	std::vector<std::vector<Node>> matrix;
	unsigned size;
public:
	SpraceMatrix() : size(0) {}
	SpraceMatrix(const std::vector<std::vector<Node>>& _matrix) : matrix(_matrix) {
		for(unsigned i = 0; i < _matrix.size(); i++)
		{
			size += _matrix[i].size();
		}
	}
	~SpraceMatrix() = default;

	void setElement(const Node& _node, unsigned i, unsigned j){
		if(i < 0 || j < 0 || i > matrix.size() || j > matrix[i].size())
			throw std::exception("Out of range!\n");
		matrix[i][j] = _node;
	}//i - номер столбца, j - номер строки 
	
	void getElement(unsigned i, unsigned j){
		if(i < 0 || j < 0 || i > matrix.size() || j > matrix[i].size())
			throw std::exception("Out of range!\n");
		return matrix[i][j];
	}//i - номер столбца, j - номер строки 
}