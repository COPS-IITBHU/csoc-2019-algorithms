    #include<bits/stdc++.h>
    #define int long long
    using namespace std;
    //CALCULATING nCr mod prime
    int power(int x, unsigned int y, unsigned int m) 
        { 
            if (y == 0) 
                return 1; 
            int p = power(x, y/2, m) % m; 
            p = (p * p) % m; 
      
            return (y%2 == 0)? p : (x * p) % m; 
        } 
	int modInverse(int a, int m) 
	{   
    	return power(a, m-2, m);
	}
	int nCrModPFermat(int n, int r, int p) 
    { 
   		if (r==0) 
      		return 1; 
  
    	int fac[n+1]; 
	    fac[0] = 1; 
    	for (int i=1 ; i<=n; i++) 
        	fac[i] = fac[i-1]*i%p; 
  
    	return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
    } 
    signed main()
    {
    	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    	int n=0,r=0,p=0;
    	cin>>n>>r>>p;
    	//p is a prime here
    	cout<<nCrModPFermat(n,r,p);
    	return 0;
    }