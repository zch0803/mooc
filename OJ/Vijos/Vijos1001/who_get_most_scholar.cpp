#include<iostream>
using namespace std;

struct Student{
    string name;
    int average_score;
    int class_score;
    char is_leader;
    char is_western;
    int paper_num;
    int scholar;
};

int main(){
    Student stu[200];
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> stu[i].name >> stu[i].average_score >> stu[i].class_score >> stu[i].is_leader >> stu[i].is_western >> stu[i].paper_num;
        stu[i].scholar = 0;
        if(stu[i].average_score > 80 && stu[i].paper_num > 0)
            stu[i].scholar += 8000;
        if(stu[i].average_score > 85 && stu[i].class_score > 80)
            stu[i].scholar += 4000;
        if(stu[i].average_score > 90)
            stu[i].scholar += 2000;
        if(stu[i].average_score > 85 && stu[i].is_western == 'Y')
            stu[i].scholar += 1000;
        if(stu[i].class_score > 80 && stu[i].is_leader == 'Y')
            stu[i].scholar += 850;
    }
    int sum_scholar = 0;
    int max_index = -1;
    int max = -1;
    for (int i=0; i<n; i++){
        if (stu[i].scholar > max){
            max_index = i;
            max = stu[i].scholar;
        }
        sum_scholar += stu[i].scholar;
    }
    cout << stu[max_index].name << endl;
    cout << stu[max_index].scholar << endl;
    cout << sum_scholar << endl;
    return 0;
}
