#pragma once
#include <iostream>

template <typename type>
class Element
{
public:
	type value_;
	Element<type>* next_element_;
	Element(type value, Element<type>* next_element=nullptr);
};
template <typename type>
class List
{
private:
	Element<type>* first_element_;
public:
	List<type>();
	List<type>(Element<type>* first_element);
	void add_element(type value);
	void remove_element();
	List<type>& operator=(List<type>& list);

	class Iterator
	{
	public:
		Iterator(Element<type>* pointed_element);
		Element<type>* pointed_element_;
		type operator*();
		Iterator& operator++();
		bool operator !=(Iterator& another);

	};
	Iterator begin();
	Iterator end();
	void iterator_add(Iterator& position, type value);
	void iterator_remove(Iterator& position);
	void print_list();
	~List();
};


template <typename type>
Element<type>::Element(type value, Element<type>* next_element)
{
	value_ = value;
	next_element_ = next_element;
}

template <typename type>
List<type>::List<type>(Element<type>* first_element)
{
	first_element_ = first_element;
}

template <typename type>
List<type>::List<type>()
{
	first_element_ = nullptr;
}

template <typename type>
void List<type>::add_element(type value)
{
	Element<type>* new_element = new Element<type>(value);

	if (first_element_ == nullptr)
	{
		first_element_ = new_element;
	}
	else
	{
		Element<type>* last_element = first_element_;
		while (last_element->next_element_)
		{
			last_element = last_element->next_element_;
		}
		last_element->next_element_ = new_element;
	}
}

template <typename type>
void List<type>::remove_element()
{
	Element<type>* last_element = first_element_;
	while (last_element->next_element_->next_element_)
	{
		last_element = last_element->next_element_;
	}
	delete last_element->next_element_;
	last_element->next_element_ = nullptr;
}

template <typename type>
List<type>::Iterator::Iterator(Element<type>* pointed_element)
{
	pointed_element_ = pointed_element;
}

template <typename type>
List<type>::template Iterator& List<type>::Iterator::operator++()
{
	pointed_element_ = pointed_element_->next_element_;
	return *this;
}

template <typename type>
type List<type>::Iterator::operator*()
{
	return pointed_element_->value_;
}

template <typename type>
bool List<type>::template Iterator::operator!=(List<type>::template Iterator& another)
{
	bool arent_equal;
	arent_equal = (pointed_element_ != another.pointed_element_);
	return arent_equal;
}

template <typename type>
List<type>:: template Iterator List<type>::begin()
{
	return Iterator(first_element_);
}

template <typename type>
List<type>:: template Iterator List<type>::end()
{
	return Iterator(nullptr);
}

template <typename type>
void List<type>::iterator_add(Iterator& position, type value)
{
	if (position.pointed_element_ == nullptr)
	{
		add_element(value);
		Element<type>* element_searched = first_element_;
		while (element_searched->next_element_->next_element_ != nullptr)
		{
			element_searched = element_searched->next_element_;
		}
		position.pointed_element_ = element_searched->next_element_;
	}
	else if (position.pointed_element_ == first_element_)
	{
		Element<type>* new_element = new Element<type>(value, first_element_);
		first_element_ = new_element;
		position = begin();
	}
	else
	{
		Element<type>* element_before = first_element_;
		while (element_before->next_element_ != position.pointed_element_)
		{
			element_before = element_before->next_element_;
		}
		element_before->next_element_ = new Element<type>(value, element_before->next_element_);
		position.pointed_element_ = element_before->next_element_;
	}
}
template <typename type>
void List<type>::iterator_remove(Iterator& position)
{
	if(position.pointed_element_ == nullptr)
	{
	
	}
	else if (position.pointed_element_ == first_element_)
	{
		first_element_ = first_element_->next_element_;
		delete position.pointed_element_;
		position = begin();
	}
	else
	{
		Element<type>* element_before = first_element_;
		while (element_before->next_element_ != position.pointed_element_)
		{
			element_before = element_before->next_element_;
		}
		element_before->next_element_ = position.pointed_element_->next_element_;
		delete position.pointed_element_;
		position.pointed_element_ = element_before->next_element_;
	}
}

/*template <typename type>
void List<type>::print_list()
{
	Element<type>* elem = first_element_;
	while (elem != nullptr)
	{
		std::cout << elem.value_ << std::endl;
		elem = elem->next_element_;
	}
}*/

template <typename type>
List<type>::~List()
{
	Element<type>* to_delete = first_element_;
	Element<type>* next_element = first_element_;
	while (to_delete != nullptr)
	{
		next_element = to_delete->next_element_;
		delete to_delete;
		to_delete = next_element;
	}
	first_element_ = nullptr;
}

template <typename type>
List<type>& List<type>::operator=(List<type>& list)
{
	first_element_ = list.first_element_;
}