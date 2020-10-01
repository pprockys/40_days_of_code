                      >> DSU
                      
        >>> Resources:
        
            Tutorial: https://cp-algorithms.com/data_structures/disjoint_set_union.html
            Visualization: https://visualgo.net/en/ufds?slide=1 
        
        
        >>> Implementation:
        
            ll pt[N];
            ll sz[N];
            
            
            void ms(ll v) 
            {
                pt[v]=v;
                sz[v]=1;
            }
            
            
            ll fs(ll v) 
            {
                if (v==pt[v])
                {
                    return v;
                }
                else
                {
                    return pt[v]=fs(pt[v]);
                }
            }
            
            
            void us(ll a,ll b) 
            {
                a=fs(a);
                b=fs(b);
                if (a!=b) 
                {
                    if(sz[a]<sz[b])
                    {
                        swap(a,b);
                    }
                    pt[b]=a;
                    sz[a]+=sz[b];
                }
            }

        >>> Problems:
        
            Problem-1:https://codeforces.com/contest/755/problem/C
            Solution:https://codeforces.com/contest/755/submission/77866463
              
            Problem-2:https://codeforces.com/contest/977/problem/E
            Solution:https://codeforces.com/contest/977/submission/78635965
            
            Problem-3:https://codeforces.com/contest/1253/problem/D
            Solution :https://codeforces.com/contest/1253/submission/88730524

  
