                    >> Binary exponentiation
        
        >>> Resources:
            
            T-1: https://cp-algorithms.com/algebra/binary-exp.html
        
        >>> Implementation:
        
            ll be(ll a,ll b)
            {
                ll ans=1;
                a%=M;
                while(b)
                {
                   if(b&1)
                   {
                       ans=(ans*a)%M;
                   }
                   a%=M;
                   a=(a*a)%M;
                   b/=2;
                }
                return ans;
            }

