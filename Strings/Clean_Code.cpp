#include<bits/stdc++.h>
using namespace std;
void addtabs(string& a,int tabs)
{
    if(tabs == 0)
        return;
    reverse(a.begin(),a.end());
    for(int i=1;i<=tabs;i++)
        a += "\t";
    reverse(a.begin(),a.end());
}
void addspaces(string& a,int spaces)
{
    if(spaces == 0)
        return;
    reverse(a.begin(),a.end());
    for(int i=1;i<=spaces;i++)
        a += " ";
    reverse(a.begin(),a.end());
}
int main()  {
    ios::sync_with_stdio(false);
    int number_of_lines;
    cin >> number_of_lines;
    vector<string> v;
    string readLine;
    getline(cin,readLine);
    while(number_of_lines--){
        getline(cin,readLine);
        int len = readLine.length();
        if(!len)
            continue;
        v.push_back(readLine);
    }
    int si = v.size();
    bool multi_line_flag = false;
    
    for(int i=0;i<si;i++){
        string x = v[i];
        int count_tabs = 0;
        int count_spaces = 0;
        if(multi_line_flag) {
            int ends_at = 0;
            for(int i=0;i<x.size();i++){
                if(i + 1 < x.size() && x[i] == '*' && x[i + 1] == '/'){
                    multi_line_flag = false;
                    ends_at = i + 1;
                    break;
                }
            }
            if(!multi_line_flag){
                string a = "";
                for(int i=ends_at;i<x.size();i++)
                    a += x[i];
                reverse(a.begin(),a.end());
                while(a.back() == ' ' || a.back() == '\t'){
                    if(a.back() == '\t') count_tabs++;
                    else if(a.back() == ' ') count_spaces++;
                    a.pop_back();
                }
                reverse(a.begin(),a.end());
                if(a.size() > 0){
                    addtabs(a,count_tabs);
                    addspaces(a,count_spaces);
                    cout << a;
                    if(i < si - 1)
                        cout << '\n';
                }
            }
        }
        else{
            string a = "";
            int ends_at = 0;
            for(int i=0;i<x.size();){
                if(i + 1 < x.size() && x[i] == '/' && x[i + 1] == '/')
                    break;
                if(i + 1 < x.size() && x[i] == '/' && x[i + 1] == '*'){
                    multi_line_flag = true;
                    ends_at = i + 1;
                }
                if(multi_line_flag){
                    for(int j=ends_at + 1;j<x.size();j++){
                        if(j + 1 < x.size() && x[j] == '*' && x[j + 1] == '/'){
                            multi_line_flag = false;
                            i = j + 2;
                            break;
                        }
                    }
                }
                else{
                    a += x[i];
                    i++;
                }
            }
            if(!multi_line_flag){
                int count_tabs = 0;
                int count_spaces = 0;
                reverse(a.begin(),a.end());
                while(a.back() == '\t' || a.back() == ' '){
                        if(a.back() == '\t') count_tabs++;
                        else if(a.back() == ' ') count_spaces++;
                        a.pop_back();
                }
                reverse(a.begin(),a.end());
                if(a.size() > 0){
                    addtabs(a,count_tabs);
                    addspaces(a,count_spaces);
                    cout << a;
                    if(i < si - 1)
                        cout << '\n';
                }
            }
        }
    }
    
    return 0;
}