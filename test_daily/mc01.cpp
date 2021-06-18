/*

面向对象编程 实验五
设计一个保存员工类（包括职工号、姓名、年龄、工资）对象的容器，编程实现以下功能：
（1） 从键盘输入5个员工对象，保存在容器中（一开始未排序）；
（2） 从键盘输入两个新员工对象（注意，职工号顺序是打乱的），插入到容器的末尾，输出全部员工的数据；
（3） 利用泛型算法sort按照职工号顺序重新排序，输出全部员工的数据。
（4） 给定一个职工号，在文件中查找有无此职工号，如有则显示此员工的全部数据。如没有，就输出“无此人”。（此问不做要求，大家可以选做）

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Stuff {
    int no;
    string name;
    int age;
    int salary;
};

struct cmp{
        bool operator()(Stuff& a,  Stuff& b) {
            return a.no < b.no; 
        }
    };

int main(){
    int N = 5;
    vector<Stuff> vc;
    while( N--) {
        Stuff stuff;
        cin >> stuff.no >> stuff.name >> stuff.age >> stuff.salary;
        vc.push_back(stuff);
    }
    for (int i = 0; i < vc.size(); i++) {
        cout << vc[i].no<< " " << vc[i].name << " " << vc[i].age << " " << vc[i].salary << endl;
    }
    int add = 2;
    while( add--) {
        Stuff stuff;
        cin >> stuff.no >> stuff.name >> stuff.age >> stuff.salary;
        vc.push_back(stuff);
    }
    sort(vc.begin(), vc.end(), cmp());
    for (int i = 0; i < vc.size(); i++) {
        cout << vc[i].no<< " " << vc[i].name << " " << vc[i].age << " " << vc[i].salary << endl;
    }
    return 0;
}