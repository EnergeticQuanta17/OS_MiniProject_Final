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



class FIFO
{
	public:
		int capacity;
		FIFO(int cap)
		{
			capacity=cap;
		}
		void pageFaults(vector<int>& pages, int n)
		{	
			unordered_set<int> s;
			queue<int> indexes;
			int page_faults = 0;
			for (int i=0; i<n; i++)
			{
				if (s.size() < capacity)
				{
					if (s.find(pages[i])==s.end())
					{
						s.insert(pages[i]);
						page_faults++;
						indexes.push(pages[i]);
					}
				}
				else
				{
					if (s.find(pages[i]) == s.end())
					{
						int val = indexes.front();
						indexes.pop();
						s.erase(val);
						s.insert(pages[i]);
						indexes.push(pages[i]);
						page_faults++;
					}
				}
				vector<int> vv;
				queue<int>q2(indexes);
				 while (!q2.empty()) {
					vv.push_back(q2.front());
					q2.pop();
   					}				
				display_page_frames(vv);
			}
		}
		void display_page_frames(vector<int>& v)
		{
			for(int i=0;i<45;i++)
                cout<<"\xcd";
            cout<<endl;
            print_using_horizontal_boxes(v);
            cout<<endl;
            for(int i=0;i<70;i++)
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
    FIFO obj(capacity);

    cout<<"Enter the number of pages involved: ";
    cin>>n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    print_page_input(v);
	obj.pageFaults(v, v.size());
	system("pause");
}