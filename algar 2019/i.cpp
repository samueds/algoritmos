#include <bits/stdc++.h>

using namespace std;

unsigned long long a,b,c,d;

int main()
{

	while(~scanf("%d%d%d%d",&a,&b,&c,&d))
	{

	    unsigned long long dig = c / d; 
	  
	    bool first = false; bool second = false;
	    if(c % d == 0)
	    {
	    	if(a == 0) first = true;
	    	if(b == 0) second = true;
	    }
	    else
	    {
	    	for (int i = 0; i < 1000 ; i++)
		    { 
		        c = c - (dig * d); 
		        if (c == 0) 
		            break; 
		        c = c * 10; 
		        dig = c / d; 
		        
		       	if(dig == a)
		       	{
		       		first = true;
		       		break;
		       	}
		       	if(dig == b)
		       	{
		       		second = true;
		       		break;
		       	}
		    }
	    }
	    
	    if((first && (a == b)) || (second && (a == b)))
	    	printf("Empate\n");
	    else if(first) printf("Reluew\n");
	    else if(second) printf("Ovatsug\n");
	    else printf("Empate\n");
	}


	return 0;
}