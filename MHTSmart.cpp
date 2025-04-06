#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<utility>
using std::vector;
using std::map;
using std::queue;
using std::pair;


// void MHT(int i, vector<vector<int>> tree, int n, bool visited[], int value[], map<int,int>& temp, int current = 0){
//     if (visited[i]) return;
//     visited[i] = true;
//     value[i] = current;
//     if (temp.find(i)==temp.end()) temp[i] = current;
//     for (int j=0;j<n;j++){
//         if (tree[i][j]==0) continue;
//         if (visited[j]) continue;
//         MHT (j,tree,n,visited,value,temp,current+1);
//     }    
// }

vector<int> hunt (int root, vector<vector<int>> tree, int n, int height){

}

void BFS (int i, vector<vector<int>> tree, int n, bool visited[], map<int,int>& temp){
    visited[i] = true;
    queue<pair<int,int>> q;
    pair<int,int> tempo;
    tempo.first = i;
    tempo.second = 0;
    q.push(tempo);

    while (!q.empty()){
        tempo = q.front();
        int cNode = tempo.first;
        int cHeight = tempo.second;
        if (temp.find(cNode)==temp.end()) temp[cNode] = cHeight;
        for (int j=0;j<n;j++){
            if (!tree[cNode][j]) continue;
            if (visited[j]) continue;
            visited[j] = true;
            pair<int,int> inside;
            inside.first = j;
            inside.second = cHeight + 1;
            q.push(inside);
        }
        q.pop();
    }
}

int maxim(map<int,int> temp){
    int maximum = 0;
    for (auto it = temp.begin();it!=temp.end();it++){
        if (it->second>maximum) maximum = it->second;
    }
    return maximum;
}

int maxim(int a,int b, int c){
    return (a>b) ? ((a>c) ? a : c) : ((b>c) ? b : c);
}

void reset(bool visited[], int n){
    for (int i=0;i<n;i++) visited[i] = false;
}

void reset(int value[], int n){
    for (int i=0;i<n;i++) value[i] = 0;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges){
    vector<int> answer;
    if (n==1) {
        answer.push_back(0);
        return answer;
    }
    if (n==2){
        answer.push_back(0);
        answer.push_back(1);
        return answer;
    }
    vector<vector<int>> tree;
    for (int i=0;i<n;i++){
        vector<int> temp;
        for (int j=0;j<n;j++){
            temp.push_back(0);
        }
        tree.push_back(temp);
    }
    int m = edges.size();
    // std::cout<<"did we get here ?"<<m<<std::endl;
    for (int i=0;i<m;i++){
        int x = edges[i][0];
        int y = edges[i][1];
        tree[x][y] = 1;
        tree[y][x] = 1;
        // std::cout<<x<<" : x and "<<y<<" : y"<<std::endl;
    }
    // std::cout<<"we got here"<<std::endl;
    bool visited[n];
    for (int i=0;i<n;i++) visited[i] = false;
    int store[3];

    for (int i=0;i<3;i++){
        map<int,int> temp;
        BFS(i,tree,n,visited,temp);
        store[i] = maxim(temp);
        reset(visited,n);    
    }
    // std::cout<<"did we get here 3?"<<std::endl;
    if (store[0]==store[1]==store[2]) {
        vector<int> result = hunt(0,tree,n,store[0]);
        int l = result.size();
        if (l%2!=0) {
            answer.push_back(result[l/2]);
            return answer;
        }
        else {
            answer.push_back(result[(l/2)-1]);
            answer.push_back(result[l/2]);
            return answer;
        }
    }
    int k = maxim(store[0],store[1],store[2]);
    if (k==store[0]){
         vector<int> result = hunt(0,tree,n,store[0]);
        int l = result.size();
        if (l%2!=0) {
            answer.push_back(result[l/2]);
            return answer;
        }
        else {
            answer.push_back(result[(l/2)-1]);
            answer.push_back(result[l/2]);
            return answer;
        }
    }
    else if (k==store[1]){
         vector<int> result = hunt(1,tree,n,store[1]);
        int l = result.size();
        if (l%2!=0) {
            answer.push_back(result[l/2]);
            return answer;
        }
        else {
            answer.push_back(result[(l/2)-1]);
            answer.push_back(result[l/2]);
            return answer;
        }
    }
    else {
         vector<int> result = hunt(0,tree,n,store[2]);
        int l = result.size();
        if (l%2!=0) {
            answer.push_back(result[l/2]);
            return answer;
        }
        else {
            answer.push_back(result[(l/2)-1]);
            answer.push_back(result[l/2]);
            return answer;
        }
    }
}

