#ifndef STACK_H
#define STACK_H
// 중복 포함 방지를 위해 헤더가드 추가함

#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

// 템플릿 stack 클래스 
// LinkedList class를 상속받음
template <typename T>
class Stack : public LinkedList<T> {	
	public:
			// LinkedList와 달리 Stack은 current가 가리키는 가장 앞의 원소를 삭제해야함 
		bool Delete(T &element) override {
        if (this->first == NULL)
            return false;

        Node<T>* current = this->first;
        element = current->data;
        this->first = current->link;
        delete current;
        this->current_size--;
        return true;
    }
};

#endif

