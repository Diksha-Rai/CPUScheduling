#include<stdio.h>

int queue1[4][5],queue2[4][5],queue3[4][5],counter1=0,counter2=0,counter3=0,rrcount=0,pscount=0,fcfscount=0,rrc=0,fcfsc=0,psc=0;

void RR()
{
	if(rrc==rrcount)
	{
		return;
	}
	else
	{
	int avail=10,j;
	for(j=counter1;avail>0;j++)
	{
		if(queue1[3][j]==0)
		{
			//pass
			rrc++;
			
			printf("Process %d following Round Robin scheduling algorithm is completed(execution done)\n\n",(queue1[0][j]));
		}
		
		else if(queue1[3][j]<4)
		{
			if(avail<4)
			{
				if(queue1[3][j]<avail)
				{
					printf("Executing process %d having current burst time %d\n",(queue1[0][j]),queue1[3][j]);
					avail=avail-queue1[3][j];
					queue1[3][j]=0;
				}
				else
				{
					printf("Executing process %d having current burst time %d\n",(queue1[0][j]),queue1[3][j]);
					queue1[3][j]=queue1[3][j]-avail;
					printf("Now remaining burst time of process %d is %d\n\n",queue1[0][j],queue1[3][j]);
					avail=0;
				}
			}
			else
			{
				printf("Executing process %d \n",(queue1[0][j]));
				queue1[3][j]=0;
				avail=avail-queue1[3][j];
			}
		}
		else
		{
			if(avail<4)
			{
				printf("Executing process %d having current burst time %d\n",(queue1[0][j]),queue1[3][j]);
				queue1[3][j]=queue1[3][j]-avail;
				printf("Now remaining burst time of process %d is %d\n\n",queue1[0][j],queue1[3][j]);
				avail=0;
			}
			else
			{
				printf("Executing process %d having current burst time %d\n",(queue1[0][j]),queue1[3][j]);
				queue1[3][j]=queue1[3][j]-4;
				printf("Now remaining burst time of process %d is %d\n\n",queue1[0][j],queue1[3][j]);
				avail=avail-4;
			}
		}
		if(j==(rrcount-1))
		{
			j=-1;
		}
	}
		if(rrc<rrcount)
		{
			rrc=0;
		}
	counter1=j;
	return;
}
}

void FCFS()
{
	if(fcfsc==fcfscount)
	{
		return;
	}
	else
	{
	int avail=10,j;
	for(j=counter3;avail>0;j++)
	{
		if(queue3[3][j]==0)
		{ /*pass*/fcfsc++;
		printf("j=%d\n",j);
		printf("Process %d following FCFS scheduling algorithm is completed(execution done)\n\n",(queue3[0][j]));		}
		else if(queue3[3][j]<avail)
		{
			printf("Executing process %d having current burst time %d\n\n",(queue3[0][j]),queue3[3][j]);
			queue3[3][j]=0;
			avail=avail-queue3[3][j];
		}
		else
		{
			printf("Executing process %d having current burst time %d\n\n",(queue3[0][j]),queue3[3][j]);
			queue3[3][j]=queue3[3][j]-avail;
			printf("Now remaining burst time of process %d is %d\n\n",queue3[0][j],queue3[3][j]);
			avail=0;
			}
	
		if(j==(fcfscount-1))
		{
			j=-1;
		}
		}
		if(fcfsc<fcfscount)
		{
			fcfsc=0;
		}
	counter3=j;return;
	}
}

