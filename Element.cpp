#ifndef TEMPL1 
#define TEMPL1

#include "Element.h"

template <typename Type>
Element<Type>::Element() {
	this->data = 0;
	this->number = 0;
	this->next = nullptr;
	this->prev = nullptr;
}

template <typename Type>
Element<Type>::Element(Type data) {
	this->data = data;
}

template <typename Type>
Element<Type>::Element(const Element<Type>& other) {
	this->data = other->data;
	this->next = other->next;
	this->number = other->number;
	this->prev = other->prev; 
}


template <typename Type>
Element<Type>::~Element() {
	this->next = nullptr;
	this->prev = nullptr;
	this->data = 0;
	this->number = 0;
}

template <typename Type>
Type Element<Type>::GetData() {
	return this->data;
}

template <typename Type>
void Element<Type>::SetData(Type data) {
	this->data = data;
}

template <typename Type>
Element<Type>* Element<Type>::GetNext() {
	return this->next;
}

template <typename Type>
void Element<Type>::SetNext(Element<Type>* next) {
	this->next = next;
}

template<typename Type>
Element<Type>* Element<Type>::GetPrev()
{
	return this->prev;
}

template <typename Type>
void Element<Type>::SetPrev(Element<Type>* prev) {
	this->prev = prev;
}

template <typename Type>
int Element<Type>::GetNumber() {
	return this->number;
}

template <typename Type>
void Element<Type>::SetNumber(int number) {
	this->number = number;
}

#endif