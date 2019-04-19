#include<bits/stdc++.h>
using namespace std;
int n;

void bankersalgo(int n,int m,int **max,int **alloc,int **need,bool f[],int avail[])
{
    int l=0,s=0;
    bool y;
    while(l<n)
    {
        s=0;
        for(int k=0;k<n;k++)
        {
            if(f[k]==false)
            {
                cout<<"Process "<<k+1<<" f value is "<<"1"<<endl;
                int flag = 0;
                for(int j=0;j<m;j++)
                {
                    cout<<"hi"<<endl;
                    cout << k << " " << j;
                    cout << avail[j] << " avail done" << endl;
                    cout << need[k][j] << " need done" << endl;
                    cout << need[k][j] << " " << avail[j] << endl;
                    if(need[k][j]>avail[j])
                    {
                        flag=1;
                        cout << "came here\n";
                        break;
                    }
                }
                cout << "yeha to aaja" << endl;
                if(flag==0)
                {
                    l++;s++;f[k]=true;
                    cout<<"Process "<<k+1<<" is Successfully Executed"<<endl;
                    for(int j=0;j<m;j++)
                    {
                        avail[j]+=alloc[k][j];
                    }
                    do{
                    cout<<"Any changes 0/1 ?"<<endl;
                    cin>>y;
                    if(y)
                    {
                        int choice;
                        cout<<"1.Increase available resources \n 2.Decrease available resources \n 3.Increase max for one process \n 4.Decrease max for one process \n 5.Increase one process \n 6.Decrease one process \n "<<endl;
                        cin>>choice;
                            switch(choice)
                            {
                                case 1:
                                    {
                                        cout<<"Enter the amount of new resources to be added for each resource type"<<endl;
                                        int x;
                                        for(int i=0;i<n;i++)
                                        {
                                            cin>>x;
                                            avail[i]+=x;
                                        }
                                        break;
                                    }
                                case 2:
                                    {
                                        cout<<"Enter the amount of resources to be deleted for each resource type"<<endl;
                                        int x;
                                        for(int i=0;i<n;i++)
                                        {
                                            cin>>x;
                                            avail[i]-=x;
                                        }
                                        break;
                                    }
                                case 3:
                                    {
                                        int del;
                                        cout<<"Enter the process to increase the max resources"<<endl;
                                        cin>>del;
                                        del--;
                                        cout<<"Enter the amount of resources to be incresed for each resource type"<<endl;
                                        int x;
                                        for(int i=0;i<m;i++)
                                        {
                                            cin>>x;
                                            max[del][i]+=x;
                                        }
                                        break;
                                    }
                                case 4:
                                    {
                                        int del;
                                        cout<<"Enter the process to decrease the max resources"<<endl;
                                        cin>>del;
                                        del--;
                                        cout<<"Enter the amount of resources to be decreased for each resource type"<<endl;
                                        int x;
                                        for(int i=0;i<m;i++)
                                        {
                                            cin>>x;
                                            max[del][i]-=x;
                                        }
                                        break;
                                    }
                                case 5:
                                    {
                                        bool *cf=new bool[n];
                                        for(int i=0;i<n;i++)cf[i]=f[i];
                                        delete [] f;
                                        bool *f=new bool[n+1];
                                        for(int i=0;i<n;i++)
                                        {
                                            f[i]=cf[i];
                                        }
                                        f[n]=false;
                                        int **cmax=new int*[n],**alloc1=new int*[n],**cneed =new int*[n];
                                        for(int i=0;i<n;i++)
                                        {
                                            cmax[i]=new int[m];alloc1[i]=new int[m];cneed[i]=new int[m];
                                        }
                                        for(int i=0;i<n;i++)
                                        {
                                            for(int j=0;j<m;j++)
                                            {
                                                cmax[i][j]=max[i][j];
                                                alloc1[i][j]=alloc[i][j];
                                                cneed[i][j]=need[i][j];
                                            }
                                        }
                                        delete [] max,alloc,need;
                                        n++;
                                        int **max=new int*[n],**alloc=new int*[n],**need =new int*[n];
                                        for(int i=0;i<n;i++)
                                        {
                                            max[i]=new int[m];alloc[i]=new int[m];need[i]=new int[m];
                                        }
                                        for(int i=0;i<n-1;i++)
                                        {
                                            for(int j=0;j<m;j++)
                                            {
                                                max[i][j]=cmax[i][j];
                                                alloc[i][j]=alloc1[i][j];
                                                need[i][j]=cneed[i][j];
                                            }
                                        }
                                        cout<<"Enter the resources already allocated for newly added process"<<endl;
                                        for(int i=0;i<m;i++)
                                        cin>>alloc[n-1][i];
                                        cout<<"Enter the max resources to be allocated for newly added process"<<endl;
                                        for(int i=0;i<m;i++)
                                        {
                                            cin>>max[n-1][i];
                                            need[n-1][i]=max[n-1][i]-alloc[n-1][i];
                                        }
                                        delete [] cmax,alloc1,cneed;
                                        break;
                                    }
                                case 6:
                                {
                                    if(n==0)
                                    {
                                        cout<<"Process list empty"<<endl;
                                        break;
                                    }
                                    n--;int del;
                                    cout<<"Enter the process to be deleted"<<endl;cin>>del;
                                    del--;
                                    bool *cf=new bool[n+1];
                                    for(int i=0;i<n+1;i++)cf[i]=f[i];
                                    delete [] f;
                                    bool *f=new bool[n];
                                    for(int i=0;i<del;i++)f[i]=cf[i];
                                    for(int i=del+1;i<n+1;i++)f[i-1]=cf[i];
                                    int **cmax=new int*[n+1],**alloc1=new int*[n+1],**cneed =new int*[n+1];
                                    for(int i=0;i<n+1;i++)
                                    {
                                        cmax[i]=new int[m];alloc1[i]=new int[m];cneed[i]=new int[m];
                                    }
                                    for(int i=0;i<n+1;i++)
                                    {
                                        for(int j=0;j<m;j++)
                                        {
                                            cmax[i][j]=max[i][j];
                                            alloc1[i][j]=alloc[i][j];
                                            cneed[i][j]=need[i][j];
                                        }
                                    }
                                    delete [] max,alloc,need;
                                    int **max=new int*[n],**alloc=new int*[n],**need =new int*[n];
                                    for(int i=0;i<n;i++)
                                    {
                                        max[i]=new int[m];alloc[i]=new int[m];need[i]=new int[m];
                                    }
                                    for(int i=0;i<del;i++)
                                    {
                                        for(int j=0;j<m;j++)
                                        {
                                            max[i][j]=cmax[i][j];
                                            alloc[i][j]=alloc1[i][j];
                                            need[i][j]=cneed[i][j];
                                        }
                                    }
                                    for(int i=del+1;i<n+1;i++)
                                    {
                                        for(int j=0;j<m;j++)
                                        {
                                            max[i-1][j]=cmax[i][j];
                                            alloc[i-1][j]=alloc1[i][j];
                                            need[i-1][j]=cneed[i][j];
                                        }
                                    }
                                    delete [] cmax,alloc1,cneed;
                                    break;
                                }
                            }
                        }
                    }while(y==1);
                }
            }
        }
        if(s==0)
        {
            for(int i=0;i<n;i++)
            if(f[i]==false)
            cout<<"Deadlock occured for process "<<(i+1)<<endl;
        }
    }
}
int main()
{
    int m;
    cout<<"Enter initial number of processes"<<endl;
    cin>>n;
    cout<<"Enter number of resource types"<<endl;
    cin>>m;
    int avail[m];
    bool *f=new bool[n];
    cout<<"Enter the available resources of each type"<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>avail[i];
    }
    int **max=new int*[n],**alloc=new int*[n],**need =new int*[n];
    for(int i=0;i<n;i++)
    {
        max[i]=new int[m];alloc[i]=new int[m];need[i]=new int[m];f[i]=false;
    }
    cout<<"Enter the resources already allocated"<<endl;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        cin>>alloc[i][j];
    }
    cout<<"Enter the max resources to be allocated"<<endl;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        cin>>max[i][j];
        need[i][j]=max[i][j]-alloc[i][j];
    }
    bankersalgo(n,m,max,alloc,need,f,avail);
}
