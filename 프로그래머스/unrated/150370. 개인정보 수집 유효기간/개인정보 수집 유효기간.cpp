#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char, int> um;
    
    istringstream iss(today);
    string ityear;
    string itmonth;
    string itday;
    getline(iss, ityear, '.');
    getline(iss, itmonth, '.');
    getline(iss, itday, '.');
    int tyear = stoi(ityear);
    int tmonth = stoi(itmonth);
    int tday = stoi(itday);
    
    int tdays = tyear * 12 * 28 +  tmonth * 28 + tday;
    
    for (auto& t : terms) {
        stringstream ss(t);
        char yk;
        int deadline;
        ss >> yk >> deadline;
        um[yk] = deadline;
    }
    
    int cnt = 0;
    for (auto& p : privacies) {
        cnt++;
        stringstream ss(p);
        string str;
        char yk;
        ss >> str >> yk;
        
        istringstream iss(str);
        string iyear;
        string imonth;
        string iday;
        getline(iss, iyear, '.');
        getline(iss, imonth, '.');
        getline(iss, iday, '.');
	    int year = stoi(iyear);
    	int month = stoi(imonth);
    	int day = stoi(iday);
        
        int days = year * 12 * 28 +  month * 28 + day;
        
        days += um[yk] * 28 - 1;
        
        if (tdays <= days) continue;
        
        answer.emplace_back(cnt);
    }
    
    return answer;
}