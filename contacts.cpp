#include<iostream>
// #include<string>
#include<vector>
using std::string;
using std::vector;

struct List{
    string val;
    List* next;
};

void insert(List*& head, string val){
    List* temp = new List;
    temp->next = NULL;
    temp->val = val;
    if (head==NULL){
        head = temp;
        return;
    }
    List* temp1 = head;
    while (temp1->next!=NULL) temp1 = temp1->next;
    temp1->next = temp;
}

class Information {
    public:
    virtual void DisplayInfo() = 0;
    virtual void AddInfo() = 0;
};

class Contacts {
    
    public:
    Contacts (){
        view = "list";
        length = 0;
        choice = "";
        index = -1;
        merged = true;
    }

    void DisplayInfo(){
        std::cout<<"Type in the name of the contact you wish to see"<<std::endl;
        std::getline(std::cin>>std::ws, choice);
        if (!merged) mergeSort(contacts);
        index = binarySearch(choice,contacts,0,length-1);
        while (index==-1) {
            std::cout<<"The name you entered does not exist in the contacts list, please try again OR \nIf you wish to go back to the contacts List, Enter '@@@' "<<std::endl;
            std::getline(std::cin>>std::ws, choice);
            if (choice=="@@@") {
                view = "list";
                return;
            }
            index = binarySearch(toLower(choice),contacts,0,length-1);
        }
        // std::cout<<"These are the contact details for "<<names[index]<<" : "<<std::endl;
        // std::cout<<"Title : "<<titles[index]<<std::endl;
        // std::cout<<"Work Phone number : "<<workPhoneNumbers[index]<<std::endl;
        // std::cout<<"Personal Phone number : "<<personalPhoneNumbers[index]<<std::endl;
        // std::cout<<"Work Email ID : "<<workEmails[index]<<std::endl;
        // std::cout<<"Personal Email ID : "<<personalEmails[index]<<std::endl;
        List* temp1 = contacts[index];
        view = "quit";
        std::cout<<"These are the contact details for "<<temp1->val<<" : "<<std::endl;
        temp1 = temp1->next;
        if (temp1==NULL) return;
        std::cout<<"Title : "<<temp1->val<<std::endl;
        temp1 = temp1->next;
        if (temp1==NULL) return;
        std::cout<<"Work Phone number : "<<temp1->val<<std::endl;
        temp1 = temp1->next;
        if (temp1==NULL) return;
        std::cout<<"Personal Phone number : "<<temp1->val<<std::endl;
        temp1 = temp1->next;
        if (temp1==NULL) return;
        std::cout<<"Work Email ID : "<<temp1->val<<std::endl;
        temp1 = temp1->next;
        if (temp1==NULL) return;
        std::cout<<"Personal Email ID : "<<temp1->val<<std::endl;
    }

    void AddInfo(){
        std::cout<<"Please enter the contact details that you wish to add : "<<std::endl;
        std::cout<<"Name of the contact : ";
        std::getline(std::cin>>std::ws, choice);
        contacts.push_back(NULL);
        insert(contacts.back(),toLower(choice));
        //names.push_back(toLower(choice));
        std::cout<<"Their title : (enter NA if not applicable)"<<std::endl;
        std::getline(std::cin>>std::ws, choice);
        //titles.push_back(choice);
        insert(contacts.back(),choice);
        std::cout<<"Their work phone number : (enter NA if not applicable)"<<std::endl;
        std::getline(std::cin>>std::ws, choice);
        //workPhoneNumbers.push_back(choice);
        insert(contacts.back(),choice);
        std::cout<<"Their personal phone number : (enter NA if not applicable)"<<std::endl;
        std::getline(std::cin>>std::ws, choice);
        //personalPhoneNumbers.push_back(choice);
        insert(contacts.back(),choice);
        std::cout<<"Their work email ID : (enter NA if not applicable)"<<std::endl;
        std::getline(std::cin>>std::ws, choice);
        //workEmails.push_back(choice);
        insert(contacts.back(),choice);
        std::cout<<"Their personal email ID : (enter NA if not applicable)"<<std::endl;
        std::getline(std::cin>>std::ws, choice);
        //personalEmails.push_back(choice);
        insert(contacts.back(),choice);
        length++;
        merged = false;
        std::cout<<"The contact has been successfully added to the contacts list.\nEnter (A) to add another contact, (D) to display a particular contact, (L) to see the contacts list or (Q) to quit"<<std::endl;
        std::getline(std::cin>>std::ws, choice);
        HandleChoice(choice);
    }

