#include<stdio.h>

int main() {
	 int n,i,j;
	 scanf("%d",&n);
	 int arr[n];
	 int sum=0;
	 int counter=0;
	 for(int i=0;i<n;i++){
		 scanf("%d",&arr[i]);
		 sum+=arr[i];
	 }
	 sum=sum/2;
	 for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]<arr[j])
            {
                arr[i]=arr[i]^arr[j];
                arr[j]=arr[i]^arr[j];
                arr[i]=arr[i]^arr[j];
            }
        }
    }
	 int sum2=0;
	 for(i=n-1;i>=0;i--){
		 sum2+=arr[i];
		 ++counter;
		if(sum2>sum){
		 	break;
		}


	 }

	 printf("%d\n",counter);






	return 0;
}