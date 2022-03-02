#include<bits/stdc++.h>

using namespace std;
class Student{
    public:
    int id;
    string name;
    double cgpa;

    Student(string name, double cgpa, int id){
        this->name = name;
        this->id= id;
        this->cgpa= cgpa;
        
    }

};
struct comparator
{
    bool operator()(Student a, Student b){
        if(a.cgpa==b.cgpa) 
        {
            if(a.name== b.name){
                return a.id<b.id;

            }
            else if(a.name>b.name) return 0;
            else return 1;
        }
        else if(a.cgpa>b.cgpa)return 0;
        else return 1;
    }
};

int main()
{
    priority_queue<Student, vector<Student>, comparator> pq;
    int n, k;
    cin>>n;
    while(n--){
        string s; double cgpa; int id;
        cin>>s>>cgpa>>id;
        pq.push(Student(s, cgpa, id));
    }
    cout<<pq.top().name<<endl;
    pq.pop();
    cout<<pq.top().name<<endl;
    return 0;
}