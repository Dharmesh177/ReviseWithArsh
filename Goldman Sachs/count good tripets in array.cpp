class Solution {
public:
    typedef long long ll;
    vector<ll> x,y;
    vector<int> record;
    void merge(vector<int> &total, int l,int r)
    {
        if(l>=r) return ;
        int mid=l+(r-l)/2;
        merge(total,l,mid);
        merge(total,mid+1,r);
        
        vector<int> tempValue(r-l+1);
        vector<int> tempRecord(r-l+1);
        int i=l,j=mid+1;
        int t=0;
        while(i<=mid && j<=r)
        {
            if(total[i]<=total[j])
            {
                tempValue[t]=total[i];
                tempRecord[t]=record[i];
                y[record[i]]+=(r-j+1);
                t++;
                i++;
            }
            else
            {
                tempValue[t]=total[j];
                tempRecord[t]=record[j];
                x[record[j]]+=i-l;
                t++;
                j++;
            }
        }
        while(i<=mid)
        {
            tempValue[t]=total[i];
            tempRecord[t]=record[i];
            t++;
            i++;
        }
        while(j<=r)
        {
            tempValue[t]=total[j];
            tempRecord[t]=record[j];
            x[record[j]]+=(mid-l+1);
            t++;
            j++;
        }
        for(int i=l;i<=r;i++)
        {
            total[i]=tempValue[i-l];
            record[i]=tempRecord[i-l];
        }
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size();
    vector<int> ind(n);
    x.resize(n);y.resize(n);
    for(int i=0;i<n;i++)
    {
        ind[nums1[i]]=i;
    }
    vector<int> todo(n);
    for(int i=0;i<n;i++)
    {
        todo[i]=ind[nums2[i]];
        record.push_back(i);
    }
    merge(todo,0,n-1);
    ll res=0;
    for(int i=0;i<n;i++)
    {
        res+=x[i]*y[i];
    }
    return res;
    }
};