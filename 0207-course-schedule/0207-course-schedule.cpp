class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>integ(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int course=prerequisites[i][0];
            int prereq=prerequisites[i][1];
            adj[prereq].push_back(course);
            integ[course]++;
        }
        queue<int>q;
        int complete=0;
        for(int i=0;i<numCourses;i++){
            if(integ[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            complete++;
            for(int i=0;i<adj[curr].size();i++){
                int next=adj[curr][i];
                integ[next]--;
                if(integ[next]==0){
                    q.push(next);
                }
            }
        }
        return complete==numCourses;
        
    }
};