void PS()
{
	if(psc==pscount)
	{
		return;
	}
	else
	{
	int exhausted=0,j;
	for(j=counter2;exhausted<10;j++)
	{
		if(queue2[3][j]==0)
		{	psc++;
		printf("Process %d following priority scheduling algorithm is completed(execution done)\n\n",(queue2[0][j])); 		}
		else if(queue2[3][j]<10)
		{
			printf("Executing process %d having current burst time %d\n\n",(queue2[0][j]),queue2[3][j]);
			printf("Now remaining burst time of process %d is %d\n\n",queue2[0][j],queue2[3][j]);
			queue2[3][j]=0;
			exhausted=exhausted+queue2[3][j];
		}
		else
		{
			printf("Executing process %d having current burst time %d\n\n",(queue2[0][j]),queue2[3][j]);
			queue2[3][j]=queue2[3][j]-(10-exhausted);
			printf("Now remaining burst time of process %d is %d\n\n",queue2[0][j],queue2[3][j]);
			exhausted=10;
		}
		if(j==(pscount-1))
		{
			j=-1;
		}
		if(exhausted==0)
		{
			break;
		}
	//checking whether any process has come during execution of previous pro or not
			if(queue2[2][j+1]<=queue2[3][j])
			{
				//new process has arrived
				if(queue2[3][j]==0)
				{	/*pass*/ continue;		}
				else if(queue2[3][j]<10)
				{
					printf("Executing process %d having current burst time %d\n\n",(queue2[0][j]),queue2[3][j]);
					queue2[3][j]=0;
					exhausted=exhausted+queue2[3][j];
				}
				else
				{
					queue2[3][j]=queue2[3][j]-(10-exhausted);
					printf("Now remaining burst time of process %d is %d\n\n",queue2[0][j],queue2[3][j]);
					exhausted=10;
				}
			}
		
    }
    	if(fcfsc<fcfscount)
		{
			fcfsc=0;
		}
		counter3=j;
	}
	
}

