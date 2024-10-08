#include <stdio.h>
#include "Stack.h"

void prnMenu(){
	cout<<"*******************************************"<<endl;
	cout<<"* 1. 삽입    2. 삭제    3. 출력   4. 종료 *"<<endl;
	cout<<"*******************************************"<<endl;
	cout<<endl;
	cout<<"원하시는 메뉴를 골라주세요: ";
}

int main(){
	    int mode, selectNumber, tmpItem;
		LinkedList<int> *p;
		bool flag = false;

		cout<<"자료구조 선택(1: Stack, Other: Linked List): ";
		cin>>mode;

		// 스택이나 연결 리스트 중 하나를 선택하기 		    
		if(mode == 1)
			p = new Stack<int>();    // 정수를 저장하는 스택
			
		else
			p = new LinkedList<int>(); // 링크드 리스트 


		do{
			prnMenu();
			cin>>selectNumber;
			
			switch(selectNumber){ 
				case 1:
				// 원소 추가 
					cout<<"원하시는 값을 입력해주세요: ";
					cin>>tmpItem;    
					p->Insert(tmpItem);
					cout<<tmpItem<<"가 삽입되었습니다."<<endl;
					break;
					
				case 2:
				// 원소 삭제 
					if(p->Delete(tmpItem)==true)
						cout<<tmpItem<<"가 삭제되었습니다."<<endl;
						
					else cout<<"비어있습니다. 삭제 실패"<<endl;
					break;
					
				case 3:
					cout<<"크기: "<<p->GetSize()<<endl;
					p->Print();
					break;
					
				case 4:
					flag = true;     break;
					
				default:
					cout<<"잘못 입력하셨습니다."<<endl;
					break;
			
			}
			
			if(flag) break;
			
		} while(1);
		
		return 0;
}

