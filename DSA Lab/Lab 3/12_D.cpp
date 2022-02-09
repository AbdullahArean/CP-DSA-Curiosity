//12
#include <bits/stdc++.h>
using namespace std;
map<string, int> container;
struct employee
{
    string name, dept, des;

} arr[100013];
bool compfun(employee a, employee b)
{
    if (a.dept == b.dept)
    {
        if (a.des == b.des)
        {
            return a.name < b.name;
        }
        else
        {

            return container[a.des] < container[b.des];
        }
    }
    return a.dept < b.dept;
}
int main()
{
    int n;
    cin >> n;
    container["MD"] = 1;
    container["GM"] = 2;
   container["DGM"] = 3;
    container["AGM"] = 4;
   container["ENGR"] = 5;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].name >> arr[i].dept >> arr[i].des;
    }
    sort(arr, arr + n, compfun);
    for (int i = 0; i < n; i++)
    {
        cout <<arr[i].name << " " << arr[i].dept << " " << arr[i].des << endl;
    }
}