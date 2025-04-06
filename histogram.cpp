#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>

using namespace std;

int Area(vector<int> histogram){
    int l = histogram.size();
    int area = 0;
    int minim = -1;
    for (int i=0;i<l;i++){
        if (minim==-1||histogram[i]<minim) minim = histogram[i];
        int current = minim*(i+1);
        if (current>area) area = current;
    }
    return area;
}

void final_check(vector<int>& check, unordered_map <vector<int>, pair<int, int>> cache){

}

int largestRectangleArea(vector<int>& heights, int start, int end){
    unordered_map <vector<int>, pair<int, int>> cache;
    pair <int, int> min_area;
    vector<int> temp;
    for (int i=start;i<=end;i++){
        temp.push_back(heights[i]);
        int minim = *min_element(temp.begin(),temp.end());
        int width = temp.size();
        int area = minim*width;
        min_area.first = minim;
        min_area.second = area;
        cache[temp] = min_area;
    }
    
    while (!cache.empty()){
        auto it = cache.begin();
        vector<int> check = it->first;
        pair<int, int> ma_temp = it->second;
        int local_min = ma_temp.first;
        if (check[0]!=local_min) {
            final_check(check,cache);
            continue;
        }
    }

}

int main(){
    vector<int> heights;
    int n = heights.size();
    cout<<largestRectangleArea(heights,0,n-1)<<endl;
    return 0;
}