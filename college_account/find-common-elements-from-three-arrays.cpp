vector<int> joinTwoSortedVectors(vector<int> vector1, vector<int> vector2)
{
           vector<int> result;

           vector<int>::iterator i=vector1.begin(), j=vector2.begin();

           /*
            The C++ function std::vector::end() returns an iterator which
            points to past-the-end element in the vector container.
           */

           while(i!=vector1.end() && j!=vector2.end())
            {
               if(*i<=*j) // include equality condition in one of the conditional cases
                {
                   result.push_back(*i);
                   ++i;
                }

               else
                {
                   result.push_back(*j);
                   ++j;
                }
            }

           if(i!=vector1.end() && j==vector2.end())
            {
               vector<int>::iterator k; //can you remove k?

               for(k=i;k!=vector1.end();k++)
                    result.push_back(*k);
            }

           else if(i==vector1.end() && j!=vector2.end())
            {
               vector<int>::iterator k;

               for(k=j;k!=vector2.end();k++)
                    result.push_back(*k);
            }

           return result;
}

vector<int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
            vector<int> result;

            vector<int> vecA, vecB, vecC;

            set<int> setResult;

            set<int> setA, setB, setC;

            int i;

            /*
             Using set to remove duplicate elements from the individual vectors
             that may contain a sequence of duplicate terms which lead
             to incorrect results during the checking the combined vector.

             Check this out:
             https://chat.openai.com/share/a6cb8e1d-8ea0-46dc-8e3d-67ab49075825
            */

            for(i=0;i<n1;i++)
                setA.insert(A[i]);

            for(i=0;i<n2;i++)
                setB.insert(B[i]);

            for(i=0;i<n3;i++)
                setC.insert(C[i]);

            // copying the data of sets into the separate vectors

            set<int>::iterator itrs;

            for(itrs=setA.begin();itrs!=setA.end();itrs++)
                vecA.push_back(*itrs);

            for(itrs=setB.begin();itrs!=setB.end();itrs++)
                vecB.push_back(*itrs);

            for(itrs=setC.begin();itrs!=setC.end();itrs++)
                vecC.push_back(*itrs);

            vector<int> vecAB, vecABC;

            vecAB=joinTwoSortedVectors(vecA,vecB);
            vecABC=joinTwoSortedVectors(vecAB,vecC); // final combined vector

            vector<int>::iterator itrv;

            itrv=vecABC.begin();

            while( (itrv+1)!=vecABC.end() && (itrv+2)!=vecABC.end() )
            /*
             I was stuck in debugging this part of the code, the issue is a pretty basic concept:

             In the while loop condition, I was checking if the second location starting from the location
             being pointed to by the vector iterator was that of the end of the vector. This was the bug.
             This is because the end of the vector comes right after the last element of the vector. So it
             is the location that comes first, right after the last element of the vector. Locations beyond
             that, like the second location after the last element of the vector, are not locations that
             belong to the vector. Hence, the segmentation fault.
            */
            {
                if(*itrv==*(itrv+1) && *itrv==*(itrv+2))
                {
                    setResult.insert(*itrv);
                    itrv+=2;
               }

                else
                {
                    itrv++;
                }
            }

            if(setResult.empty())
                result.push_back(-1);
                //output in case of no common elements is -1

            else
            {
                set<int>::iterator itr;

                for(itr=setResult.begin();itr!=setResult.end();itr++)
                    result.push_back(*itr);
            }

            return result;
}
