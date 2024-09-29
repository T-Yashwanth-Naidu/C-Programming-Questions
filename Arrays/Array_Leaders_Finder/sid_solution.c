#include <stdio.h>
int arrayLeaderfinder(int* a,int l)
{
    int greatest;
    for(int i=0;i<l;i++)
    {
        if(a[i]>a[i+1])
        {
            greatest = a[i];
        }
    }
    return greatest;

}

void main()
{
    int arr1[] = {2,6,1,4,5};
    int len = sizeof(arr1)/sizeof(arr1[0]);
    printf("The greatest number in the array is %d ",arrayLeaderfinder(arr1,len));
}

