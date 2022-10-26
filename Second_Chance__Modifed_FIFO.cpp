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
int present(int a[],int nf,int page,int rf_bit[])
{
    for(int i=0;i<nf;i++)
    {
        if(a[i]==page)
        {
          rf_bit[i]=1;
          return 1;
        }

    }
    return 0;
}

void printtable(int table_frame[], int nf)
{
    vector<int> v;
	for(int i=0; i<nf; i++)
	{
		if(table_frame[i] == -1)
			continue;
		else
			v.push_back(table_frame[i]);
	}
	for(int i=0;i<45;i++)
                cout<<"\xcd";
            cout<<endl;
            print_using_horizontal_boxes(v);
            cout<<endl;
            for(int i=0;i<70;i++)
                cout<<"\xdf\xdf";
            cout<<endl;
}


int main()
{
    int nf;
    cout<<"Enter number of frames: ";
    cin>>nf;
    int a[nf],rf_bit[nf];
    for(int i=0;i<nf;i++)
    {
        a[i]=-1;
        rf_bit[i]=0;
    }

    int np;
    cout<<"Enter number of pages: ";
    cin>>np;
    int b[np];
    cout<<"Enter page requests: ";
    for(int i=0;i<np;i++)
    {
        cin>>b[i];
    }
    int pos=0,count1=0;
    int page_faults=0;
    for(int i=0;i<np;i++)
    {
        printf("Page table after request from %2d:\n",b[i]);
        if(!present(a,nf,b[i],rf_bit))
        {
            //int pos=findpos(a,nf,b,i,np);
            pos=(pos+1)%nf;
            while(rf_bit[pos]==1)
            {
                rf_bit[pos]=0;
                pos=(pos+1)%nf;
            }

            a[pos]=b[i];
            printtable(a,nf);
            page_faults++;\
            continue;
        }

        printtable(a,nf);
		printf("\n");
    }

     printf("\nNumber of page faults : %d\n\n", page_faults);
     system("pause");
}