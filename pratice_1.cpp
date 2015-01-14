#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ��� ����ü
typedef struct Node
	{
		int Data; // ��
		struct Node * link; // ��ũ, ���� ��带 ����Ű�� ������(�ڱ���������ü)
	} Node;


Node * MakeNode(int Data) //��� ����� / �ʱ�ȭ
{
	Node * newNode = (Node *)malloc(sizeof(Node)); // �޸𸮿� �����Ҵ�
	newNode -> Data = Data; // ��忡 �� �߰�
	newNode -> link = NULL;// �ι�° ����� �ּ� ���� ���� null�� ����.

	return newNode; // ����� �ּҰ� ���� 


}

int searchNode (Node * head) // ��� ����� ��ȯ. 
{
	int count = 0; // ��� ���� 
	if ( head == NULL) // head�� NULL �̴ϱ� ��尡 ���� ����
		return 0;
	else // ��尡 �ϳ� �̻� �ִ� ���� 
	{
		while(head -> link != NULL) // ���� ��尡 tail �� ���� ������ �ݺ���
		{
			count ++;// count �� 1�� ����
			head = head -> link; // �� ���� ���� �̵�
		
		
		}
		return count +1; // tail�� �ݺ����� ��� �� �� �߰��� ä�� �����ؾ� �Ѵ�.
	}

}


void insertFirstNode(Node ** head, Node ** tail, Node * Newnode) // ù ��° ���� �����ϱ�.
{
	if((*head) == NULL) //��� ����Ʈ�� ��尡 ���� ���� �̹Ƿ�
	{
		(*head) = Newnode; // ���ο� ��尡 head�� �� ���ÿ�
		(*tail) = Newnode; // ���ο� ��尡 tail�� �� ����.
		
	}
	else					// ��尡 �� �� �̻� �ִ� ���
	{
		Newnode -> link  = *head; // �� ��尡 ����Ű�� ���� ����� �����Ͱ��� head�� ����Ʈ��.
		(* head) = Newnode;		// �� ��尡 head�� �� ����.
	
	}



}

void insertMiddleNode(Node ** head, Node ** tail, Node * Newnode, int cur) // �߰� ���� �����ϱ�.cur�� ������ ��带 �˷��ִ� ��������.
{
	if((*head) == NULL) // ��尡 �ϳ��� ���� ����
	{
		insertFirstNode(head, tail, Newnode); // ��尡 �����Ƿ� �� �տ� ��带 �߰��Ѵ�.
	
	}
	else //��尡 �� �� �̻� ���� �� ��,
	{
		Node * temp = (*head); //head�� ������ ���� ������ temp ��� ����
		Node * pre = NULL; // ���� ����� �տ� �ִ� ����� ������ ���� ������ pre ��� ����.

		for(int i = cur; i>0; i--) //cur�� ��ġ�� ��带 �̵�
		{
			pre = temp; // cur�� �̵��ϱ� ���� ���� ��带 pre�� ����.
			temp = temp -> link; // temp�� ���� ���� �ű�.

		}
		pre -> link = Newnode; //���� ��尡 ����Ű�� ���� ����� ������ ���� ���ο� ����� �����Ͱ��� ����,
		Newnode -> link = temp; // temp�� ���� ���� �̵�.
	}


}

void deleteNode(Node ** head, Node ** tail, int cur) //��� ���� cur�� ���� �Ϸ��� ��带 �˷��ֱ� ���� ���.
{
	Node * pre = NULL; // pre�� �����ϰ� ���� ����� �� ���.
	Node * temp = * head; // temp�� head�� �����Ͱ�. 

	int size = searchNode(*head); // ����Ʈ�� ������.

	if ( size == 1) //����Ʈ�� ����� �� ���� ���.
	{ 
		free(*head); // head�� ���� �Ҵ��� Ǯ����. ��尡 �ϳ��� ���� ����.
		*head = NULL; // �׸��� head�� ���� NULL�� �ǰ� �Ѵ�.
	}


	else
	{
		if (cur == 0) // �� ���� ��带 ������ ��
		{	
			pre = *head; // head�� ���� pre�� �ְ�,
			*head = (*head) -> link; // head�� ���� ��带 head��.
			free(pre); //pre�� Ǯ���ش�.
			pre = NULL; //pre�� ���� NULL�� �ǰ� �Ѵ�.
	
		}
		else
		{
			for(int i = cur; i>0; i--) //���� �Ϸ��� ���� �̵�.
			{
				pre = temp; // ���� ����� ���� ��带 pre��.
				temp = temp -> link; // ��� �̵�.
			}
		

			pre -> link = temp -> link; // �����ϴ� ����� �� ���� ���� ��带 ����.
			if (temp -> link == NULL) // �����ϴ� ��尡 tail �̶��.
			{
				*tail = pre; // ���� �Ϸ��� ����� ���� ��带 tail�� �����.
			}
			free(temp);

		}
	}
}

void printNode(Node* head) // ��� ��� �Լ�.
{
    int count = 0; // �ε��� ��ġ �˷��ִ� count.
    
    while(head != NULL) // tail���� ��� �̵�.
	{                               
        int temp = head->Data;  // temp�� ���� ��� ����.
        printf("\n%d ��° ���� : %d\n �Դϴ�.", count, temp);  // �ε��� ��ġ�� ��.
        count++; //�ε��� ��ġ ����.                                     
        head = head-> link; // ���� ���� ����.                             
    
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
		printf("��忡 �߰��� ���� �Է��ϼ��� : ");
		scanf("%d", &Data);
		printf("\n��带 �߰��� ��ġ�� �Է��ϼ��� : ");
		scanf("%d", &cur);
		temp = MakeNode(Data);
		insertMiddleNode(&head, &tail, temp, cur);
		printNode(head);
	}

    printf("\n������ ����� index�� �Է��ϼ��� : ");
    scanf("%d", &cur);
    deleteNode(&head, &tail, cur);
	printNode(head);
              


	return 0;
}