    void ShowList(){
        if (length==0){
            std::cout<<"The contacts list is empty. Please add contacts to the list to display here."<<std::endl;
            std::cout<<"Enter (A) to add contacts or (Q) to quit"<<std::endl;
            std::getline(std::cin>>std::ws,choice);
            HandleChoice(choice);
        }
        else {
            std::cout<<"Displaying the contacts list in the following order : Contact Name, Title, Work Phone Number, Personal Phone Number, Work Email and Personal Email "<<std::endl;
            std::cout<<"==================================================================================================================================================="<<std::endl;
            
            for (int i=0;i<length;i++){
                List* temp1 = contacts[i];
                while (temp1!=NULL) {
                    std::cout<<temp1->val<<" ";
                    temp1 = temp1->next;
                }
                std::cout<<std::endl;
                std::cout<<"--------------------------------------------------------------------------------------------------------------"<<std::endl;
                
            }
            //std::cout<<"--------------------------------------------------------------------------------------------------------------"<<std::endl;
            std::cout<<"Enter (A) to add contacts, (D) to display a particular contact or (Q) to quit"<<std::endl;
            std::getline(std::cin>>std::ws,choice);
            HandleChoice(choice);
        }
    }

    void Display(){
        while (true){
            if (view=="quit") {
                std::cout<<"Closing the contacts list..."<<std::endl;
                break;
            }
            else if (view=="list"){
                ShowList();
            }
            else if (view=="add"){
                AddInfo();
            }
            else if (view=="select"){
                DisplayInfo();
            }
        }
    }

    private:
    string view;
    vector<List*> contacts;
    string choice;
    int index;
    int length;
    bool merged;
    void HandleChoice(string c){
        if (c=="a"||c=="A") view = "add";
        else if (c=="q"||c=="Q") view ="quit";
        else if ((c=="l"||c=="L")&&view!="list") view = "list";
        else if ((c=="d"||c=="D")&&length!=0) view = "select";
        else {
            std::cout<<"You have entered an invalid option, try again"<<std::endl;
            view = "list";
        }
    }
    string toLower(string c){
        int n = c.length();
        for (int i=0;i<n;i++) {
            if (c[i]>='A'&&c[i]<='Z') c[i] = c[i] + 'a' - 'A';
        }
        return c;
    }
    int binarySearch(string target,vector<List*> names, int start, int end){
        
        while (start<=end){
            int mid = (start+end)/2;
            if (target==names[mid]->val) return mid;
            else if (target<names[mid]->val) end = mid-1;
            else start = mid+1;
        }
        return -1;
    }

    vector<List*> merge(vector<List*> numsL, vector<List*> numsR){
        vector<List*> answer;
        int nL = numsL.size();
        int nR = numsR.size();
        int i = 0;
        int j = 0;
        while (i<nL&&j<nR){
            if (numsL[i]->val<=numsR[j]->val) answer.push_back(numsL[i++]);
            else answer.push_back(numsR[j++]);
        }
        while (i<nL) answer.push_back(numsL[i++]);
        while (j<nR) answer.push_back(numsR[j++]);
        return answer;
    }

    void mergeSort(vector<List*>& contacts){
        int n = contacts.size();
        if (n<=1) return;
        int mid = (n-1)/2;
        vector<List*> contactsL;
        vector<List*> contactsR;
        for (int i=0;i<=mid;i++) contactsL.push_back(contacts[i]);
        for (int i=mid+1;i<n;i++) contactsR.push_back(contacts[i]);
        mergeSort(contactsL);
        mergeSort(contactsR);
        contacts = merge(contactsL,contactsR);
    }

};

int main(){
    Contacts c;
    c.Display();
    return 0;
}