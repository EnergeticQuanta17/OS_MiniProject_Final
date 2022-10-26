#include<bits/stdc++.h>
using namespace std;
#include<vector>

int no_of_digits(int n)
{
    int count=0;
    while(n>0)
    {
        count++;
        n/=10;
    }
    return count;
}
void print_top_part(int n)
{
    if(n==1)
    {
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


class NRU
{
    public:
        vector<int> nn;
        vector<int> nm;
        vector<int> rn;
        vector<int> rm;
        
        vector<int> f;
        int cap,max_cap;
        int page_hits,page_faults;
        NRU(int capacity)
        {
            cap=capacity;
            max_cap=capacity;
            page_hits=0;
            page_faults=0;
        }
        void insert(int page_no)
        {
            nn.push_back(page_no);
            f.push_back(page_no);
            cap--;
        }
        void Delete()
        {
            cap++;
            if(nn.size()!=0)
            {
                cout<<"Removing from (Not Referenced, Not Modified):- Page number:";
                int x=nn.back();
                cout<<x<<endl;
                nn.pop_back();
                return;
            }
            if(nm.size()!=0)
            {
                cout<<"Removing from (Not Referenced, Modified):- Page number:";
                int x=nm.back();
                nm.pop_back();
                return;
            }
            if(rn.size()!=0)
            {
                cout<<"Removing from (Referenced, Not Modified):- Page number:";
                int x=rn.back();
                rn.pop_back();
                return;
            }
            if(rm.size()!=0)
            {
                cout<<"Removing from (Referenced, Modified):- Page number:";
                int x=rm.back();
                rm.pop_back();
                return;
            }
        }
        void put(int page_no)
        {
            for(int i=0;i<f.size();i++)
            {
                if(f[i]==page_no)
                {
                    page_hits++;
                    return;
                }
            }
            
            if(cap==0)
            {
                Delete();
                page_faults++;
            }
            insert(page_no);
        }
        void remove(int page_no)
        {
            vector<int>::iterator itr4321;
            for(auto itr4321=nn.begin();itr4321!=nn.end();itr4321++){
                if(*itr4321==page_no)
                {
                    nn.erase(itr4321);
                    return;
                }
            }

            vector<int>::iterator itr432;
            for(auto itr432=nm.begin();itr432!=nm.end();itr432++){
                if(*itr432==page_no)
                {
                    nm.erase(itr432);
                    return;
                }
            }

            vector<int>::iterator itr43;
            for(auto itr43=rn.begin();itr43!=rn.end();itr43++){
                if(*itr43==page_no)
                {
                    rn.erase(itr43);
                    return;
                }
            }

            vector<int>::iterator itr4;
            for(auto itr4=rm.begin();itr4!=rm.end();itr4++){
                if(*itr4==page_no)
                {
                    rm.erase(itr4);
                    return;
                }
            }
        }
        void request_modify_reference(int page_no, int mod, int ref)
        {
            remove(page_no);
            if(mod==0 && ref==0)
                nn.push_back(page_no);
            else if(mod==1 && ref==0)
                nm.push_back(page_no);
            else if(mod==0 && ref==1)
                rn.push_back(page_no);
            else if(mod==1 && ref==1)
                rm.push_back(page_no);
        }

        void display()
        {
            cout<<endl;
            vector<int> v;
            for(int i=0;i<nn.size();i++)
                v.push_back(nn[i]);
            for(int i=0;i<nm.size();i++)
                v.push_back(nm[i]);
            for(int i=0;i<rn.size();i++)
                v.push_back(rn[i]);
            for(int i=0;i<rm.size();i++)
                v.push_back(rm[i]);
            for(int i=0;i<23;i++)
                cout<<"\xcd";
            cout<<endl;
            print_using_horizontal_boxes(v);
            cout<<endl;
            for(int i=0;i<70;i++)
                cout<<"\xdf\xdf";
            cout<<endl;
        }
};

int main()
{
    int capacity, n;
    cout<<"Enter the maximum number of frames possible: ";
    cin>>capacity;
    NRU obj(capacity);

    cout<<"Enter the number of pages involved: ";
    cin>>n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    int pn,mod,ref;
    for(int i=0;i<n;i++)
    {
        obj.put(v[i]);
        char c='Y';
        cout<<"Pages in main memory after "<<(i+1)<<" pages have been processed: ";
        obj.display();
        cout<<"Do you want to change references to a page in main memory?(Y/N): ";
        cin>>c;
        while(c=='Y' && i!=n-1){
            cout<<"Modify references to page existing in main memory:(page_no,mod?,ref?):";
            cin>>pn>>mod>>ref;
            obj.request_modify_reference(pn,mod,ref);
            cout<<"Do you want to register another change?(Y/N): ";
            cin>>c;
        };
    }
    cout<<"Number of page-hits in Not Recently Used --> "<<obj.page_hits<<endl;
    cout<<"Number of page-faults in Not Recently Used --> "<<n-obj.page_hits<<endl;
    system("pause");
}
    