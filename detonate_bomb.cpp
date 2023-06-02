#define ll long long 
class Solution {
public:
    int mx=0;
    void bfs(vector<int>v[],int n){
        for(int i=0;i<n;i++){
               queue<int> q;
               vector<int> vis(n);
               q.push(i);
               vis[i]=1;
               int ans(1);
               while(!q.empty()){
                   int x=q.front();
                   q.pop();
                   for(auto&it:v[x]){
                       if(vis[it]) continue;
                       q.push(it);
                       vis[it]=1;
                       ans++;
                   }
               }
               mx=max(mx,ans);
           }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        
        vector<int> v[n];
        for(int i=0;i<n;i++){
            ll x1=bombs[i][0];
            ll y1=bombs[i][1];
            ll r1=bombs[i][2];
            for(int j=i+1;j<n;j++){
            ll x2=bombs[j][0];
            ll y2=bombs[j][1];
            ll z=(x2-x1)*(x2-x1) + (y2-y1)*(y2-y1),p=r1*r1;
            if(z<=p) v[i].push_back(j);
            }
            for(int j=i-1;j>=0;j--){
            ll x2=bombs[j][0];
            ll y2=bombs[j][1];
            ll z=(x2-x1)*(x2-x1) + (y2-y1)*(y2-y1),p=r1*r1;
            if(z<=p) v[i].push_back(j);
            }
        }
        bfs(v,n);
        return mx;
    }
};