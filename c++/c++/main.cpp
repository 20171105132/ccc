//
//  main.cpp
//  c++
//
//  Created by zhangyue on 18/6/27.
//  Copyright © 2018年 zhangyue. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;
class SKL
{
private:
    string name;
    int brith;
public:
    void student(string x,int y)
    {
        name=x;
        brith=y;
    }
    void student1()
    {
        cout<<name<<" "<<brith<<endl;
    }
    void jiao(string name_)
    {
        name=name_;
    }

};
int main()
{
    SKL S;
    string x;
    int y;
    string name_;
    cin>>x>>y;
    S.student( x,y);
    S.student1();
    cin>>name_;
    S.jiao(name_);
    S.student1();
    return 0;
}
