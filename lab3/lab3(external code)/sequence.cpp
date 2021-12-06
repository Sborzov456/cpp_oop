#include "sequence.h"
int& Chain:: operator [] (int index) {

	if (index < 0 || index >= top)
	{
		throw std::out_of_range("bad index");
	}
	return(array[index]);
}

Chain::Chain(int elem) :top{ 1 }, NUM_max{ QUOTA }, array{ new int[QUOTA] } {
	array[0] = elem;
}

Chain::Chain(int n, int* A) : top{ n }, NUM_max{ (n / 10 + 1) * QUOTA }, array{ new int[NUM_max] } {
	if (n >= 0)
	{
		memcpy(array, A, n * sizeof(int));
		//for (int i = 0; i < top; i++)
		//{
		//	array[i] = A[i];
		//}
	}
}

int* Chain::get_array() {
	return (array);
}

Chain::Chain(const Chain& chain) : top{ chain.top }, NUM_max{ chain.NUM_max }
{
	//std::cout << "& constr" << std::endl;
	array = new int[NUM_max];
	//for (int i = 0; i < top; i++)
	//{
	memcpy(array, chain.array, top * sizeof(int));
	//array[i] = chain.array[i];
//}

}

Chain& Chain::operator =(const Chain& chain)
{
	//std::cout << "& operator" << std::endl;
	if (this != &chain)
	{
		NUM_max = chain.NUM_max;
		top = chain.top;
		delete[] array;
		array = new int[NUM_max];
		//for (int i = 0; i < top; i++)
		//{
		memcpy(array, chain.array, top * sizeof(int));
		//array[i] = chain.array[i];
	//}
		return *this;
	}
	return *this;


}
Chain::Chain(Chain&& chain) :array{ chain.array }, top{ chain.top }, NUM_max{ chain.NUM_max }
{
	//std::cout << "&& constr" << std::endl;
	chain.array = nullptr;
}

Chain& Chain ::operator =(Chain&& chain)
{
	//std::cout << "&& operator" << std::endl;
	if (this != &chain)
	{
		NUM_max = chain.NUM_max;
		top = chain.top;
		delete[] array;
		array = chain.array;
		chain.array = nullptr;
		return *this;
	}
	return *this;

}
std::istream& operator >> (std::istream& in, Chain& chain)
{
	in >> chain.top;
	chain.NUM_max = chain.QUOTA * (chain.top / 10 + 1);
	chain.array = new int[chain.NUM_max];

	if (chain.top <= chain.NUM_max) {

		for (int i = 0; i < chain.top; i++)
		{
			in >> chain.array[i];
		}

		return in;
	}
	else {
		throw std::out_of_range("Invalid number of items");
	}
}

std::ostream& operator <<(std::ostream& s, const Chain& chain) {
	if (chain.top == 0)
	{
		s << "Chain is empty";

	}
	else {
		for (int i = 0; i < chain.top; i++)
		{
			s << chain.array[i] << " ";
		}
		s << std::endl;

	}
	return s;
}

void Chain::push(int k) {
	if (top >= NUM_max) {
		NUM_max += QUOTA;
		int* old = array;
		array = new int[NUM_max];
		//for (int i = 0; i < top; i++)
		//{
			//array[i] = old[i];
		//}
		memcpy(array, old, top * sizeof(int));
		delete[] old;

	}

	array[top] = k;
	top++;
}
// 132104 

Chain operator+(const Chain& s1, const Chain& s2) {
	{

		Chain chain3 = s1;


		int y = 0;

		while (y != s2.top) {
			chain3.push(s2.array[y]);
			y++;
		}
		return chain3;
	}

}
Chain und_chain(Chain& chain) {
	Chain chain2;
	if (chain.top >= 3)
	{
		int f = 2;
		for (int i = 0; i < chain.top; i++)
		{
			int j;

			if (i + 1 < chain.top && chain.array[i] < chain.array[i + 1])
			{
				j = i + 1;

				while (j + 1 < chain.top && chain.array[j] < chain.array[j + 1])
				{
					f++;
					j++;

				}
				if (f >= 3)
				{
					for (int o = 0; o < f; o++)
					{
						chain2.push(chain.array[i]);
						i++;
					}
					return chain2;
				}

			}
			if (i + 1 < chain.top && chain.array[i] > chain.array[i + 1])
			{
				j = i + 1;

				while (j + 1 < chain.top && chain.array[j] > chain.array[j + 1])
				{
					f++;
					j++;

				}
				if (f >= 3)
				{
					for (int o = 0; o < f; o++)
					{
						chain2.push(chain.array[i]);
						i++;
					}
					return chain2;
				}

			}


		}
		return chain2;
	}
	return chain2;


}
int Chain::differences() const {
	int num = 0;
	int flag = 0;
	for (int i = 0; i < top; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (array[i] == array[j] && i != j)
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			num++;

		}
		flag = 0;
	}
	return num;
}
int Chain::same_elem(int k) const
{
	int num = 0;
	for (int i = 0; i < top; i++)
	{
		if (k == array[i])
		{
			num++;
		}
	}
	return num;
}