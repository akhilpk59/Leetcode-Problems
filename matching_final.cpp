#include<iostream>
#include<string>
using namespace std;

struct LL{
    char a;
    int freq;
    LL* next;
};

LL* shead = NULL;
LL* phead = NULL;

bool isEmpty(LL* head){
    if (head==NULL) return true;
    else return false;
}

void insert(LL*& head, char a, int freq){
    LL* temp = new LL;
    temp->a = a;
    temp->freq = freq;
    temp->next = NULL;

    if (head==NULL) {
        head = temp;
        return;
    }
    LL* temp1 = head;
    while (temp1->next!=NULL) temp1 = temp1->next;
    temp1->next = temp;
    return;
}

void print (LL* head){
    LL* temp = head;
    while(temp!=NULL){
        cout<<temp->a<<" "<<temp->freq<<" / ";
        temp=temp->next;
    }
    cout<<endl;
}

bool find (string s, char a){
    int n = s.length();
    for (int i=0;i<n;i++){
        if (s[i]==a) return true;
    }
    return false;
}

void load (string s, string p){
    //if (p==s) return true;
    int pn = p.length();
    int sn = s.length();
    char current = s[0];
    int freq_current = 0;
    for (int i=0;i<sn;i++){
        if (s[i]==current) {
            freq_current++;
            if (i==sn-1) insert(shead,current,freq_current);
        }
        else {
            insert(shead,current,freq_current);
            current = s[i];
            freq_current = 1;
            if (i==sn-1) insert(shead,current,freq_current);
        } 
    }
    int i = 0;
    while(i<pn-1){
        if (p[i+1]=='*') {
            insert(phead,p[i],0);
            i+=2;
            continue;
        }
        else if (p[i+1]!=p[i]) {
            insert(phead,p[i],1);
            i++;
            continue;
        }
        else if (p[i+1]==p[i]){
            current = p[i];
            freq_current = 0;
            while((p[i]==current)&&(i<pn-1)){
                freq_current++;
                i++;
            }
            if (p[i]=='*') {
                insert (phead, current, freq_current-1);
                insert (phead,current,0);
                i++;
                continue;
            }
            else if (p[i]!=current) {
                insert(phead, current,freq_current);
                if (i==pn-1) {
                    insert(phead,p[i],1);
                    break;
                } 
                continue;
            }
            else if (i==pn-1){
                insert(phead,current,++freq_current);
                break;
            }
        }
    }
    if (i==pn-1) insert(phead,p[i],1);
}

bool partial (LL*shead, LL* phead){
    if (phead==NULL) return true;
    LL* temps = shead;
    LL* tempp = phead;
    if (temps==NULL){
        if (tempp->freq!=0) return false;
        else return partial(temps,tempp->next);
    }
    else if (tempp->a=='.'){
        if (tempp->freq!=0){
            int count = tempp->freq;
            while (count!=0){
                count--;
                temps=temps->next;
                if (temps==NULL) break;
            }
            if (count!=0) return false;
            else return partial(temps,tempp->next);
        }
        else if (tempp->next==NULL) return true;
        else {
           if (partial(temps,tempp->next)) return true;
           else return false;
        }
    }
    else if (tempp->a!=temps->a){
        if (tempp->freq!=0) return false;
        else return partial (temps,tempp->next);
    }
    else {
        if (tempp->freq>temps->freq) return false;
        else if (tempp->freq==temps->freq) return partial (temps->next,tempp->next);
        else {
            if (tempp->freq!=0){
                temps->freq -= tempp->freq;
                return partial (temps,tempp->next);
            }
        }
    }

}

bool match(LL* shead, LL* phead){
    LL* tempp = phead;
    LL* temps = shead;
    if (tempp==NULL&&temps==NULL) return true;
    else if (temps!=NULL&&tempp==NULL) return false;
    else if (tempp!=NULL&&temps==NULL) {
        if (tempp->freq!=0) return false;
        else return match(temps,tempp->next);
    }
    else if (tempp->a=='.'){
        if (tempp->freq!=0){
            int count = tempp->freq;
            while (count!=0){
                count--;
                temps=temps->next;
                if (temps==NULL) break;
            }
            if (count!=0) return false;
            else return match(temps,tempp->next);
        }
        else {
            if (tempp->next==NULL) return true;
            else {
                return partial(temps,tempp->next);
            }
        }
    }

    else if (tempp->a!=temps->a){
        if (tempp->freq!=0) return false;
        else return match(temps,tempp->next);
    }
    else {
        if (tempp->freq>temps->freq) return false;
        else if (tempp->freq==temps->freq) return match(temps->next,tempp->next);
        else {
            if (tempp->freq!=0) {
                temps->freq -= tempp->freq;
                return match (temps,tempp->next);
            }
            else if (tempp->next==NULL) return match(temps->next, tempp->next);
            else if (tempp->next->a!=temps->a) return match (temps->next, tempp->next);
            else {
                int count = 0;
                while (tempp!=NULL&&tempp->a==temps->a){
                    count += tempp->freq;
                    tempp=tempp->next;
                }
                if (tempp==NULL){
                    if (count>temps->freq) return false;
                    else return true;    
                }
                else if (count>temps->freq) return false;
                else return match(temps->next,tempp);
            }
        }
    }
}



int main(){
    string s = "";
    string p = "";
    getline(cin,s);
    getline(cin,p);
    load(s,p);
    print(shead);
    print(phead);
    cout<<boolalpha<<match(shead, phead)<<endl;
    return 0;
}