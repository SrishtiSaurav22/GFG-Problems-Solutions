long long int factorial(int N)
    {
        long long int fct=1;
        int i=0;
        
        for(i=N;i>=1;i--)
            fct=fct*i;
            
        return fct;
    }
