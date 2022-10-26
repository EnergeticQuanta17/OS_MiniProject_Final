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


class Optimal
{
    public:
        int cap;
        Optimal(int capacity)
        {
            cap=capacity;
        }
        bool search(int key, vector<int>& fr)
        {
            for (int i = 0; i < fr.size(); i++)
                if (fr[i] == key)
                    return true;
            return false;
        }
        
        int predict(vector<int>& pg, vector<int>& fr, int index)
        {
            int pn=pg.size();
            int res = -1, farthest = index;
            for (int i = 0; i < fr.size(); i++) {
                int j;
                for (j = index; j < pn; j++) {
                    if (fr[i] == pg[j]) {
                        if (j > farthest) {
                            farthest = j;
                            res = i;
                        }
                        break;
                    }
                }
                if (j == pn)
                    return i;
            }
            return (res == -1) ? 0 : res;
        }
 
        void optimalPage(vector<int>& pg)
        {
            int pn=pg.size();
            vector<int> fr;
            int hit = 0;
            for (int i = 0; i < pn; i++) {
                if (search(pg[i], fr)) {
                    hit++;
                    continue;
                }
                if (fr.size() < cap)
                    fr.push_back(pg[i]);
                else {
                    int j = predict(pg, fr, i + 1);
                    fr[j] = pg[i];
                }
                cout<<"Page numbers in main memory after "<<(i+1)<<" page request: \n";
                for(int i=0;i<55;i++)
                cout<<"\xcd";
                cout<<endl;
                print_using_horizontal_boxes(fr);
                cout<<endl;
                for(int i=0;i<70;i++)
                    cout<<"\xdf\xdf";
                    cout<<"\n";
                }
            cout<<"Number of page-hits in Least Frequently Used --> "<<hit<<endl;
            cout<<"Number of page-faults in Least Frequently Used --> "<<pn-hit<<endl;
        }

};

int main()
{
    int capacity, n;
    cout<<"Enter the maximum number of frames possible: ";
    cin>>capacity;
    Optimal obj(capacity);

    cout<<"Enter the number of pages involved: ";
    cin>>n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    obj.optimalPage(v);
    system("pause");
}