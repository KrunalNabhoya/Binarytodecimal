#include<stdio.h>
#include<math.h>

int checkbinary(char str[])
{
	int f=0;
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]!='1')
		{
			if(str[i]!='0')
			{
				if(f==0)
				{		
					if(str[i]!='.')
					{
						return 1;
					}
					else
					{
						f=1;
					}
				}
				else
				{
					return 1;
				}
			}
		}
	}
	return 0;
	
}

int main()
{
	char str[50]; 
	int f=0,v1=0,v2=0,c=0,t;
	float ans;
	
	printf("\nEnter Binary Number:-");
	gets(str);
	
	if(checkbinary(str))
	{
		printf("Your Binary Number Is Not Valid!\n");
		return 0;
	}

	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]!='.')
		{
			if(f!=1)
			{
				v1=v1*10;
				v1=v1+(int)str[i]-48;
			}
			else
			{
				v2=v2*10;
				v2=v2+(int)str[i]-48;
			}
		}
		else{
			f=1;
		}
	}
	
	while(v1>0)
	{
		t=v1%10;
		ans=ans+t*pow(2,c);	
		c+=1;
		v1=v1/10;
	}
	
	
	int tv=v2;
	v2=0;
	while(tv>0)
	{
		t=tv%10;
		v2=t+(v2*10);
		tv=tv/10;
		if(tv==0)
		{
			v2*=10;
		}
	}
	
	c=-1;
	while(v2>0)
	{
		t=v2%10;
		ans=ans+t*pow(2,c);
		
		c-=1;
		v2=v2/10;
	}
	
	printf("\nDecimal Number of (%s) Is (%f)\n",str,ans);
	
	
return 0;
}