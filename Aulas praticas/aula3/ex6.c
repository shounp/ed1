#include <stdio.h>

long long exponencial(long long x,long long n){
	if (n==0)
		return 1;
	long long soupow = exponencial(x,n/2);
	if (n%2==1)
		return x*soupow*soupow;
	else
		return soupow*soupow;

}

int main(){
	long long a=3,c=4;
	printf("%lld\n",exponencial(a,c));
	return 0;
}