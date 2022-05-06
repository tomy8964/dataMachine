//201835546 Hamgeonwook
#include <stdio.h>
#include "schedule.h"

#define MAX_PROC_NUM 100
#define PROC_STATE_INIT 0
#define PROC_STATE_READY 1
#define PROC_STATE_RUNNING 2
#define PROC_STATE_TERMINATE 3

typedef struct myprocess_
{
	int pid;
	int state;
	int begin_time;
	int burst_time;
	int remaining_time;
	int response_time;
	int finish_time;
}MyProcess;

MyProcess proc_list[MAX_PROC_NUM];

int num_procs;
int method;
int cpu_use = -1;
int preemptive = 0;

void set_schedule(int m)
{
	method = m;
	// SRTF
	if (m == 3)
	{
		preemptive = 1;
	}
}

void read_proc_list(const char* file_name)
{
	//read file list
	FILE* fp = fopen(file_name, "r");
	fseek(fp, 0, SEEK_SET);
	fscanf(fp, "%d", &num_procs);
	for (int i = 0; i < num_procs; i++)
	{
		fscanf(fp, "%d %d %d", &proc_list[i].pid, &proc_list[i].begin_time, &proc_list[i].burst_time);
		proc_list[i].state = PROC_STATE_INIT;
		proc_list[i].finish_time = 10000;
		proc_list[i].response_time = 10000;
		proc_list[i].remaining_time = proc_list[i].burst_time;
	}
	fclose(fp);
}

void non_preemptive_switch()
{
	int best_idx = -1;
	int best_val = 10000;

	for (int i = 0; i < num_procs;i++)
	{
		if (proc_list[i].state == PROC_STATE_READY)
		{
			int val;
			//FCFS
			if (method == 1)
			{
				val = proc_list[i].begin_time;
			}
			//SJF
			else if (method == 2)
			{
				val = proc_list[i].burst_time;
			}
			if (val<best_val)
			{
				best_val = val;
				best_idx = i;
			}

		}
	}
	if (best_idx > -1)
	{
		proc_list[best_idx].state = PROC_STATE_RUNNING;
	}
	cpu_use = best_idx;

	return;
}

void preemptive_switch()
{
	int best_idx = -1;
	int best_val = 10000;

	for (int i = 0; i < num_procs;i++)
	{
		if ((proc_list[i].state == PROC_STATE_READY)||(proc_list[i].state == PROC_STATE_RUNNING))
		{
			int val;
			if (method == 3)
			{
				proc_list[i].state = PROC_STATE_READY;
				val = proc_list[i].remaining_time;
			}
			if (val < best_val)
			{
				best_val = val;
				best_idx = i;
			}

		}
	}
	if (best_idx > -1)
	{
		proc_list[best_idx].state = PROC_STATE_RUNNING;
	}
	cpu_use = best_idx;

	return;
}

int check_terminate_all()
{
	//if terminate?
	int terminate_all = 1;
	for (int i = 0; i < num_procs; i++)
	{
		if (proc_list[i].state != PROC_STATE_TERMINATE)
		{
			terminate_all = 0;
			break;
		}
	}
	return terminate_all;
}

int do_schedule(int tick)
{
	if (check_terminate_all())
		return -1;
	int new_ready = 0;
	for (int i = 0; i < num_procs;i++)
	{
		if (proc_list[i].begin_time == tick)
		{
			proc_list[i].state = PROC_STATE_READY;
			new_ready = 1;
		}
	}
	if (cpu_use >= 0)
	{
		proc_list[cpu_use].remaining_time--;
		if (preemptive == 1)
		{
			preemptive_switch();
		}
		if (proc_list[cpu_use].remaining_time == 0)
		{
			proc_list[cpu_use].finish_time = tick;
			proc_list[cpu_use].state = PROC_STATE_TERMINATE;
			if (check_terminate_all())
				return -1;
			if (preemptive == 0)
			{
				non_preemptive_switch();
			}
			else if (preemptive == 1)
			{
				preemptive_switch();
			}
		}
	}
	else {
		if (new_ready)
		{
			if (preemptive == 0)
			{
				non_preemptive_switch();
			}
			else if (preemptive == 1)
			{
				preemptive_switch();
			}
		}
	}
	if (proc_list[cpu_use].response_time > tick)
	{
		proc_list[cpu_use].response_time = tick;
	}
	if (cpu_use > -1)
		return proc_list[cpu_use].pid;
	
	return 0;
}

void print_performance()
{
	int sum_tat = 0;
	int sum_wt = 0;
	int sum_rt = 0;

	printf("\n");
	printf("==================================================================================================\n");
	printf(" PID        begin      finish      Turn around time    wating time        Response time   \n");
	printf("==================================================================================================\n");
	for (int i = 0; i < num_procs; i++)
	{
		int tat = proc_list[i].finish_time - proc_list[i].begin_time;
		int wt = proc_list[i].finish_time - proc_list[i].begin_time - proc_list[i].burst_time;
		int rt = proc_list[i].response_time - proc_list[i].begin_time;
		sum_tat += tat;
		sum_wt += wt;
		sum_rt += rt;
		printf("%4d %10d %10d %12d %18d %19d\n", 
			proc_list[i].pid,
			proc_list[i].begin_time,
			proc_list[i].finish_time,
			tat, 
			wt, 
			rt);
	}
	printf("_________________________________________________________________________________________________\n");
	printf(" average:                %16.2f     %18.2f    %19.2f\n",
		(float)sum_tat / (float)num_procs, 
		(float)sum_wt / (float)num_procs, 
		(float)sum_rt / (float)num_procs );
	printf("==================================================================================================\n");

}