int main(){
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{3,4},{0,5},{4,6},{3,7},{5,8},{4,9},{0,10},{3,11},{6,12},{8,13},{4,14},{12,15},{4,16},{5,17},{9,18},{15,19},{2,20},{5,21},{17,22},{16,23},{22,24},{13,25},{8,26},{14,27},{1,28},{0,29},{24,30},{16,31},{18,32},{30,33},{30,34},{24,35},{16,36},{22,37},{26,38},{23,39},{1,40},{7,41},{15,42},{26,43},{42,44},{10,45},{29,46},{14,47},{31,48},{22,49},{28,50},{44,51},{23,52},{49,53},{14,54},{2,55},{37,56},{15,57},{29,58},{39,59},{7,60},{59,61},{56,62},{59,63},{31,64},{9,65},{9,66},{12,67},{66,68},{19,69},{14,70},{69,71},{35,72},{12,73},{2,74},{66,75},{28,76},{69,77},{45,78},{11,79},{55,80},{79,81},{78,82},{6,83},{76,84},{79,85},{14,86},{44,87},{7,88},{19,89},{60,90},{49,91},{46,92},{23,93},{34,94},{18,95},{26,96},{26,97},{95,98},{63,99},{59,100},{40,101},{56,102},{29,103},{33,104},{74,105},{79,106},{70,107},{25,108},{76,109},{69,110},{6,111},{25,112},{88,113},{112,114},{87,115},{97,116},{27,117},{45,118},{51,119},{95,120},{74,121},{111,122},{43,123},{94,124},{46,125},{50,126},{77,127},{26,128},{34,129},{35,130},{84,131},{29,132},{20,133},{6,134},{131,135},{64,136},{87,137},{69,138},{123,139},{100,140},{69,141},{91,142},{60,143},{120,144},{114,145},{123,146},{22,147},{1,148},{80,149},{109,150},{55,151},{97,152},{135,153},{135,154},{32,155},{42,156},{27,157},{32,158},{59,159},{36,160},{105,161},{93,162},{1,163},{129,164},{28,165},{154,166},{106,167},{2,168},{46,169},{44,170},{147,171},{3,172},{31,173},{49,174},{83,175},{39,176},{42,177},{112,178},{3,179},{1,180},{103,181},{69,182},{119,183},{97,184},{150,185},{61,186},{84,187},{104,188},{36,189},{69,190},{181,191},{8,192},{182,193},{158,194},{148,195},{94,196},{17,197},{95,198},{86,199},{37,200},{181,201},{112,202},{155,203},{76,204},{73,205},{186,206},{186,207},{92,208},{129,209},{22,210},{195,211},{185,212},{202,213},{49,214},{113,215},{156,216},{77,217},{121,218},{98,219},{45,220},{75,221},{154,222},{195,223},{59,224},{104,225},{62,226},{134,227},{9,228},{158,229},{71,230},{120,231},{156,232},{125,233},{12,234},{109,235},{167,236},{172,237},{62,238},{131,239},{234,240},{237,241},{187,242},{224,243},{224,244},{31,245},{159,246},{28,247},{132,248},{123,249},{88,250},{63,251},{228,252},{100,253},{147,254},{228,255},{111,256},{19,257},{235,258},{20,259},{30,260},{149,261},{60,262},{20,263},{43,264},{160,265},{83,266},{108,267},{81,268},{63,269},{89,270},{24,271},{261,272},{179,273},{52,274},{114,275},{219,276},{259,277},{239,278},{274,279},{39,280},{53,281},{161,282},{256,283},{219,284},{229,285},{159,286},{143,287},{286,288},{195,289},{99,290},{25,291},{244,292},{134,293},{286,294},{163,295},{174,296},{184,297},{171,298},{158,299},{10,300},{269,301},{233,302},{220,303},{50,304},{222,305},{220,306},{263,307},{266,308},{7,309},{117,310},{191,311},{207,312},{302,313},{9,314},{193,315},{219,316},{185,317},{120,318},{176,319},{119,320},{130,321},{233,322},{160,323},{56,324},{303,325},{167,326},{236,327},{97,328},{61,329},{20,330},{242,331},{90,332},{169,333},{332,334},{298,335},{291,336},{205,337},{74,338},{173,339},{257,340},{9,341},{39,342},{263,343},{10,344},{78,345},{29,346},{322,347},{43,348},{134,349},{344,350},{327,351},{270,352},{21,353},{345,354},{277,355},{158,356}};
    int n = 357;
    vector<int> answer = findMinHeightTrees(n,edges);
    for (auto val : answer) std::cout<<val<<" ";
    std::cout<<std::endl;
    return 0;
}