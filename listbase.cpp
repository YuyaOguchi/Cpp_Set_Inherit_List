//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 5, Project 12
//  2/03/2016
//  list used for inheritance

#include "listbase.h"
#include <iostream>
using namespace std;

List::List() {
	cursor = NULL;
	N = 0;
}

List::~List(){
	while(N !=0){
		remove_current();
	}
}
List::List(const List& source){
	cursor = NULL;
	N = 0;
	operator=(source);
}

void List::start(){
	if(cursor!= NULL){
		while (cursor ->prev != NULL){
			cursor = cursor -> prev;
		}
	}
}

void List::end(){
	if(cursor!= NULL){
		while (cursor ->next != NULL){
			cursor = cursor -> next;
		}
	}
}

void List::advance(){
	if(cursor!= NULL){
	if (cursor -> next != NULL){
		cursor = cursor -> next;
	}
	}
}

void List::insert(T key, T value){
	if(cursor == NULL){
		Node * temp = new Node(key, value, NULL, NULL);
		cursor = temp;
	}else if (cursor->prev == NULL){
		Node * temp = new Node(key, value, NULL, cursor);
		cursor -> prev = temp;
	}else{
		Node * temp = new Node(key, value, cursor->prev, cursor);
		if(cursor == NULL){
			cursor = temp;
		}else{
			if(cursor ->prev != NULL){
				cursor->prev->next = temp;
			}
			cursor->prev = temp;
		}
	}
	N++;

}

void List::attach(T key, T value){
	cout <<"Value in attach: " << value << endl;
	if(cursor == NULL){
		Node * temp = new Node(key, value, NULL,NULL);
		cursor = temp;
	}else if(cursor->next == NULL){
		Node * temp = new Node(key, value, cursor, NULL);
		cursor->next = temp;
	}else{
		Node * temp = new Node(key, value, cursor, cursor->next);
		cursor->next->prev = temp;
		cursor->next = temp;
	}
	N++;
}
void List::remove_current(){
	Node *temp = cursor;
	if(cursor->next == NULL){
		cursor = cursor ->prev;
		if (cursor !=NULL){
			cursor->next = NULL;
		}
		delete temp;
	}else if (cursor->prev ==NULL){
		cursor = cursor ->next;
		cursor->prev = NULL;
		delete temp;
	}else{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}
	N--;
}
int List::size()const{
	return N;
}

T List::current()const{
	return cursor->data;
}

T List::currentkey()const{
	return cursor->key;
}

List& List::operator=(const List& source){
	//start();
	if(this == &source){
	return *this;
	}
	while(N !=0){
		remove_current();
	}
	Node *temp = source.cursor;
	while(temp ->prev != NULL){
	temp = temp->prev;
	}
	while(temp != NULL){
		attach(temp->key,temp->data);
		advance();
		temp = temp->next;
	}
	start();
	return *this;
}

ostream& operator<<(ostream &out, const List &other){
	List::Node *temp;
	temp = other.cursor;
	if (temp == NULL){
	cout << "keybaglist is Empty" << endl;
	return out;
	}
	while (temp ->prev != NULL){
		temp = temp -> prev;
	}

	cout << "keybaglist: ";
	if(temp != NULL){
		cout << temp->data;
	}
	while(temp->next != NULL){
		temp = temp -> next;
		cout << temp->data;
	}
	cout << endl;
	return out;
}
