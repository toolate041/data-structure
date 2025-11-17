/*#include <iostream>
using namespace std;

struct Node {
    int e;
    Node* next;
};


void createList(Node *head)
{
	Node *p=head;
	int n,e;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>e;
		Node *s=new Node{e,NULL};
		s->next=p->next;
		p->next=s;
		p=s;
		head->e++; 
	}
 } 

Node* LL_merge(Node* La, Node* Lb) {
    Node* Lc = new Node{0, nullptr};  // 新链表头结点
    Node* p = La->next;
    Node* q = Lb->next;
    Node* r = Lc;

    while (p && q) {
        if (p->e < q->e) {
            r->next = p;
            p = p->next;
        } else {
            r->next = q;
            q = q->next;
        }
        r = r->next;
    }
    // 连接剩余部分
    r->next = p ? p : q;
    Lc->e = La->e + Lb->e;  // 总结点数
    return Lc;
}

// 打印链表
void printList(Node* head) {
    Node* p = head->next;
    while (p) {
        cout << p->e << (p->next ? " " : "");
        p = p->next;
    }
    cout << endl;
}

int main() {
    Node* La = new Node{0, nullptr};
    Node* Lb = new Node{0, nullptr};
    createList(La);
    createList(Lb);

    Node* Lc = LL_merge(La, Lb);
    printList(Lc);

    return 0;
}
*/
/*#include<iostream>
#include<cmath> 
using namespace std; 
struct Node
{
	int e;
	Node *next;
}*head,*p ;
void createList(Node *head)
{
	Node *p=head;
	int n,e;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>e;
		Node *s=new Node{e,NULL};
		s->next=p->next;
		p->next=s;
		p=s;
		head->e ++;
		}	
} 
void printList(Node *head)
{
	Node *p=head->next;
	while(p)
	{
		cout<<p->e<<" ";
		p=p->next;
	}
	cout<<endl;
}
int addnum(Node *head,int i,int e)
{
	int j;
	if(i<1||i>head->e+1)
	{
		cout<<"error"<<endl;
		return 0;
	}
	else
	{
	Node *p=head;
	for(j=1;j<i;j++)//循环从1开始 
	p=p->next;
	Node *s=new Node{e,NULL};
	s->next=p->next;
	p->next=s;
	head->e++; 
	return 1;	
	 } 
	
}
int deletenum(Node *head,int i)
{
	int j;
	if(i<1||i>head->e)//不能是e+1 
	{
		cout<<"error"<<endl;
		return 0;
	}
	
	else
	{
	Node *p=head;
	for(j=1;j<i;j++)
	p=p->next;
	p->next=p->next->next;
	head->e --;
	return 1;
	}
	
}
void findnum(Node *head,int i)
{
	int j;
	if(i<1||i>head->e)
	{
		cout<<"error"<<endl;
	
	}
	else
	{
		Node*p=head;
		while(i--)
		{
			p=p->next;
		}
		cout<<p->e<<endl; 
	}
	
 } 
int main()
{
	int m,n,j;
	Node *head=new Node{0,NULL};
	createList(head);
	printList(head);
	int position,num;
	cin>>position>>num;
	m=addnum(head,position,num);
	if(m)
	{
	printList(head);	
	}
	
	cin>>position>>num;
	m=addnum(head,position,num);
	if(m)
	{
	printList(head);	
	}
	cin>>position;
	n=deletenum(head,position);
	if(n)
	{
	printList(head);	
	}
	cin>>position;
	n=deletenum(head,position);
	if(n)
	{
	printList(head);	
	}
	cin>>position;
	findnum(head,position);
	cin>>position;
	findnum(head,position);
	
 }
 */
/*#include<iostream>
using namespace std;
void print(int store[100],int t)
{
	for(int i=0;i<t;i++)
	{
		cout<<store[i]<<" ";
	}
	cout<<endl;
}
void rightmove(int store[100],int num,int t)
{
	int i,j; 
	while(num--)
	{
		int k=store[t-1];
		for(i=t-1;i>=1;i--)
		{
			store[i]=store[i-1];
		}
		store[0]=k;
	}
	print(store,t);
}
void leftmove(int store[100],int num,int t)
{
	int i,j;
	while(num--)
	{
		int k=store[0];
		for(i=0;i<t-1;i++)
		{
			store[i]=store[i+1];
		}
		store[t-1]=k;
	}
	print(store,t);
}

int main()
{
	int i,j,t,order,num;
	cin>>t;
	int store[t];
	for(i=0;i<t;i++)
	{
		cin>>store[i];
	}
	print(store,t);
	cin>>order>>num;
	if(order==1)
	{
		rightmove(store,num,t);
	}
	else
	{
		leftmove(store,num,t);
	}
	cin>>order>>num;
	if(order==1)
	{
		rightmove(store,num,t);
	}
	else
	{
		leftmove(store,num,t);
	}
}*/
/*#include<iostream>
#include<cmath> 
using namespace std; 
struct Node
{
	int e;
	Node *next;
}*Head,*p;
void printList(Node *Head,int t)
{
	Node *p=Head->next;
	while(p)
	{
		cout<<p->e<<" ";
		p=p->next;
	}
	cout<<endl;
}
void createList(Node *Head,int t)
{
	int i,e;
	Node *p=Head;
	for(i=0;i<t;i++)
	{
		cin>>e;
		Node *s=new Node{e,NULL};
		s->next=p->next;
		p->next=s;
		p=s;
		Head->e++;
	 } 
	 printList(Head,t);
}
int swapNode(Node *head,int a,int b,int t)
{
	if(a<0||b<0||a>t||b>t)
	{
		cout<<"error"<<endl;
		return 0;
	}
	else
	{
		 Node* p = head;
    for (int i = 1; i <= a; ++i) p = p->next;
    int valA = p->e;

    p = head;
    for (int i = 1; i <= b; ++i) p = p->next;
    int valB = p->e;

    p = head;
    for (int i = 1; i <= a; ++i) p = p->next;
    p->e = valB;

    p = head;
    for (int i = 1; i <= b; ++i) p = p->next;
    p->e = valA;
		return 1;
	}
}

int main()
{
	Node *Head=new Node{0,NULL};
	int i,j,t,k,a,b;
	cin>>t;
	createList(Head,t);
	cin>>a>>b;
	k=swapNode(Head,a,b,t);
	if(k)
	{
		printList(Head,t);
	}
	cin>>a>>b;
	k=swapNode(Head,a,b,t);
	if(k)
	{
		printList(Head,t);
	}
}*///交换的逻辑是通过两次循环，得到要交换位置的值
// 备份后在通过两次循环修改两个位置的值。 
#include<iostream>
#include<cmath> 
using namespace std; 
