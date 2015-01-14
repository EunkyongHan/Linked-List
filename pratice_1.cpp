#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 노드 구조체
typedef struct Node
	{
		int Data; // 값
		struct Node * link; // 링크, 다음 노드를 가리키는 포인터(자기참조구조체)
	} Node;


Node * MakeNode(int Data) //노드 만들기 / 초기화
{
	Node * newNode = (Node *)malloc(sizeof(Node)); // 메모리에 동적할당
	newNode -> Data = Data; // 노드에 값 추가
	newNode -> link = NULL;// 두번째 노드의 주소 값은 아직 null인 상태.

	return newNode; // 노드의 주소값 리턴 


}

int searchNode (Node * head) // 노드 사이즈를 반환. 
{
	int count = 0; // 노드 갯수 
	if ( head == NULL) // head가 NULL 이니까 노드가 없는 상태
		return 0;
	else // 노드가 하나 이상 있는 상태 
	{
		while(head -> link != NULL) // 다음 노드가 tail 이 나올 때까지 반복문
		{
			count ++;// count 를 1씩 증가
			head = head -> link; // 그 다음 노드로 이동
		
		
		}
		return count +1; // tail은 반복문에 없어서 한 개 추가한 채로 리턴해야 한다.
	}

}


void insertFirstNode(Node ** head, Node ** tail, Node * Newnode) // 첫 번째 노드로 삽입하기.
{
	if((*head) == NULL) //노드 리스트에 노드가 없는 상태 이므로
	{
		(*head) = Newnode; // 새로운 노드가 head가 된 동시에
		(*tail) = Newnode; // 새로운 노드가 tail이 된 상태.
		
	}
	else					// 노드가 한 개 이상 있는 경우
	{
		Newnode -> link  = *head; // 새 노드가 가리키는 다음 노드의 포인터값은 head의 포인트값.
		(* head) = Newnode;		// 새 노드가 head가 된 상태.
	
	}



}

void insertMiddleNode(Node ** head, Node ** tail, Node * Newnode, int cur) // 중간 노드로 삽입하기.cur은 선행자 노드를 알려주는 참조변수.
{
	if((*head) == NULL) // 노드가 하나도 없는 상태
	{
		insertFirstNode(head, tail, Newnode); // 노드가 없으므로 맨 앞에 노드를 추가한다.
	
	}
	else //노드가 한 개 이상 존재 할 때,
	{
		Node * temp = (*head); //head의 포인터 값을 가지는 temp 노드 생성
		Node * pre = NULL; // 현재 노드의 앞에 있는 노드의 포인터 값을 가지는 pre 노드 생성.

		for(int i = cur; i>0; i--) //cur의 위치로 노드를 이동
		{
			pre = temp; // cur가 이동하기 전에 현재 노드를 pre에 넣음.
			temp = temp -> link; // temp를 다음 노드로 옮김.

		}
		pre -> link = Newnode; //앞의 노드가 가리키는 다음 노드의 포인터 값을 새로운 노드의 포인터값에 넣음,
		Newnode -> link = temp; // temp를 다음 노드로 이동.
	}


}

void deleteNode(Node ** head, Node ** tail, int cur) //노드 삭제 cur은 삭제 하려는 노드를 알려주기 위해 사용.
{
	Node * pre = NULL; // pre는 삭제하고 싶은 노드의 앞 노드.
	Node * temp = * head; // temp는 head의 포인터값. 

	int size = searchNode(*head); // 리스트의 사이즈.

	if ( size == 1) //리스트의 사이즈가 한 개일 경우.
	{ 
		free(*head); // head의 동적 할당을 풀어줌. 노드가 하나도 없는 상태.
		*head = NULL; // 그리고 head의 값은 NULL로 되게 한다.
	}


	else
	{
		if (cur == 0) // 맨 앞의 노드를 삭제할 때
		{	
			pre = *head; // head의 값을 pre에 넣고,
			*head = (*head) -> link; // head의 다음 노드를 head로.
			free(pre); //pre를 풀어준다.
			pre = NULL; //pre의 값을 NULL로 되게 한다.
	
		}
		else
		{
			for(int i = cur; i>0; i--) //삭제 하려는 노드로 이동.
			{
				pre = temp; // 삭제 노드의 앞의 노드를 pre에.
				temp = temp -> link; // 노드 이동.
			}
		

			pre -> link = temp -> link; // 삭제하는 노드의 앞 노드와 뒤의 노드를 연결.
			if (temp -> link == NULL) // 삭제하는 노드가 tail 이라면.
			{
				*tail = pre; // 삭제 하려는 노드의 앞의 노드를 tail로 만든다.
			}
			free(temp);

		}
	}
}

void printNode(Node* head) // 노드 출력 함수.
{
    int count = 0; // 인덱스 위치 알려주는 count.
    
    while(head != NULL) // tail까지 노드 이동.
	{                               
        int temp = head->Data;  // temp에 현재 노드 넣음.
        printf("\n%d 번째 값은 : %d\n 입니다.", count, temp);  // 인덱스 위치와 값.
        count++; //인덱스 위치 증가.                                     
        head = head-> link; // 다음 노드로 가기.                             
    
    }
}


int main ()
{	
	Node* head = NULL;
    Node* tail = NULL;
    Node* temp;

    int index;
    int Data;
    int cur;
    
	
	for(int i=0; i<5; i++)
	{
		printf("노드에 추가할 값을 입력하세요 : ");
		scanf("%d", &Data);
		printf("\n노드를 추가할 위치를 입력하세요 : ");
		scanf("%d", &cur);
		temp = MakeNode(Data);
		insertMiddleNode(&head, &tail, temp, cur);
		printNode(head);
	}

    printf("\n삭제할 노드의 index를 입력하세요 : ");
    scanf("%d", &cur);
    deleteNode(&head, &tail, cur);
	printNode(head);
              


	return 0;
}