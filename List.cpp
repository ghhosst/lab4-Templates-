#ifndef TEMPL2  
#define TEMPL2

#include "List.h"





template <typename Type>
List<Type>::List() {
	this->root = nullptr;
	this->index = nullptr;
}

template <typename Type>
List<Type>::List(Element<Type>* root, Element<Type>* index) {
	this->root = root;
	this->index = index;
}

template <typename Type>
List<Type>::List(const List<Type>& other) {
	this->index = nullptr;
	this->root = nullptr;

	if (other.root == nullptr) 
		return;

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
}


template <typename Type>
List<Type>::~List() {
	if (root == nullptr) 
		return;
	else {
		if (root == index) {
			delete root;
			root = nullptr;
			index = nullptr;
		}
		else {
			Element<Type>* tmpElement;
			while (root != nullptr) {
				tmpElement = root;
				root = tmpElement->GetNext();
				delete tmpElement;
			}
			root = nullptr;
			index = nullptr;
		}
	}
}

template <typename Type>
Element<Type>* List<Type>::GetRoot() {
	return this->root;
}

template <typename Type>
void List<Type>::SetRoot(Element<Type>* root) {
	this->root = root;
}

template <typename Type>
Element<Type>* List<Type>::GetIndex() {
	return this->index;
}

template <typename Type>
void List<Type>::SetIndex(Element<Type>* index) {
	this->index = index;
}


template <typename Type>
void List<Type>::Insert(Type data, List<Type>* TheList) {
	Element<Type>* element = new Element<Type>(data);
	element->SetPrev(TheList->index); 
	if (root == nullptr)
		root = element;
	if (index != nullptr) {
		index->SetNext(element);
	}
	index = element;
}

template <typename Type>
void List<Type>::funcNumbering(int cnt) {
	Element<Type>* currentIndex = GetRoot();
	while (currentIndex != nullptr){
		currentIndex->SetNumber(cnt);
		currentIndex = currentIndex->GetNext();
		cnt++; 
	}
}

template <typename Type>
void List<Type>::Retrieve(Element<Type>* element) {
	if (element == nullptr) {
		std::cout << "\n\nИндекс выходит за рамки списка, или введён нецелочисленный индекс !!!\n\n";
		return;
	}
	if ((element->GetPrev() == nullptr) && (element->GetNext() == nullptr)) {
		delete element;
		element = nullptr;
		root = nullptr;
		index = nullptr;
	}
	else {
		if (element->GetPrev() == nullptr) {
			(element->GetNext())->SetPrev(nullptr);
			root = element->GetNext(); 
			delete element;
			element = nullptr;
		}
		else {
			if (element->GetNext() == nullptr) {
				(element->GetPrev())->SetNext(nullptr);
				index = element->GetPrev(); 
				delete element;
				element = nullptr;
			}
			else {
				(element->GetPrev())->SetNext(element->GetNext());
				(element->GetNext())->SetPrev(element->GetPrev());
				delete element;
				element = nullptr;
			}
		}
	}
	std::cout << "\n\nЭлемент успешно извлечён !\n\n"; 
}

template <typename Type>
bool List<Type>::Empty() {
	if (root == nullptr)
		std::cout << "\n\nСписок пуст !!!\n\n";
	return (root == nullptr);
}


template <typename Type>
void List<Type>::DeleteList() {
	if (root == nullptr)
		return;
	else {
		if (root == index) {
			delete root;
			root = nullptr;
			index = nullptr;
		}
		else {
			Element<Type>* tmpElement;
			while (root != nullptr) {
				tmpElement = root;
				root = tmpElement->GetNext();
				delete tmpElement;
			}
			root = nullptr;
			index = nullptr;
		}
	}
	std::cout << "\n\nСписок очищен !!!\n\n";
}

#endif