#include<stdio.h>
int main()
{
    long long int jjj=0;
    for(int i=0; i<99999; i++)
    {
        for(int j=0; j<99999; j++)
        {
            for(int k=0; k<99999; k++) jjj++;
        }
        printf(".");
    }
    printf("completed");
}
