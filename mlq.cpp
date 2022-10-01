#include <stdio.h>
#include <conio.h>

void MLQSchedule(int processes[], int burst[], int sysuser[], int n) 
{
    int wait[100],turnaround[100], temp;
    float totalwait, totalturnaround;
    for(int i=0;i<n;i++)
        for(int k=i+1;k<n;k++)
            if(sysuser[i] > sysuser[k])
                {
                    temp=processes[i];
                    processes[i]=processes[k];
                    processes[k]=temp;
                    temp=burst[i];
                    burst[i]=burst[k];
                    burst[k]=temp;
                    temp=sysuser[i];
                    sysuser[i]=sysuser[k];
                    sysuser[k]=temp;
                }
    totalwait = wait[0] = 0;
    totalturnaround = turnaround[0] = burst[0];
    for(int i=1;i<n;i++)
    {
        wait[i] = wait[i-1] + burst[i-1];
        turnaround[i] = turnaround[i-1] + burst[i];
        totalwait = totalwait + wait[i];
        totalturnaround = totalturnaround + turnaround[i];
    }
    for(int i=0;i<n;i++)
    {   
        printf("Process %d\n", i+1);
        printf("System/User (0/1): %d\n", sysuser[i]);
        printf("Burst Time: %d\n", burst[i]);
        printf("Wait Time: %d\n", wait[i]);
        printf("Turnaround Time: %d\n\n", turnaround[i]);
    }
    printf("\nAverage Waiting Time is: %f",totalwait/n);
    printf("\nAverage Turnaround Time is: %f",totalturnaround/n);
}
int main()
{
    int processes[20],burst[20], sysuser[20], n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        processes[i] = i;
        printf("Enter the Burst Time of Process %d: ", i+1);
        scanf("%d",&burst[i]);
        printf("System/User Process (0/1) : ");
        scanf("%d", &sysuser[i]);
    }
    MLQSchedule(processes, burst, sysuser, n);
    getch();
return 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* node = head, *offsetNode = head;
    for (int i = 0; i < n; ++i)
        node = node->next;
    
    // if node is NULL n is equal to the length of the linked list and we have to remove the head
    if (node == NULL)
        return head->next;
    
    while (node->next != NULL) {
        node = node->next;
        offsetNode = offsetNode->next;
    }
    
    offsetNode->next = offsetNode->next->next;
    
    return head;
    }
};