int main()
{
	int i,j=0,k=0,l=0,noOfPro,col;
	printf("\t^~^~^~^~^~^~^~^ MULTILEVEL QUEUE SCHEDULING ALGO IMPLEMENTATION^~^~^~^~^~^~^~^~^\n\n");
	printf("Enter the number of processes : ");
	scanf("%d",&noOfPro);
	printf(" Please enter the details of the processes - \n\n");
	for(i=0;i<noOfPro;i++)
	{
		int process;
		printf("the process number : ");
		scanf("%d",&process);
		printf("priority of process : ");
		int priority;
		scanf("%d",&priority);
		
		if(priority>0 && priority<=5)
		{
			rrcount++;//for measuring no of processes in fcfs
			int r=0;
			queue1[r][j]=process;
			r++;
			queue1[r][j]=priority;
			r++;
			printf("Arrival time of the process : ");
			scanf("%d",&queue1[r][j]);
			r++;
			printf("Burst time of the process : ");
			scanf("%d",&queue1[r][j]);
			j++;						
		}
		else if(priority>5 && priority<=10)
		{
			pscount++;//for measuring no of processes in fcfs
			int r=0;
			queue2[r][k]=process;
			r++;
			queue2[r][k]=priority;
			r++;
			printf("Arrival time of the process : ");
			scanf("%d",&queue2[r][k]);
			r++;
			printf("Burst time of the process : ");
			scanf("%d",&queue2[r][k]);
			k++;				
		}
		else if(priority>10 && priority<=15)
		{
			fcfscount++; //for measuring no of processes in fcfs
			int r=0;
			queue3[r][l]=process;
			r++;
			queue3[r][l]=priority;
			r++;
			printf("Arrival time of the process : ");
			scanf("%d",&queue3[r][l]);
			r++;
			printf("Burst time of the process : ");
			scanf("%d",&queue3[r][l]);
			l++;				
		}
		else 
		{
			printf("Please enter priority in the range of 1 to 15\n");
		}
	}
	
	//sorting the queue of round robin acc to processes's arrival time
	for(col=0;col<rrcount;col++)
	{
		int temp;
		if(col==rrcount-1)
		{
			break;
			/*for(i=0;i<4;i++)
			{
			for(j=0;j<rrcount;j++)
			{
				printf("\t%d\t",queue1[i][j]);
			}
			printf("\n");
			}*/
		}
		else
		{
		if(queue1[2][col]>queue1[2][col+1])
		{
			//sorting arrival times
			temp=queue1[2][col];
			queue1[2][col]=queue1[2][col+1];
			queue1[2][col+1]=temp;
			
			//sorting process numbers
			temp=queue1[0][col];
			queue1[0][col]=queue1[0][col+1];
			queue1[0][col+1]=temp;
			
			//sorting priorities		
			temp=queue1[1][col];
			queue1[1][col]=	queue1[1][col+1];
			queue1[1][col+1]=temp;
			
			//sorting burst times			
			temp=queue1[3][col];
			queue1[3][col]=	queue1[3][col+1];
			queue1[3][col+1]=temp;	
		}
		}
	}
	
	//sorting priority scheduling queue
	for(col=0;col<pscount;col++)
	{
		int temp;
		if(col==pscount-1)
		{
		/*for(i=0;i<4;i++)
		{
			for(j=0;j<pscount;j++)
			{
				printf("%d\t",queue2[i][j]);
			}
			printf("\n");
		}*/
		}
		else
		{
		if(queue2[1][col]>queue2[1][col+1])
		{
			//sorting arrival times
			temp=queue2[2][col];
			queue2[2][col]=queue2[2][col+1];
			queue2[2][col+1]=temp;
			
			//sorting process numbers
			temp=queue2[0][col];
			queue2[0][col]=queue2[0][col+1];
			queue2[0][col+1]=temp;
			
			//sorting priorities		
			temp=queue2[1][col];
			queue2[1][col]=	queue2[1][col+1];
			queue2[1][col+1]=temp;
			
			//sorting burst times			
			temp=queue2[3][col];
			queue2[3][col]=	queue2[3][col+1];
			queue2[3][col+1]=temp;	
		}
		}
	}
	
	//sorting fcfs scheduling queue
	for(col=0;col<fcfscount;col++)
	{
		int temp;
		if(col==fcfscount-1)
		{
			break;
			/*for(i=0;i<4;i++)
			{
				for(j=0;j<fcfscount;j++)
				{
					printf("%d\t",queue3[i][j]);
				}
				printf("\n");
			}*/
		}
		else
		{
		if(queue3[2][col]>queue3[2][col+1])
		{
			//sorting arrival times
			temp=queue3[2][col];
			queue3[2][col]=queue3[2][col+1];
			queue3[2][col+1]=temp;
			
			//sorting process numbers
			temp=queue3[0][col];
			queue3[0][col]=queue3[0][col+1];
			queue3[0][col+1]=temp;
			
			//sorting priorities		
			temp=queue3[1][col];
			queue3[1][col]=	queue3[1][col+1];
			queue3[1][col+1]=temp;
			
			//sorting burst times			
			temp=queue3[3][col];
			queue3[3][col]=	queue3[3][col+1];
			queue3[3][col+1]=temp;	
		}
		}
	}
	
	//finding minimum arrival time
	int minArrTime;
	minArrTime=queue1[2][0];
	int index=1;
	if(queue2[2][0]<minArrTime)
	{
		minArrTime=queue2[2][0];
		index=2;
	}
	if(queue3[2][0]<minArrTime)
	{
		minArrTime=queue3[2][0];
		index=3;
	}
	printf("min arrival time is %d \n\n",minArrTime);
	//checking priority
	if(index==1)
	{
		printf("Initially process is of 1 Queue\n\n");
		//calling RR
		RR();
	}
	
	else if(index==2)
	{
		printf("Initially process is of 2 Queue\n\n");
		//calling PS
		PS();
	}
	else if(index==3)
	{
		printf("Initially process is of 3 Queue\n\n");
		FCFS();
	}
	
	PS();
	FCFS();
	int end;
	while(end!=0)
	{
		if(rrc<rrcount or psc<pscount or fcfsc<fcfscount)
		{
			RR();
			PS();
			FCFS();
		}
		else
		{
			end=0;
		}
	}
	
	
	return 0;
}
