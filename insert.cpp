#include<iostream>
#include<vector>
using std::vector;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
    int n = intervals.size();
    vector<vector<int>> answer;
    if (n==0){
        answer.push_back(newInterval);
        return answer;
    }
    else if (n==1){
        if (newInterval[1]<=intervals[0][0]) {
            if (newInterval[1]==intervals[0][0]) {
                intervals[0][0] = newInterval[0];
                return intervals;
            }
            intervals.insert(intervals.begin(),newInterval);
            return intervals;
        }
        else if (newInterval[0]>=intervals[0][1]) {
            if (newInterval[0]==intervals[0][1]) {
                intervals[0][1] = newInterval[1];
                return intervals;
            }
            intervals.push_back(newInterval);
            return intervals;
        }
        if (intervals[0][0]<=newInterval[0]) {
            if (intervals[0][1]>=newInterval[1]) return intervals;
            else {
                intervals[0][1] = newInterval[1];
                return intervals;
            }
        }
        else {
            intervals[0][0] = newInterval[0];
            if (intervals[0][1]>=newInterval[1]) return intervals;
            else {
                intervals[0][1] = newInterval[1];
                return intervals;
            }
        }
    }

    if (newInterval[1]<intervals[0][0]) {
        intervals.insert(intervals.begin(),newInterval);
        return intervals;
    }
    else if (newInterval[0]>intervals[n-1][1]) {
        intervals.push_back(newInterval);
        return intervals;
    }
    int i=0;
    int count = 0;
    while (i<n&&newInterval[0]>=intervals[i++][0])count++;

    if (count==0){
        i = 0;
        while (i<n&&newInterval[1]>intervals[i++][1]) count++;
        if (count==n){
            intervals.clear();
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<int>add;
        add.push_back(newInterval[0]);
        add.push_back(intervals[count][1]);
        intervals.erase(intervals.begin(),intervals.begin()+count+1);
        intervals.insert(intervals.begin(),add);
        return intervals;
    }
    else if (count==n){
        if (intervals[n-1][1]>=newInterval[1]) return intervals;
        else {
            intervals[n-1][1] = newInterval[1];
            return intervals;
        }
    }
    // std::cout<<count<<std::endl;
    vector<int> temp = intervals[count-1];
    int delC = 0;
    if (temp[1]<newInterval[0]) {
        for (int i=count;i<n;i++){
            if (newInterval[1]<intervals[i][0]){
                intervals.erase(intervals.begin()+count,intervals.begin()+count+delC);
                intervals.insert(intervals.begin()+count,newInterval);
                return intervals;
            }
            else {
                if (newInterval[1]<intervals[i][1]){
                    vector<int> fresh;
                    fresh.push_back(newInterval[0]);
                    fresh.push_back(intervals[i][1]);
                    intervals.erase(intervals.begin()+count,intervals.begin()+count+delC+1);
                    intervals.insert(intervals.begin()+count,fresh);
                    return intervals;
                }
                else delC++;
            }
        }
        intervals.erase(intervals.begin()+count,intervals.end());
        intervals.push_back(newInterval);
        return intervals;
    }
    else { 
        delC = 0;
        // std::cout<<"we got here"<<std::endl;
        if (temp[1]>=newInterval[1]) return intervals;
        else {
            for (int i=count;i<n;i++){
                if (newInterval[1]<intervals[i][0]) {
                    vector<int> fresher;
                    fresher.push_back(temp[0]);
                    fresher.push_back(newInterval[1]);
                    intervals.erase(intervals.begin()+count-1,intervals.begin()+count+delC);
                    intervals.insert(intervals.begin()+count-1,fresher);
                    return intervals;
                }
                else {
                    if (newInterval[1]<intervals[i][1]){
                        vector<int> fresher;
                        fresher.push_back(temp[0]);
                        fresher.push_back(intervals[i][1]);
                        // std::cout<<fresher[0]<<" "<<fresher[1]<<std::endl;
                        // std::cout<<count<<" "<<delC<<std::endl;
                        // std::cout<<"------------"<<std::endl;
                        intervals.erase(intervals.begin()+count-1,intervals.begin()+count+delC+1);
                        intervals.insert(intervals.begin()+count-1,fresher);
                        return intervals;
                    }
                    else delC++;
                }
            }
            vector<int> freshmax;
            freshmax.push_back(temp[0]);
            freshmax.push_back(newInterval[1]);
            intervals.erase(intervals.begin()+count-1,intervals.end());
            intervals.push_back(freshmax);
            return intervals;
        }
    }
}

int main(){
    vector<vector<int>> intervals = {{1,5}};
    vector<int> newInterval = {2,3};
    vector<vector<int>> answer = insert(intervals,newInterval);
    for (auto val : answer){
        for (auto nums : val) std::cout<<nums<<" ";
        std::cout<<std::endl;
    }
    return 0;
}