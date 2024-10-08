#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;


// 가독성을 위해, 선언과 정의를 분리해서 작성함!

// 템플릿 LinkedList Node 클래스 선언
template <typename T>
class Node {
public:
    T data;  // 데이터를 저장할 변수
    Node *link;  // 다음 노드를 가리킬 포인터
    Node(T element);  // 생성자 선언
};

// 템플릿 LinkedList 클래스 선언
template <typename T>
class LinkedList {
protected:
    Node<T>* first;  // 첫 번째 노드를 가리키는 포인터
    int current_size;  // 리스트 크기
public:
    LinkedList();  // 생성자 선언
    int GetSize();  // 노드 개수를 반환
    void Insert(T element);  // 맨 앞에 원소를 삽입
    virtual bool Delete(T &element);  // 맨 뒤의 원소 삭제
    void Print();  // 리스트 출력
};

// Node 클래스 생성자 정의
template <typename T>
Node<T>::Node(T element) {
    data = element;
    link = NULL;  // NULL 사용
}

// LinkedList 클래스 생성자 정의
template <typename T>
LinkedList<T>::LinkedList() {
    first = NULL;  // 리스트 초기화
    current_size = 0;
}

// GetSize 함수 정의
template <typename T>
int LinkedList<T>::GetSize() {
    return current_size;
}

// Insert 함수 정의
template <typename T>
void LinkedList<T>::Insert(T element) {
    Node<T>* newnode = new Node<T>(element);
    newnode->link = first;
    first = newnode;
    current_size++;
}

// Delete 함수 정의
template <typename T>
bool LinkedList<T>::Delete(T &element) {
    if (first == NULL)
        return false;

    Node<T>* current = first;
    Node<T>* previous = NULL;

    // 마지막 노드를 찾는 반복문
    while (current->link != NULL) {
        previous = current;
        current = current->link;
    }

    if (previous)
        previous->link = NULL;
    else
        first = NULL;

    element = current->data;
    delete current;
    current_size--;
    return true;
}

// Print 함수 정의
template <typename T>
void LinkedList<T>::Print() {
    Node<T>* i = first;
    int index = 1;

    if (current_size != 0) {
        for (i = first; i != NULL; i = i->link) {  
            if (index == current_size) {
                cout << "[" << index << "|";
                cout << i->data << "]";
            } else {
                cout << "[" << index << "|";
                cout << i->data << "]->";
                index++;
            }
        }
        cout << endl;
    }
}

#endif
