#pragma once
#include <iostream>
class Chain {
private:
	static const int QUOTA = 10;
	int NUM_max;
	int top;
	int* array;
public:
	int get_top() { return top; };
	Chain() :NUM_max{ QUOTA }, top{ 0 }, array{ new int[QUOTA] } {}
	Chain(int elem);
	Chain(int n, int* A);
	~Chain() { delete[] array; }
	Chain(const Chain& chain);
	friend std::istream& operator >> (std::istream& in, Chain& chain);
	int* get_array();
	Chain(Chain&& chain);
	Chain& operator =(const Chain& chain);
	Chain& operator =(Chain&& chain);
	friend std::ostream& operator << (std::ostream& s, const Chain& chain);
	int& operator [](int index);
	void push(int k);
	friend Chain operator+(const Chain& s1, const Chain& s2);
	friend Chain und_chain(Chain& chain);
	int differences() const;
	int same_elem(int k) const;
};
