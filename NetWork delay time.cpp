//Djilstra's Algo
class Solution {
typedef pair<int, int> pi;
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      vector<int > cost (n+1,INT_MAX) ;
      cost[k] =  0 ;
        
        vector<pi> adj[n+1] ;
        int u, v , w ;
        for(int i =0 ; i < times.size() ; i++)
        {
             u = times[i][0] ;
             v = times[i][1] ;
            w = times[i][2] ;
            adj[u].push_back({v ,w}) ;
        }
         priority_queue<pi, vector<pi>, greater<pi> > pq;
        
        pq.push({k, cost[k]}) ;
        
        while(!pq.empty())
        {
            u = pq.top().first;
            pq.pop() ;
          for(auto it : adj[u])
            {
                 v = it.first ;
                 w = it.second ;
              if( cost[v] > w + cost[u] )
              {
                   cost[v] = w + cost[u] ;
                  pq.push({v ,cost[v]}) ;
              }
            }
        }
        
    int ans = 0;
        for(int i=1;i<cost.size();i++){
            cout<<"Cost to Node"<<i<<" "<<cost[i]<<endl;
            ans = max(ans, cost[i]);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};