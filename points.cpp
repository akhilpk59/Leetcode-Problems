#include<iostream>
#include<vector>
using std::vector;

int maxPoints(vector<vector<int>>& points){
    int n = points.size();
    if (n==1) return 1;
    if (n==2) return 2;
    int maxCount = 2;
    for (int i = 0;i<n-1;i++){
        int x1 = points[i][0];
        int y1 = points[i][1];
        
        for (int j = i+1;j<n;j++) {
            int yDiff = points[j][1] - y1;
            int xDiff = points[j][0] - x1;
            int current = 2;
            for (int k=j+1;k<n;k++){
                if (((points[k][1]-y1)*(xDiff))==((points[k][0]-x1)*yDiff)) current++;
                if (current>maxCount) maxCount = current;
            }
            
        }
    }

    return maxCount;

}

int main(){
    vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    std::cout<<maxPoints(points)<<std::endl;
    return 0;
}