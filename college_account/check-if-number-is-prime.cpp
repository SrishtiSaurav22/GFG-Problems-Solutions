int isPrime(int N)
    {
        if(N==1)
            return 0;
            
        int i;
        
        for(i=2;i<=sqrt(N);i++)
        {
            if(N%i==0)
                return 0;
        }
        
        return 1;
    }
    // For input=0, why is the output 1??
