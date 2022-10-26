#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

struct Sdata
{
    int ID;
    char name[40];
    float height;
};

//linked list node 
struct Sstudent
{
    struct Sdata student;
    struct Sstudeent* pNextStudent;
};

struct Sstudent* gpFirstStudent = NULL;

void AddStudent()
{
    struct Sstudent* pNewStudent = NULL;
    struct Sstudent* pLastStudent=NULL;
    char temp_text[40];
    //check list is empty == yes
    if (gpFirstStudent == NULL)
    {
        //create new record
        pNewStudent = (struct Sstudent*)malloc(sizeof(struct Sstudent));
        //assign it to gpfirst
        gpFirstStudent = pNewStudent;
    }
    //check list is empty == no
    else
    {
        //navigate until reach to last record
        pLastStudent = gpFirstStudent;
        while (pLastStudent->pNextStudent)
            pLastStudent = pLastStudent->pNextStudent;
            //create new record
        pNewStudent = (struct Sstudent*)malloc(sizeof(struct Sstudent));
        pLastStudent->pNextStudent = pNewStudent;
        
    }
        //fill new record 
        printf("Enter ID: \n");
        gets(temp_text);
        pNewStudent->student.ID = atoi(temp_text);

        printf("Enter Student Full Name: \n");
        gets(pNewStudent->student.name);

        printf("Enter Height: \n");
        gets(temp_text);
        pNewStudent->student.height = atof(temp_text);

        //set the next pointer (new_student) to null
        pNewStudent->pNextStudent = NULL;
    
}

int DeleteStudent()
{
    char temp_text[40];
    unsigned int selected_id;
    //get the selected id
    printf("Enter the student id to be deleted: \n");
    gets(temp_text);
    selected_id = atoi(temp_text);
    //check if list not emty
    if (gpFirstStudent)
    {
        struct Sstudent* pSelectedStudent = gpFirstStudent;
        struct Sstudent* pPreviousStudent = NULL;
        while (pSelectedStudent)
        {
            //compare each node with the selected ID
            if (pSelectedStudent->student.ID == selected_id)
            {
                if (pPreviousStudent)//the first student is not the selected one
                {
                    pPreviousStudent->pNextStudent = pSelectedStudent->pNextStudent;
                }
                //1st student is the selected ID
                else
                {
                    gpFirstStudent = pSelectedStudent->pNextStudent;
                }
                free(pSelectedStudent);
                return 1;
            }
            pPreviousStudent = pSelectedStudent;
            pSelectedStudent = pSelectedStudent->pNextStudent;
        }
        printf("cannot find student ID\n");
        return 0;
    }
}
void View_Students()
{
    struct Sstudent* pCurrentStudent = gpFirstStudent;
    int count = 0;
    if (gpFirstStudent == NULL)
        printf("Empty List\n");
    else
    {
        while (pCurrentStudent)
        {
            printf("record number %d \n", count + 1);
            printf("\t ID: %d \n", pCurrentStudent->student.ID);
            printf("\t Name: %s \n", pCurrentStudent->student.name);
            printf("\t Height %f \n", pCurrentStudent->student.height);
            pCurrentStudent = pCurrentStudent->pNextStudent;
            count++;
        }
    }
}
void DeleteAll()
{
    struct Sstudent* pCurrentStudent = gpFirstStudent;
    int count = 0;
    if (gpFirstStudent == NULL)
        printf("Empty List\n");
    else
    {
        while (pCurrentStudent)
        {
            struct sStudent* pTempStudent = pCurrentStudent;
            pCurrentStudent = pCurrentStudent->pNextStudent;
            free(pTempStudent);
        }
        gpFirstStudent = NULL;
    }
}

void GetNth()
{
    char temp_text[40];
    int count = 0;
    unsigned int selected_index;
    printf("Enter element Index\n");
    gets(temp_text);
    selected_index = atoi(temp_text);
    struct Sstudent* pCurrentStudent = gpFirstStudent;
    while (pCurrentStudent)
    {
        if (selected_index == count)
        {
            printf("\t ID: %d \n", pCurrentStudent->student.ID);
            printf("\t Name: %s \n", pCurrentStudent->student.name);
            printf("\t Height %f \n", pCurrentStudent->student.height);
            break;
        }
        else
        {
            pCurrentStudent = pCurrentStudent->pNextStudent;
        }
        count++;

    }
    if (pCurrentStudent == NULL)
        printf("Element Not Found\n");
}

