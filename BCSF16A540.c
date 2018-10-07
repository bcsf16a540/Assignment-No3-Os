#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
int array[1000];
for(int i=0;i<1000;i++){
	array[i]=i+1;
}
int n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;
int s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,sum;
s1=s2=s3=s4=s5=s6=s7=s8=s9=s10=0;
int fd[10][2];
int val=0;
//creating pipe for getting values from the Child Processes:
for(int i=0;i<10;i++)
	pipe(fd[i]);
	
	n1=fork();
	n2=fork();
	n3=fork();
	n4=fork();
	n5=fork();
	n6=fork();
	n7=fork();
	n8=fork();
	n9=fork();
	n10=fork();
if(n1==0 && n2!=0 && n3!=0 && n4!=0 && n5!=0&& n6!=0 && n7!=0 && n8!=0&& n9!=0 && n10!=0)
{
 // writing only, no need for read-descriptor:
        close(fd[0][0]);
	for(int i=0;i<100;i++)
	s1+=array[i];
 // send the value on the write-descriptor:
        write(fd[0][1], &s1, sizeof(s1)); 
        // close the write descriptor:
        close(fd[0][1]);
}
else if(n1!=0 && n2==0 && n3!=0 && n4!=0 && n5!=0&& n6!=0 && n7!=0 && n8!=0&& n9!=0 && n10!=0)
{
 // writing only, no need for read-descriptor:
        close(fd[1][0]);
	for(int i=100;i<200;i++)
	s2+=array[i];
 // send the value on the write-descriptor:
        write(fd[1][1], &s2, sizeof(s2)); 
        // close the write descriptor:
        close(fd[1][1]);
}
else if(n1!=0 && n2!=0 && n3==0 && n4!=0 && n5!=0&& n6!=0 && n7!=0 && n8!=0&& n9!=0 && n10!=0)
{
 // writing only, no need for read-descriptor:
        close(fd[2][0]);
	for(int i=200;i<300;i++)
	s3+=array[i];
 // send the value on the write-descriptor:
        write(fd[2][1], &s3, sizeof(s3)); 
        // close the write descriptor:
        close(fd[2][1]);
}
else if(n1!=0 && n2!=0 && n3!=0 && n4==0 && n5!=0&& n6!=0 && n7!=0 && n8!=0&& n9!=0 && n10!=0)
{
 // writing only, no need for read-descriptor:
        close(fd[3][0]);
	for(int i=300;i<400;i++)
	s4+=array[i];
 // send the value on the write-descriptor:
        write(fd[3][1], &s4, sizeof(s4)); 
        // close the write descriptor:
        close(fd[3][1]);
}
else if(n1!=0 && n2!=0 && n3!=0 && n4!=0 && n5==0&& n6!=0 && n7!=0 && n8!=0&& n9!=0 && n10!=0)
{
 // writing only, no need for read-descriptor:
        close(fd[4][0]);
	for(int i=400;i<500;i++)
	s5+=array[i];
 // send the value on the write-descriptor:
        write(fd[4][1], &s5, sizeof(s5)); 
        // close the write descriptor:
        close(fd[4][1]);
}
else if(n1!=0 && n2!=0 && n3!=0 && n4!=0 && n5!=0&& n6==0 && n7!=0 && n8!=0&& n9!=0 && n10!=0)
{
 // writing only, no need for read-descriptor:
        close(fd[5][0]);
	for(int i=500;i<600;i++)
	s6+=array[i];
 // send the value on the write-descriptor:
        write(fd[5][1], &s6, sizeof(s6)); 
        // close the write descriptor:
        close(fd[5][1]);
}
else if(n1!=0 && n2!=0 && n3!=0 && n4!=0 && n5!=0&& n6!=0 && n7==0 && n8!=0&& n9!=0 && n10!=0)
{
 // writing only, no need for read-descriptor:
        close(fd[6][0]);
	for(int i=600;i<700;i++)
	s7+=array[i];
 // send the value on the write-descriptor:
        write(fd[6][1], &s7, sizeof(s7)); 
        // close the write descriptor:
        close(fd[6][1]);
}
else if(n1!=0 && n2!=0 && n3!=0 && n4!=0 && n5!=0&& n6!=0 && n7!=0 && n8==0&& n9!=0 && n10!=0)
{
 // writing only, no need for read-descriptor:
        close(fd[7][0]);
	for(int i=700;i<800;i++)
	s8+=array[i];
 // send the value on the write-descriptor:
        write(fd[7][1], &s8, sizeof(s8)); 
        // close the write descriptor:
        close(fd[7][1]);
}
else if(n1!=0 && n2!=0 && n3!=0 && n4!=0 && n5!=0&& n6!=0 && n7!=0 && n8!=0&& n9==0 && n10!=0)
{
 // writing only, no need for read-descriptor:
        close(fd[8][0]);
	for(int i=800;i<900;i++)
	s9+=array[i];
 // send the value on the write-descriptor:
        write(fd[8][1], &s9, sizeof(s9)); 
        // close the write descriptor:
        close(fd[8][1]);
}
else if(n1!=0 && n2!=0 && n3!=0 && n4!=0 && n5!=0&& n6!=0 && n7!=0 && n8!=0&& n9!=0 && n10==0)
{
 // writing only, no need for read-descriptor:
        close(fd[9][0]);
	for(int i=900;i<1000;i++)
	s10+=array[i];
 // send the value on the write-descriptor:
        write(fd[9][1], &s10, sizeof(s10)); 
        // close the write descriptor:
        close(fd[9][1]);
}
else if(n1>0 && n2>0 && n3>0 && n4>0 && n5>0 && n6>0 && n7>0 && n8>0 && n9>0 && n10>0)
{
wait(NULL);
for(int i=0;i<10;i++)
{	
	close(fd[i][1]);
        // read the data (blocking operation)
        read(fd[i][0], &val, sizeof(val));
	sum+=val;
        // close the read-descriptor
        close(fd[i][0]);
}
	printf("The Sum of the Numbers 0 to 1000 is %d\n",sum);
}

return 0;
}
