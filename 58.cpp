#include<iostream>
#include<string>
using namespace std;
struct free_throws
{
    std::string name;
    int made;
    int attempts;
    float percent;
};
void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & source);
int main()
{
    free_throws one={"Ifelse branch",13,14};
    free_throws two={"Andor Kno",13,14};
    free_throws three={"Min Max",10,16};
    free_throws four={"While Loop",5,9};
    free_throws five={"Long Long ",6,14};
    free_throws team={"Throwgoods",0,0};
    free_throws dup;

    set_pc(one);
    display(one);
    accumulate(team,one);
    display(team);
    accumulate(accumulate(team,three),four);
    display(team);

    dup=accumulate(team,five);
    cout<< "display team:\n";
    display(team);
    cout<< "display dup after assignment:\n";
    display(dup);
    set_pc(four);

    accumulate(dup,five) = four;
    cout<<"display dup after i11-advised assigned:\n";
    display(dup);
    return 0;
}
void display(const free_throws & ft)
{
    cout<< "Name: "<< ft.name << "\n";
    cout<< "Made: " << ft.made << "\t";
    cout<<"Attempts: "<<ft.attempts <<"\t";
    cout<<"Percent: "<<ft.percent << "\n";
}
void set_pc(free_throws & ft)
{
    if(ft.attempts !=0)
    {
        ft.percent =100.0f*float(ft.made)/float(ft.attempts);
    }
    else{
        ft.percent=0;
    }

}
free_throws & accumulate(free_throws & target ,const free_throws & source)
{
    target.attempts+=source.attempts;
    target.made+=source.made;
    set_pc(target);
    return target;
}