int Length()
{
    int count = 0;
    struct Sstudent* pCurrentStudent = gpFirstStudent;
    while (pCurrentStudent)
    {
        count++;
        pCurrentStudent = pCurrentStudent->pNextStudent;
    }
    printf("Linked List Length = %d\n", count);
    return count;
}

int Length_Recursive(struct Sstudent* pCurrentStudent)
{
    int count = 0;
    if (pCurrentStudent==NULL)
    {
        return 0;
    }
    else
    {
        count++;
        pCurrentStudent = pCurrentStudent->pNextStudent;
        return count + Length_Recursive(pCurrentStudent);
    }
}

void GetNth_From_End()
{
    char temp_text[40];
    unsigned int selected_index;
    printf("Enter element Number From End\n");
    gets(temp_text);
    selected_index = atoi(temp_text);
    struct Sstudent* main_Ptr = gpFirstStudent;
    struct Sstudent* ref_Ptr = gpFirstStudent;
    for (int i = 0; i < selected_index; i++)
    {
        ref_Ptr = ref_Ptr->pNextStudent;
    }
    while (ref_Ptr->pNextStudent)
    {
        ref_Ptr = ref_Ptr->pNextStudent;
        main_Ptr = main_Ptr->pNextStudent;
    }
    printf("\t ID: %d \n", main_Ptr->student.ID);
    printf("\t Name: %s \n", main_Ptr->student.name);
    printf("\t Height %f \n", main_Ptr->student.height);
}

void GetMiddle()
{
    struct Sstudent* main_Ptr = gpFirstStudent;
    struct Sstudent* ref_Ptr = gpFirstStudent;
    while (ref_Ptr)
    {
        main_Ptr = main_Ptr->pNextStudent;
        ref_Ptr = ref_Ptr->pNextStudent;
        if (ref_Ptr->pNextStudent == NULL)
            break;
        ref_Ptr = ref_Ptr->pNextStudent;
        if (ref_Ptr->pNextStudent == NULL)
            break;
    }
    printf("\t ID: %d \n", main_Ptr->student.ID);
    printf("\t Name: %s \n", main_Ptr->student.name);
    printf("\t Height %f \n", main_Ptr->student.height);
}

void Reverse()
{
    struct Sstudent* pCurrent = gpFirstStudent;
    struct Sstudent* pPrevious = NULL;
    struct Sstudent* pNext = gpFirstStudent;
    while (pCurrent)
    {
        pNext = pCurrent->pNextStudent;
        pCurrent->pNextStudent = pPrevious;
        pPrevious = pCurrent;
        pCurrent = pNext;
    }
    gpFirstStudent = pPrevious;
    
}

void main()
{
    char temp_text[40];
    while (1)
    {
        printf("===========\n");
        printf("choose one of the following options \n");
        printf("1 --> Add Student\n");
        printf("2 --> Delete Student\n");
        printf("3 --> View Students\n");
        printf("4 --> Delete All\n");
        printf("5 --> Get Index\n");
        printf("6 --> Get Length\n");
        printf("7 --> Get length using recursive\n");
        printf("8 --> GetNth from ending\n");
        printf("9 --> Get middle of linked list\n");
        printf("10 --> Reverse linked list\n");
        printf("Enter Option Number:\n");
        gets(temp_text);
        printf("=======================\n");
        switch (atoi(temp_text))
        {
        case 1:
            AddStudent();
            break;
        case 2:
            DeleteStudent();
            break;
        case 3:
            View_Students();
                break;
        case 4:
            DeleteAll();
            break;
        case 5:
            GetNth();
            break;
        case 6:
            Length();
            break;
        case 7:
            printf("Linked List Length = %d\n", Length_Recursive(gpFirstStudent));
            break;
        case 8:
            GetNth_From_End();
            break;
        case 9:
            GetMiddle();
            break;
        case 10:
            Reverse();
            break;
        default:
            printf("Wrong Option\n");
            break;
        }
    }
}










