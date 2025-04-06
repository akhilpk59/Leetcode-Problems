#include<iostream>
#include<vector>

using namespace std;

int minimum(int h1, int h2){
    if (h1==0||h2==0) return -1;
    return (h1<h2) ? h1 : h2;
}

int trap(vector<int>& height){
    int answer = 0;
    int n = height.size();
    int start = 0;
    int h_1 = -1;
    int h_2 = -1;
    int finish = 1;
    int d_flag = 0;
    int s_index = -1;
    int e_index = -1;
    int temp = -1;
    for (int i=0;i<n;i++){
        if (height[i]!=0){
            start++;
        }
        if (start==0) continue;
        if (height[i]>=h_1&&d_flag==0&&finish==1) {
            h_1 = height[i];
            s_index = i;
            cout<<"A : "<<" h_1 : "<<h_1<<" s_index : "<<s_index<<endl;
            continue;
        }
        else if (height[i]<h_1&&d_flag==0&&finish==1) {
            d_flag = 1;
            temp = height[i];
            cout<<"B :"<<" temp : "<<temp<<endl;
            finish = 0;
            //h_2 = height[i];
            continue;
        }
        else if (height[i]<=temp&&d_flag==1&&finish==0){
            temp = height[i];
            cout<<"C : temp : "<<temp<<endl;
            continue;
        }
        else if (height[i]>temp&&d_flag==1&&finish==0){
            h_2 = height[i];
            e_index = i;
            d_flag = 0;
            cout<<"D : h_2 : "<<h_2<<" e_index : "<<e_index<<endl;
            continue;
        }
        else if (height[i]>=h_2&&d_flag==0&&finish==0){
            h_2 = height[i];
            e_index = i;
            cout<<"E : h_2 : "<<h_2<<" e_index : "<<e_index<<endl;
        }
        else if (height[i]<h_2&&d_flag==0&&finish==0){
            int h = minimum(h_1,h_2);
            cout<<"F : h : "<<h<<endl;
            if (h==-1) {
                cout<<"G : final answer : "<<answer<<endl;
                return answer;
            }
            for (int j=s_index+1;j<e_index;j++){
                answer+=(h-height[j]);
                cout<<"H : answer in loop : "<<answer<<endl;
            }
            h_1 = h_2;
            s_index = e_index;
            temp = height[i];
            d_flag = 1;
            cout<<"I : h_1 : "<<h_1<<" s_index : "<<s_index<<" temp : "<<temp<<" d_flag : "<<d_flag<<endl;
            continue;
        }
        // if (a_flag==0){
        //     if (height[i]>=h_2&&d_flag==1){
        //         h_2 = height[i];
        //         e_index = i;
        //         continue;
        //     }
        //     else if (height[i]<h_2&d_flag==1){
        //         int h = minimum(h_1,h_2);
        //         h_1 = h_2;
        //         i--;
        //         if (h==-1) {
        //             s_index = e_index;
        //             break;
        //         }
        //         for (int j=s_index+1;j<e_index;j++){
        //             answer += (h-height[j]);
        //         }
        //         s_index = e_index;
        //         a_flag = 1;
        //         d_flag = 0;
        //         continue;
        //     }
             
        // }
    }
    return answer;
}

int main(){
    vector<int> height = {4,2,0,3,2,5};
    cout<<trap(height)<<endl;
    return 0;
}