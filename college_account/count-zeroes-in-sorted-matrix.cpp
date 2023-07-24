int countZeros(vector<vector<int>>A)
	{
	    if(A.empty())
	        return 0;
	    
	    vector<vector<int>>::iterator itr;
	    int numZero=0;
	    
	    for(itr=A.begin();itr!=A.end();itr++)
	        numZero+=count(itr->begin(),itr->end(),0);
	    
	    return numZero;
	}
