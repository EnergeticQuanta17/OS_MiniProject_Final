#include<bits/stdc++.h>
using namespace std;

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


class LFU{
    public:
       map<int,int> m;
       map<int,int> frequency_map;
        int cap,max_cap;
        int page_hits,page_faults;
        LFU(int capacity)
        {
            max_cap=capacity;
            cap=capacity;
            page_hits=0;
            page_faults=0;
        }

        void insert(int page_no)
        {
            frequency_map[page_no]++;
            m[page_no]++;
            cap--;
        }

        void Delete(int page_no)
        {
            m[page_no]--;
            cap++;
        }

        void put(int value)
        {
            if(m[value]!=0)
            {
                frequency_map[value]++;
                page_hits++;
                return;
            }
            if(cap==0)
            {
                page_faults++;
                int minimum=INT_MAX;
                int index=0;
                for(auto i: frequency_map)
                {
                    if(minimum>i.second && m[i.first]!=0)
                    {
                        minimum=i.second;
                        index=i.first;
                    }
                }
                Delete(index);
            }
            insert(value);
        }

        void print_pages()
        {
            vector<int> v;
            for(auto i: m)
            {
                if(i.second>0)
                    v.push_back(i.first);
            }
            for(int i=0;i<23;i++)
                cout<<"\xcd";
            cout<<endl;
            print_using_horizontal_boxes(v);
            cout<<endl;
            for(int i=0;i<max_cap*7;i++)
                cout<<"\xdf\xdf";
        }
};
void print_page_input(vector<int>& v)
{
    for(int i=0;i<70;i++)
            cout<<"\xb0\xb0";
    cout<<endl;

    cout<<"Page Input Order\n";
    print_using_horizontal_boxes(v);
    cout<<endl;
    for(int i=0;i<70;i++)
            cout<<"\xb0\xb0";
    cout<<endl;
}

int main()
{
    int capacity, n;
    cout<<"Enter the maximum number of frames possible: ";
    cin>>capacity;
    LFU obj(capacity);

    cout<<"Enter the number of pages involved: ";
    cin>>n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    print_page_input(v);

    for(int i=0;i<n;i++)
    {
        obj.put(v[i]);
        cout<<"After "<<(i+1)<<" pages invoked: \n";
        obj.print_pages();
        cout<<endl<<endl;
    }
    getchar();
    cout<<"Number of page-hits in Least Frequently Used --> "<<obj.page_hits<<endl;
    cout<<"Number of page-faults in Least Frequently Used --> "<<n-obj.page_hits<<endl;
    system("pause");
}
