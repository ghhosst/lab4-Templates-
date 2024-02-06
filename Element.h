#pragma once

template <typename Type>
class Element{
private: 
	Type data;
	Element<Type>* next;
	Element<Type>* prev; 
	int number;
public:
	Element();
	Element(Type data);
	Element(const Element<Type>& other);
	~Element();
	Type GetData();
	void SetData(Type data);
	Element<Type>* GetNext();
	void SetNext(Element<Type>* next);
	Element<Type>* GetPrev();
	void SetPrev(Element<Type>* prev);
	int GetNumber();
	void SetNumber(int number);
};

#include "Element.cpp"