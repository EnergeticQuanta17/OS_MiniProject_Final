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
class LFD{
    public:
        vector<int> f;
        int cap,max_cap; 
        int page_hits,page_faults;
        vector<vector<int>> v;
        LFD(int capacity)
        {
            max_cap=capacity;
            cap=capacity;
            page_hits=0;
            page_faults=0;
        }
        void insert(int page_no)
        {
            f.push_back(page_no);
            cap--;
        }
        void add_to_v(int val, int pos)
        {
            int flag=0;
            for(int i=0;i<v.size();i++)
            {
                if(v[i].size()==0)
                    continue;
                if(v[i][0]==val)
                {
                    v[i].push_back(pos);
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                vector<int> temp;
                temp.push_back(val);
                temp.push_back(pos);
                v.push_back(temp);
            }
        }
        void Delete(int curr_index)
        {
            int maximum=INT_MIN;
            int element=0,page_no=0;
            int index_i=0,index_j=0;
            for(int i=0;i<f.size();i++)
            {
                int local_mini=0,flag=0,index=0;
                for(int j=0;j<v.size();j++)
                {
                    if(v[j].size()==0)
                        continue;
                    if(f[i]==v[j][0])
                    {
                        int k=1;
                        while(k<v[j].size() && v[j][k]<curr_index)
                            k++;
                        if(k<v[j].size())
                        {
                            flag=1;
                            local_mini=v[j][k];
                            element=f[i];
                        }
                        break;
                    }
                }
                if(flag==0)
                {
                    page_no=f[i];
                    break;
                }
                if(maximum<local_mini)
                {
                    maximum=local_mini;
                    page_no=element;
                }
            }
            vector<int>::iterator iter=v[0].begin();
            for(auto iter=f.begin();iter!=f.end();iter++)
            {
                if(*iter==page_no)
                {
                    f.erase(iter);
                    break;
                }

            }
            cap++;
        }
        void put(int page_no, int position)
        {
            int present=-1;
            for(int i=0;i<f.size();i++)
            {
                if(f[i]==page_no)
                {
                    present=i;
                    page_hits++;
                    break;
                }
            }
            if(present!=-1)
                return;
            if(cap==0)
            {
                Delete(position);
                page_faults++;
            }
            
            insert(page_no);
        }
        void print_pages()
        {
            cout<<endl;
            for(int i=0;i<max_cap*7;i++)
                cout<<"\xcd";
            cout<<endl;
            print_using_horizontal_boxes(f);
            cout<<endl;
            for(int i=0;i<max_cap*4;i++)
                cout<<"\xdf\xdf";
            cout<<endl;
        }

};

int main()
{
    int capacity, n;
    cout<<"Enter the maximum number of frames possible: ";
    cin>>capacity;
    LFD obj(capacity);

    cout<<"Enter the number of pages involved: ";
    cin>>n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    for(int i=0;i<n;i++)
        obj.add_to_v(v[i],i);
    for(int i=0;i<n;i++)
    {
        obj.put(v[i],i);
        cout<<"After "<<(i+1)<<" pages invoked: ";
        obj.print_pages();
    }
    cout<<"Number of page-hits in Largest Forward Distance --> "<<obj.page_hits<<endl;
    cout<<"Number of page-faults in Largest Forward Distance --> "<<obj.page_faults<<endl;
}
