/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int dfs(vector<Employee*> employees,int id,unordered_map<int,bool>& vis){
        vis[id]=1;
        int sum=0;
        for(int i=0;i<employees.size();i++){
            if(employees[i]->id==id){
                sum+=employees[i]->importance;
                vector<int>v=employees[i]->subordinates;
                for(int j=0;j<v.size();j++){
                    if(!vis[v[j]]) sum+=dfs(employees,v[j],vis);
                }
            }
        }
        return sum;
    }
    int getImportance(vector<Employee*> employees, int id) {
        int sum=0;
        for(int i=0;i<employees.size();i++){
            if(employees[i]->id==id){
                sum+=employees[i]->importance;
                vector<int>v=employees[i]->subordinates;
                unordered_map<int,bool>vis;
                for(int j=0;j<v.size();j++){
                    if(!vis[v[j]]) sum+=dfs(employees,v[j],vis);
                }
            }
        }
       return sum; 
    
    }
};