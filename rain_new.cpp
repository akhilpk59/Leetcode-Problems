#include<iostream>
#include<vector>

using namespace std;

int minim(vector<int> height,int start, int end){
    return (height[start]<height[end]) ? height[start] : height[end];
}
int count(vector<int> height, int start, int end){
    int answer = 0;
    if (start>=end) return 0;
    int h = minim(height, start, end);
    for (int i = start+1;i<end;i++){
        if ((h-height[i])>=0) answer+= (h - height[i]);
    }
    return answer;
}

int max_index(vector<int> height, int index[], int n){
    int maxim = -1;
    int index_num = -1;
    for (int i=0;i<n;i++){
        if (index[i]==-1) break;
        if (height[index[i]]>=maxim){
            maxim = height[index[i]];
            index_num = i;
        }
    }
    return index_num;
}
int last_index(int index[],int n){
    for (int i=0;i<n;i++){
        if (index[i]==-1) return i-1;
    }
    return n-1;
}

int trap(vector<int>& height){
   
    int n = height.size();
    if (n<=2) return 0;
    int index[n]; 
    for (int i=0;i<n;i++){
        index[i] = -1;
    }
    int ind = 0;
    if (height[1]<height[0]) index[ind++] = 0;
    for (int i=1;i<n-1;i++){
        if ((height[i-1]<height[i])&&(height[i+1]<height[i])){
            index[ind++] = i;
           // cout<<"i : "<<i<<endl;
        }
        else if ((height[i-1]==height[i])&&(height[i+1]<height[i])){
            index[ind++] = i;
         //   cout<<"i : "<<i<<endl;
        }
        else if ((height[i-1]<height[i])&&(height[i+1]==height[i])){
            index[ind++] = i;
          //  cout<<"i : "<<i<<endl;
        }
    }
    if (height[n-2]<height[n-1]) index[ind] = n-1;

    for (int i =0;i<n;i++){
        cout<<"index["<<i<<"] : "<<index[i]<<endl;
    }

    int answer = 0;
    int finale = max_index(height,index,n);
    int last = last_index(index,n);
    int start = 0;
    int h1 = height[index[start]];
    cout<<"finale : "<<finale<<" last : "<<last<<" start : "<<start<<" h1 : "<<h1<<endl;
    for (int i = 0;i<=finale;i++){
        if (height[index[i]]>=h1){
            answer+= count(height,index[start],index[i]);
            start = i;
            h1 = height[index[i]];
        }
    }
    start = last;
    h1 = height[index[start]];
    for (int i = last;i>=finale;i--){
        if (height[index[i]]>=h1){
            answer+=count(height,index[i],index[start]);
            start = i;
            h1 = height[index[i]];
        }
    }
    return answer;
}

int main(){
    vector<int> height = {3, 0, 2, 0, 4};
    cout<<trap(height)<<endl;
    return 0;
}