#pragma once
#include "Element.h"
#include <iostream>

template <typename Type>
class List; 





template <typename Type>
std::istream& operator>> (std::istream& in, List<Type>& TheList) {
	Type tmpData;
	in >> tmpData;
	TheList.Insert(tmpData, &TheList);
	return in;
}


template <typename Type>
std::ostream& operator<< (std::ostream& out, List<Type>& TheList) { 
	Element<Type>* currentIndex = TheList.GetRoot(); 
	out << "\n\nСписок\n\n";
	while (currentIndex != nullptr) {
		out << currentIndex->GetData() << " ";
		currentIndex = currentIndex->GetNext();
	}
	out << "\n\n";
	return out;
}


template <typename Type>
List<Type>& operator+ (List<Type>& list1, List<Type>& list2) { 
	if (list1.GetRoot() == nullptr)
		return list2;
	(list1.GetIndex())->SetNext(list2.GetRoot());       
 	((list1.GetIndex())->GetNext())->SetPrev(list1.GetIndex());       
	list1.SetIndex(list2.GetIndex());  
	list2.SetIndex(nullptr);
	list2.SetRoot(nullptr); 
	return list1;      
} 




template <typename Type> 
class List{
private:
	Element<Type>* root;	// первый элемент (корень списка)
	Element<Type>* index;	// текущий элемент.
public:
	List();
	List(Element<Type>* root, Element<Type>* index);
	List(const List<Type>& other);
	~List();
	Element<Type>* GetRoot();
	void SetRoot(Element<Type>* root);  
	Element<Type>* GetIndex();
	void SetIndex(Element<Type>* index);
	void Insert(Type data, List<Type>* TheList);
	void funcNumbering(int cnt);
	void Retrieve(Element<Type>* element); 
	bool Empty();
	void DeleteList();


	friend std::istream& operator>> <Type>(std::istream& in, List<Type>& TheList);			// добавление элементов 
	friend std::ostream& operator<< <Type>(std::ostream& out, List<Type>& TheList);			// вывод списка на экран
	friend List<Type>& operator+ <Type>(List<Type>& list1, List<Type>& list2);				// объединение двух списков
	Element<Type>* operator[](int mainIndex) {												// доступ к элементу
		bool trueIndex = false; 
		Element<Type>* currentIndex = GetRoot(); 
		while (currentIndex != nullptr) {
			if (currentIndex->GetNumber() == mainIndex)
				trueIndex = true;
			currentIndex = currentIndex->GetNext();
		}
		currentIndex = GetRoot();
		if (trueIndex) {
			while (currentIndex->GetNumber() != mainIndex) {
				currentIndex = currentIndex->GetNext();
			}
			return currentIndex;
		}
		else {
			return nullptr;
		}
	}

	List<Type>& operator= (const List<Type>& other) {
		if (this->root != nullptr)
			delete this->root;

		this->index = nullptr;
		this->root = nullptr;

		if (other.root == nullptr)
			return *this;

		Element<Type>* first_element = new Element<Type>(other.root->GetData()); 
		this->root = first_element;  
		this->index = first_element;  
		Element<Type>* new_index_tmp = first_element; 

		Element<Type>* tmp_index = other.root->GetNext();
		while (tmp_index != nullptr) {
			Element<Type>* element = new Element<Type>(tmp_index->GetData());
			this->index = element;
			element->SetPrev(new_index_tmp);
			new_index_tmp->SetNext(element);
			new_index_tmp = new_index_tmp->GetNext();
			tmp_index = tmp_index->GetNext();
		}

		return *this;
	}

};

#include "List.cpp"