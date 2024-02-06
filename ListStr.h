#pragma once
#include "List.h"
#include "Element.h"

template <>
class List<char*> {
private:
	Element<char*>* root;	// первый элемент (корень списка)
	Element<char*>* index;	// текущий элемент.
public:
	List();
	List(Element<char*>* root, Element<char*>* index);
	List(const List<char*>& other);
	~List();
	Element<char*>* GetRoot();
	void SetRoot(Element<char*>* root);
	Element<char*>* GetIndex();
	void SetIndex(Element<char*>* index);
	void Insert(char* data, List<char*>* TheList);
	void funcNumbering(int cnt);
	void Retrieve(Element<char*>* element);
	bool Empty();
	void DeleteList();


	friend void operator>> (char* S, List<char*>& TheList);								// добавление элементов 
	friend std::ostream& operator<< (std::ostream& out, List<char*>& TheList);			// вывод списка на экран
	friend List<char*>& operator+ <char*>(List<char*>& list1, List<char*>& list2);		// объединение двух списков
	Element<char*>* operator[](int mainIndex) {											// доступ к элементу
		bool trueIndex = false;
		Element<char*>* currentIndex = GetRoot();
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

	List<char*>& operator= (const List<char*>& other) {
		if (this->root != nullptr)
			delete this->root;

		this->index = nullptr;
		this->root = nullptr;

		if (other.root == nullptr)
			return *this;

		Element<char*>* first_element = new Element<char*>(other.root->GetData());
		this->root = first_element;
		this->index = first_element;
		Element<char*>* new_index_tmp = first_element;

		Element<char*>* tmp_index = other.root->GetNext();
		while (tmp_index != nullptr) {
			Element<char*>* element = new Element<char*>(tmp_index->GetData());
			this->index = element;
			element->SetPrev(new_index_tmp);
			new_index_tmp->SetNext(element);
			new_index_tmp = new_index_tmp->GetNext();
			tmp_index = tmp_index->GetNext();
		}

		return *this;
	}

};


void operator>> (char* S, List<char*>& TheList) {
	TheList.Insert(S, &TheList);
}

std::ostream& operator<< (std::ostream& out, List<char*>& TheList) {
	Element<char*>* currentIndex = TheList.GetRoot();
	out << "\n\nСписок\n\n";
	while (currentIndex != nullptr) {
		out << currentIndex->GetData() << " ";
		currentIndex = currentIndex->GetNext();
	}
	out << "\n\n";
	return out;
}



List<char*>& operator+ (List<char*>& list1, List<char*>& list2) {
	if (list1.GetRoot() == nullptr)
		return list2;
	(list1.GetIndex())->SetNext(list2.GetRoot());
	((list1.GetIndex())->GetNext())->SetPrev(list1.GetIndex());
	list1.SetIndex(list2.GetIndex());
	list2.SetIndex(nullptr);
	list2.SetRoot(nullptr);
	return list1;
}






List<char*>::List() {
	this->root = nullptr;
	this->index = nullptr;
}

List<char*>::List(Element<char*>* root, Element<char*>* index) {
	this->root = root;
	this->index = index;
}

List<char*>::List(const List<char*>& other) {
	this->index = nullptr;
	this->root = nullptr;

	if (other.root == nullptr)
		return;

	Element<char*>* first_element = new Element<char*>(other.root->GetData());
	this->root = first_element;
	this->index = first_element;
	Element<char*>* new_index_tmp = first_element;

	Element<char*>* tmp_index = other.root->GetNext();
	while (tmp_index != nullptr) {
		Element<char*>* element = new Element<char*>(tmp_index->GetData());
		this->index = element;
		element->SetPrev(new_index_tmp);
		new_index_tmp->SetNext(element);
		new_index_tmp = new_index_tmp->GetNext();
		tmp_index = tmp_index->GetNext();
	}
}


List<char*>::~List() {
	if (root == nullptr)
		return;
	else {
		if (root == index) {
			delete root;
			root = nullptr;
			index = nullptr;
		}
		else {
			Element<char*>* tmpElement;
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

Element<char*>* List<char*>::GetRoot() {
	return this->root;
}

void List<char*>::SetRoot(Element<char*>* root) {
	this->root = root;
}

Element<char*>* List<char*>::GetIndex() {
	return this->index;
}

void List<char*>::SetIndex(Element<char*>* index) {
	this->index = index;
}


void List<char*>::Insert(char* data, List<char*>* TheList) {
	Element<char*>* element = new Element<char*>(data);
	element->SetPrev(TheList->index);
	if (root == nullptr)
		root = element;
	if (index != nullptr) {
		index->SetNext(element);
	}
	index = element;
}

void List<char*>::funcNumbering(int cnt) {
	Element<char*>* currentIndex = GetRoot();
	while (currentIndex != nullptr) {
		currentIndex->SetNumber(cnt);
		currentIndex = currentIndex->GetNext();
		cnt++;
	}
}

void List<char*>::Retrieve(Element<char*>* element) {
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

bool List<char*>::Empty() {
	if (root == nullptr)
		std::cout << "\n\nСписок пуст !!!\n\n";
	return (root == nullptr);
}




void List<char*>::DeleteList() {
	if (root == nullptr)
		return;
	else {
		if (root == index) {
			delete root;
			root = nullptr;
			index = nullptr;
		}
		else {
			Element<char*>* tmpElement;
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