#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool isdiagonal(int x, int y, int p , int q)
{
     if( x == p)
	  return false;
	 else if(y == q)
	   return false;
	   else;
	    return true;
}

int main()
{
	int r,c,k=1,p1=0,p2=0,x,y,p,q,from,to,flag,flag2,a,b,pl=1,dots,turn;
	bool diag;
	cout<<"Enter Row and Column:";
	cin>>r>>c;
	dots = ((r-1)*c) + ((c-1)*r);
	r = r + ( r- 1);
	c = c + ( c - 1);
	//cout<<r<<"      "<<c<<endl;
	int mat[r][c];
	
	for(int i = 1;i<=r;i++)// initializing space
	{
		 for(int j = 1;j<=c;j++)
		  mat[i][j] = ' ';
	}
	
	for(int i = 1;i<=r;i=i+2)// initilizing dots as numbers
	{
		for(int j = 1 ;j<=c;j=j+2)
		{
			mat[i][j] = k;
			k++;
		}
	}
	

	for(int i = 1;i<=r;i++)// initializing matrix
	{
		for(int j = 1 ;j<=c;j++)
		{
	         if(mat[i][j] >= 1 && mat[i][j] <= 9)
	          cout<<mat[i][j];
	          else
	          printf("%c",mat[i][j]);
		}
		cout<<endl;
	}
	
	
	
	
  for(int it= 1;it<=dots;it++) 
  {
  	top:
  		turn = 0;
     if( pl == 1)
     cout<<"enter the input for player "<<pl<<":";
     else
     {
	 
     cout<<"enter the input for player "<<pl<<":";
      
      }
	cin>>from;
	cin>>to;
		diag = false;
/*....... finding points index..........*/	
	for(int i = 1;i<=r;i=i+2)
	{
		flag = 0;
		for(int j = 1 ;j<=c;j=j+2)
		{
			if( mat[i][j] == from)
			{
				x = i;
				y = j;
				flag = 1;
				break;
			}
		}
	}
	
	
	for(int i = 1;i<=r;i=i+2)
	{
		flag2 = 0;
		for(int j = 1 ;j<=c;j=j+2)
		{
			if( mat[i][j] == to)
			{
				p = i;
				q = j;
				flag2 = 1;
				break;
			}
		}
	}


/////*checking for diagonal**...........///	
	diag = isdiagonal(x,y,p,q);
	
	if( diag == false)
	{
		
		if( x == p)
		{
			  if( q > y)
			  {
			  mat[x][y+1] = '-';
			   a=x;
			   b = y+1;
		       }
			  else
			  {
			   mat[x][y-1] = '-';
			   a = x;
			   b = y+1;
		      }
		}
		else if( y == q)
		{
			if( p>x)
			{
			mat[x+1][y] = '|';
			a = x+1;
			b=y;
	     	}
		 	else
		 	{
			mat[x-1][y] = '|';
			 a = x-1;
			 b = y;
		    }
		}		
	}
	else
	 {
	 	cout<<"******There is no path between thes two points....enter again\n*******";
	 	goto top;
	 }
	 
	/*--- check for box closure-----*/
		if(mat[a][b] == '-')
		{
			 if(mat[a-2][b] == '-' && mat[a-1][b-1] == '|' && mat[a-1][b+1] == '|')
			 {
			 	if(pl == 1)
			 	{
			      mat[a-1][b] = 'A';
			 	 p1++;
			     }
			 	 else
			 	 {
			 	 mat[a-1][b] = 'B';
			 	 	 p2++;
			     }
			     if(pl == 1)
			     turn = 1;
			     else
			     turn = 2;
			 }
			 if( mat[a+2][b] == '-' && mat[a+1][b-1] == '|' && mat[a+1][b+1] == '|')
		    {
		    	if(pl == 1)
			 	{
			      mat[a+1][b] = 'A';
			 	 p1++;
			     }
			 	 else
			 	 {
			 	 mat[a+1][b] = 'B';
			 	 	 p2++;
			     }
			     if(pl == 1)
			     turn = 1;
			     else
			     turn  = 2;
			}
		}
		else if( mat[a][b] == '|')
		{
			  if( mat[a][b-2] == '|' && mat[a-1][b-1] == '-' && mat[a+1][b-1] == '-')
			  {
			  	 if(pl == 1)
			 	{
			      mat[a][b-1] = 'A';
			 	 p1++;
			     }
			 	 else
			 	 {
			 	 mat[a][b-1] = 'B';
			 	 	 p2++;
			     }
			     if(pl == 1)
			     turn = 1;
			     else
			     turn = 2;
			    
			  }
			  if(mat[a][b+2] == '|' && mat[a-1][b+1] == '-' && mat[a+1][b+1] == '-' )
			  {
			  	  if(pl == 1)
			 	{
			      mat[a][b+1] = 'A';
			 	 p1++;
			     }
			 	 else
			 	 {
			 	 mat[a][b+1] = 'B';
			 	 	 p2++;
			     }
			     if(pl == 1)
			     turn = 1;
			     else
			     turn = 2;
			  }
		}
		if(turn != 0)
		{
			pl = turn;
		}
		else
		{
		
		if(pl == 1)
		  pl=2;
		  else if(pl == 2)
		   pl = 1;
	   }
	
	
	for(int ii= 1;ii<=r;ii++)
	{
		for(int jj = 1 ;jj<=c;jj++)
		{
	         if(mat[ii][jj] >= 1 && mat[ii][jj] <= 9)
	          cout<<mat[ii][jj];
	          else
	          printf("%c",mat[ii][jj]);
		}
		cout<<endl;
	}
}


	cout<<endl;
	if(p1 == p2)
	cout<<"Game tied";
	else if(p1 > p2)
	cout<<"Player 1 is won";
	else
	cout<<"player 2 is won";
	
}
