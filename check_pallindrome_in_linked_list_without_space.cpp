#include"default.h"

struct LinkedList{
    int val;
    LinkedList *next;
    public:
    LinkedList(int d){
        val=d;
        next=NULL;
    }
};

void printLinkedList(LinkedList* l){
    if(l){
        cout<<l->val<<" ";
        printLinkedList(l->next);
    }else cout<<nl;
}


LinkedList* rotateThis(LinkedList* root){
    LinkedList *prev=NULL,*next,*cur=root;
    while(cur){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}

bool matchThis(LinkedList*start, LinkedList*last){
    if(start==NULL && last==NULL) return true;
    if(start==NULL || last==NULL) return false;
    cout<<start->val<<" "<<last->val<<nl;
    if(start->val==last->val) return matchThis(start->next,last->next);
    return false;
}

bool checkThis(LinkedList* root){
    LinkedList* mid=root,*cur=root,*prev;
    if(root==NULL || root->next==NULL) return true;
    int cnt=1;
    while(cur){
        cur=cur->next;
        cnt++;
        if(cnt%2) {prev=mid; mid=mid->next;}
    }
    if(cnt%2==0) mid=mid->next;
    prev->next=NULL;
    LinkedList* rev=rotateThis(mid);
    printLinkedList(root);
    printLinkedList(rev);
    return matchThis(root,rev);

}



void solve(){
    int n;
    cin>>n;
    LinkedList * root=NULL,*temp;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        if(root==NULL) root=new LinkedList(a),temp=root;
        else{
            temp->next=new LinkedList(a);
            temp=temp->next;
        }
    }

    temp=root;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<nl;

    bool ans=checkThis(root);
    cout<<(ans?"YES":"NO")<<nl;

}