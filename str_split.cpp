#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> split(const string &s, const string &seperator){
    vector<string> result;
    typedef string::size_type string_size;
    string_size i = 0;
    while(i != s.size())
    {
        int flag = 0;
        while(i != s.size() && flag == 0)
        {
            flag = 1;
            for(string_size x = 0; x < seperator.size(); ++x)
            if(s[i] == seperator[x])
            {
                ++i;
                flag = 0;
                break;
            }
        }
        flag = 0;
        string_size j = i;
        while(j != s.size() && flag == 0)
        {
            for(string_size x = 0; x < seperator.size(); ++x)
            if(s[j] == seperator[x])
            {
                flag = 1;
                break;
            }
            if(flag == 0)
            ++j;
        }
        if(i != j)
        {
            result.push_back(s.substr(i, j-i));
            i = j;
        }
    }
    return result;
}
int main(int argc,char* argv[])
{
    string str = "sdvxs:dd";
    vector<string> v = split(str,":");
    vector<string> value = split(str , ":");
    for(vector<string>::size_type i = 0; i != value.size(); ++i)
    {
        std::cout << value[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}


