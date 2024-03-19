class Solution {
public:
    int maximumSwap(int num) {
        vector<int> v;
        int tempnum = num;
        while(tempnum){
            v.push_back(tempnum%10);
            tempnum/=10;
        }
        reverse(v.begin(),v.end());
        int flag = 0;
        int n = v.size();
        for(int i=0;i<n-1;i++){
            if(v[i]<v[i+1]) {
                flag = 1;
                break;
            }
        }
        if(flag){
            for(int i=0;i<n-1;i++){
                int index=-1;
                int maxi = v[i];
                for(int j=i+1;j<n;j++){
                    if(v[j]>=maxi){
                        index = j;
                        maxi = v[j];
                    }
                }
                if(index!=-1 and v[i]!=v[index]){
                    swap(v[i],v[index]);
                    break;
                }
            }
        }
        else return num;
        int newNum = 0;
        for(int i=0;i<n;i++){
            newNum = newNum*10 + v[i];
        }
        return newNum;
    }
};