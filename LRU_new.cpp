#include<bits/stdc++.h>
using namespace std;

int no_of_digits(int n){
    if(n==0)
        return 1;
    int count=0;
    while(n>0){
        count++;
        n/=10;
    }
    return count;
}

void print_top_part(int n){
    if(n==1){
        cout<<"\xda\xc4\xc4\xc4\xc4\xc4\xbf\n";
        return;
    }
    cout<<"\xda\xc4\xc4\xc4\xc4\xc4\xc2";
    for(int i=0;i<n-2;i++)
        cout<<"\xc4\xc4\xc4\xc4\xc4\xc2";
    cout<<"\xc4\xc4\xc4\xc4\xc4\xbf\n";
}

void print_middle_part(vector<int>& v)
{
    cout<<"\xb3";
    if(v.size()==1)
    {
        int digits=no_of_digits(v[0]);
        if(digits==1)
            cout<<"  "<<v[0]<<"  \xb3\n";
        else if(digits==2)
            cout<<" "<<v[0]<<"  \xb3\n";
        else
            cout<<" "<<v[0]<<" \xb3\n";
        return;
    }
    
    
    for(int i=0;i<v.size();i++)
    {
        int digits=no_of_digits(v[i]);
        if(digits==1)
            cout<<"  "<<v[i]<<"  \xb3";
        else if(digits==2)
            cout<<" "<<v[i]<<"  \xb3";
        else
            cout<<" "<<v[i]<<" \xb3";
    }
    cout<<"\n";
}

void print_last_part(int n)
{
    if(n==1)
    {
        cout<<"\xc0\xc4\xc4\xc4\xc4\xc4\xd9"; 
        return;
    }
    cout<<"\xc0\xc4\xc4\xc4\xc4\xc4"; 
    for(int i=0;i<n-2;i++)
        cout<<"\xc1\xc4\xc4\xc4\xc4\xc4"; 
    cout<<"\xc1\xc4\xc4\xc4\xc4\xc4\xd9"; 
}

void print_using_horizontal_boxes(vector<int>& v)
{
    print_top_part(v.size());
    print_middle_part(v);
    print_last_part(v.size());
}

void print_pages(vector<int>& f, int max_cap){
    if(!f.size()) return;
    for(int i=0;i<max_cap*7;i++)
        cout<<"\xcd";
    cout<<endl;
    print_using_horizontal_boxes(f);
    
}

class node{
    public: 
        int val;
        node *next,*prev;
        node(int v){
            val=v;
        }
};

class LRUCache {
public:
    
    node *head=new node(-1);
    node *tail=new node(-1);
    int cap;
    map<int,node*> m;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        head->prev=tail->next=NULL;
    }
    
    void insert(int val){
        node *temp=new node(val);
        temp->next=head->next;
        temp->prev=head;
        head->next=temp;
        temp->next->prev=temp;
        cap--;
        m[val]=temp;
    }
    
    void Delete(node *t){
        t->prev->next=t->next;
        t->next->prev=t->prev;
        cap++;
        m.erase(t->val);
    }
    
    void put(int value) {
        if(m.find(value) != m.end()) Delete(m[value]);
        else if(!cap){
            cout<<"Page fault occurred... \n";
            Delete(tail->prev);
        }
        insert(value);
    }
};

int main(){
    int capacity, n;
    cout<<"Enter the maximum number of frames possible: ";
    cin>>capacity;
    LRUCache lru(capacity);
    cout<<"Enter the number of pages invoked: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the sequence of pages invoked: ";
    for(int i=0; i<n; i++) cin>>v[i];
    cout<<"The sequence of pages stored in the frames of physical memory after each page is invoked is :\n";
    for(int i=0; i<n; i++){
        cout<<"After "<<(i+1)<<" pages invoked: \n";
        lru.put(v[i]);
        vector<int> t;
        node* temp = lru.head->next;
        while(temp->val != -1){
            t.push_back(temp->val);
            temp = temp->next;
        }
        print_pages(t, capacity);
        cout<<"\n";

        for(int i=0;i<70;i++)
            cout<<"\xdf\xdf";
        cout<<endl;
    }
    return 0;
}
