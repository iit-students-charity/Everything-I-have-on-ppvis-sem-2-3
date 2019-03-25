#pragma once
template <typename data>
class MyGraph
{
public:
	MyGraph();
	~MyGraph();
private:
	const size_t size;
	data** matr;
};

