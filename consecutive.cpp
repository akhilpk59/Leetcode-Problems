#include<iostream>
#include<vector>
#include<utility>

using std::pair;
using std::vector;

int minim(vector<int> nums){
    int n = nums.size();
    int index = 0;
    for (int i=1;i<n;i++) {
        if (nums[i]<nums[index]) index = i;
    }
    return index;
}
int maxim(vector<int> nums){
    int n = nums.size();
    int index = 0;
    for (int i=1;i<n;i++) {
        if (nums[i]>nums[index]) index = i;
    }
    return index;
}

int cal(int a){
    if (a==0) return 1;
    if (a<0) a = 0-a;
    int digit = 0;
    while (a>0){
        digit++;
        a/=10;
    }
    return digit;
}

pair<int,bool> maxim (vector<pair<int,bool>> nums){
    int pMaxD = 0;
    int nMinD = 0;
    bool first = false;
    int n = nums.size();
    for (int i=0;i<n;i++){
        pair<int,bool> temp = nums[i];
        if (temp.second){
            if (temp.first<nMinD||!first){
                nMinD = temp.first;
                first = true;
            }
        }
        else {
            if (temp.first>pMaxD) pMaxD = temp.first;
        }
    }
    pair<int,bool> answer;
    if (pMaxD!=0) {
        answer.first = pMaxD;
        answer.second = false;    
    }
    else {
        answer.first = nMinD;
        answer.second = true;
    }
    return answer;
}
pair<int,bool> minim (vector<pair<int,bool>> nums){
    int pMinD = 0;
    int nMaxD = 0;
    bool first = false;
    int n = nums.size();
    for (int i=0;i<n;i++){
        pair<int,bool> temp = nums[i];
        if (temp.second){
            if (temp.first>nMaxD) nMaxD = temp.first;
            }
        else {
            if (temp.first<pMinD||!first) {
                pMinD = temp.first;
                first = true;
            }
        }
    }
    pair<int,bool> answer;
    if (nMaxD!=0) {
        answer.first = nMaxD;
        answer.second = true;
    }
    else {
        answer.first = pMinD;
        answer.second = false;
    }
     return answer;
}

int search(vector<pair<int,bool>> capture, int target, bool nSign = false){
    int n = capture.size();
    for (int i=0;i<n;i++){
        if (target==capture[i].first&&nSign==capture[i].second) return i;
    }
    return -1;
}

int maxim(int a,int b){
    return (a>b) ? a : b;
}

int maxim (int a, int b, int c){
    return (a>b) ? ((a>c) ? a : c) : ((b>c) ? b : c);
}

int longestConsecutive (vector<int> nums, bool flag = true){
    int n = nums.size();
    if (n==0||n==1) return n;
    int x = minim(nums);
    int y = maxim(nums);
    int l = (nums[y]-nums[x])+1;
    // x = minim(nums);
    // y = maxim(nums);
    // l = (nums[y]-nums[x]) + 1;
    bool arr[l];
    for (int i=0;i<l;i++) arr[i] = false;
    for (int i=0;i<n;i++) arr[nums[i]-nums[x]] = true;
    int consec = 0;
    // int count = 0;
    for (int i=0;i<l;i++){
        // count++;
        if (arr[i]){
            int current = 0;
            while (i<l&&arr[i]){
                current++;
                i++;
            }
            if (current>consec) consec = current;
        }
        // std::cout<<count<<std::endl;
    }
    return consec;
}


