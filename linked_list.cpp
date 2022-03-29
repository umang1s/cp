#include"default.h"

class LinkedList{
    struct Node{
        int val;
        Node* next;
        Node(int d){
            val=d;
            next=NULL;
        }
    };
    Node* root;
    int total;
public:
    LinkedList(){
        total=0;
        root=NULL;
    }

    void insert(int val){
        Node *temp=root;
        total++;
        if(temp==NULL){root=new Node(val); return;}
        while(temp->next)temp=temp->next;
        temp->next=new Node(val);
    }

    void erase(int val){
        Node *cur=root,*prev=NULL,*next=NULL;
        while(cur){
            if(cur->val==val){
                if(prev==NULL) root=root->next;
                else prev->next=cur->next;
                total--;
                return ;
            }
            prev=cur;
            cur=cur->next;
        }
    }

    void print(){
        Node *temp=root;
        while(temp){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<nl;
    }

    int size(){
        return total;
    }

    void reverse(){
        Node *cur=root,*prev=NULL,*next;
        while(cur){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        root=prev;
    }

    Node* getReverseNode(){
        Node *cur=root,*prev=NULL,*next;
        while(cur){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }

};




void solve(){
    int n;
    cin>>n;
    LinkedList lst=LinkedList();
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        lst.insert(a);
    }
    lst.print();
    lst.reverse();
    lst.print();
    lst.reverse();
    lst.print();
    lst.erase(6);
    lst.print();
}