int alternate(vector<int>& nums){
    int n = nums.size();
    vector<pair<int,bool>> capture;
    
    for (int i=0;i<n;i++){
        int digit = cal(nums[i]);
        // std::cout<<digit<<" ";
        bool nSign = false;
        if (nums[i]<0) nSign = true;
        pair<int,bool> temp;
        temp.first = digit;
        temp.second = nSign;
        capture.push_back(temp);
    }
    pair<int,bool> minD = minim(capture);
    pair<int,bool> maxD = maxim(capture);

    if ((minD.second&&maxD.second)||(!minD.second&&!maxD.second)){
        int l;
        if (!minD.second) l = maxD.first-minD.first+1;
        else l = minD.first - maxD.first + 1;
        //std::cout<<maxD.first<<" "<<minD.first<<std::endl;
        int arr[l];
        for (int i=0;i<l;i++) arr[i] = 0;
        // for (int i=0;i<l;i++) std::cout<<arr[i]<<" ";
        // std::cout<<std::endl;
        // for (auto val : capture) std::cout<<val.first<<" ";
        // std::cout<<std::endl;
        for (int i=0;i<n;i++){
            pair<int,bool> temp = capture[i];
            if (!minD.second) arr[(temp.first)-minD.first]++;
            else arr[(temp.first)-maxD.first]++;
        }
        // for (auto val:arr) std::cout<<val<<" ";
        // std::cout<<std::endl;
        for (int i=0;i<l;i++){
            if (i==0&&arr[i]==1){
                if (arr[i+1]==0) {
                    int index;
                    if (!minD.second) index = search(capture,minD.first+i);
                    else index = search(capture,maxD.first+i,true);
                    nums.erase(nums.begin()+index);
                    capture.erase(capture.begin()+index);
                }
            }
            else if (i==l-1&&arr[i]==1){
                if (arr[i-1]==0){
                    int index;
                    if (!minD.second) index = search(capture,minD.first+i);
                    else index = search(capture,maxD.first+i,true);
                    nums.erase(nums.begin()+index);
                    capture.erase(capture.begin()+index);
                }
            }
            else {
                if ((arr[i+1]==0)&&(arr[i-1]==0)&&arr[i]==1){
                    int index;
                    if (!minD.second) index = search(capture,minD.first+i);
                    else index = search(capture,maxD.first+i,true);
                    nums.erase(nums.begin()+index);
                    capture.erase(capture.begin()+index);   
                }
            }
        }
        // int e = nums.size();
        // std::cout<<e<<std::endl;
        return longestConsecutive(nums);
    }

    else {
        // std::cout<<std::boolalpha<<"MinD : digits : "<<minD.first<<" and value : "<<minD.second<<std::endl;
        // std::cout<<std::boolalpha<<"MaxD : digits : "<<maxD.first<<" and value : "<<maxD.second<<std::endl;
        
        int l = maxD.first + minD.first;
        int arr[l];
        for (int i=0;i<l;i++) arr[i] = 0;
        for (int i=0;i<n;i++){
            pair<int,bool> temp = capture[i];
            if (!temp.second) arr[l-1-(maxD.first-temp.first)]++;
            else arr[minD.first-temp.first]++;
        }
        for (int i=0;i<l;i++){
            if (i==0&&arr[i]==1){
                if (arr[i+1]==0) {
                    int index;
                    if (i<minD.first) index = search(capture,minD.first-i,true);
                    else index = search(capture,(i-minD.first)+1,false);
                    nums.erase(nums.begin()+index);
                    capture.erase(capture.begin()+index);
                    arr[i]=0;
                }
            }
            else if (i==l-1&&arr[i]==1){
                if (arr[i-1]==0){
                    int index;
                    if (i<minD.first) index = search(capture,minD.first-i,true);
                    else index = search(capture,(i-minD.first)+1,false);
                    nums.erase(nums.begin()+index);
                    capture.erase(capture.begin()+index);
                    arr[i] = 0;
                }
            }
            else {
                if ((arr[i+1]==0)&&(arr[i-1]==0)&&arr[i]==1){
                    int index;
                    if (i<minD.first) index = search(capture,minD.first-i,true);
                    else index = search(capture,(i-minD.first)+1,false);
                    nums.erase(nums.begin()+index);
                    capture.erase(capture.begin()+index);   
                    arr[i] = 0;
                }
            }
        }
        vector<int> numsN;
        vector<int> numsP;
        int k = capture.size();
        for (int i=0;i<k;i++){
            if (capture[i].second) numsN.push_back(nums[i]);
            else numsP.push_back(nums[i]);
        }
        if (arr[minD.first]==0||arr[minD.first-1]==0) return maxim(longestConsecutive(numsN),longestConsecutive(numsP));
        else {
            int p = minD.first;
            int q = minD.first-1;
            while (arr[p]!=0&&arr[q]!=0&&p<l-1&&q>0){
                p++;
                q--;
            }
            vector<int> mid;
            int dN = minD.first+q;
            int dP = p - minD.first + 1;
            for (int i=0;i<k;i++){
                if (capture[i].second){
                    if (capture[i].first<=dN) mid.push_back(nums[i]);
                }
                else {
                    if (capture[i].first<=dP) mid.push_back(nums[i]);
                }
            }
            return maxim(longestConsecutive(numsN),longestConsecutive(numsP), longestConsecutive(mid));
        }
    }

}

int longestConsecutives(vector<int> nums){
    int n = nums.size();
    if (n==0||n==1) return n;
    int x = minim(nums);
    int y = maxim(nums);
    int l = (nums[y]-nums[x])+1;
    if (l>100000) return alternate(nums);
    // x = minim(nums);
    // y = maxim(nums);
    // l = (nums[y]-nums[x]) + 1;
    bool arr[l];
    for (int i=0;i<l;i++) arr[i] = false;
    for (int i=0;i<n;i++) arr[nums[i]-nums[x]] = true;
    int consec = 0;
    // int count = 0;
    for (int i=0;i<l;i++){
        // count++;
        if (arr[i]){
            int current = 0;
            while (i<l&&arr[i]){
                current++;
                i++;
            }
            if (current>consec) consec = current;
        }
        // std::cout<<count<<std::endl;
    }
    return consec;
}

int main(){
    vector<int> nums = {-1000000000,1,2,3,9,1000000000};
    std::cout<<longestConsecutives(nums)<<std::endl;
    return 0;
}