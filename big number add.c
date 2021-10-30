#include<stdio.h>
#include<string.h>
#include<stdbool.h>
typedef struct _string
{
    char character;
    struct _string *next;
    struct _string *prev;
} string;
typedef struct _stringObject
{
    string *head;
    string *last;
} stringObject;
stringObject *createObject_string()
{
    stringObject *node=(stringObject*)malloc(sizeof(stringObject));
    node->head=NULL;
    node->last=NULL;
    return node;
}
void insertString(stringObject *object, char stri[])
{
    int i;
    for(i=0; i<strlen(stri); i++)
    {
        string *node=(string*)malloc(sizeof(string));
        node->character=stri[i];
        node->next=NULL;
        node->prev=NULL;
        if(object->head==NULL)
        {
            object->head=node;
            object->last=node;
        }
        else
        {
            node->prev=object->last;
            object->last->next=node;
            object->last=node;
        }
    }
}
void printString(stringObject *object)
{
    string *pri=object->last;
    if(pri!=NULL)
    {
        while(pri!=NULL)
        {
            printf("%c", pri->character);
            pri=pri->prev;
        }
    }
}
void addition(stringObject *x, stringObject *y, stringObject *z)
{
    int carry = 0;
    char tem[3];
    string *a=x->last;
    string *b=y->last;
    if(a!=NULL && b!=NULL)
    {
        while(a!=NULL || b!=NULL)
        {
            if(a == NULL)
            {
                tem[0] = ((b->character + carry - '0')%10)+'0';
                carry = (b->character + carry - '0')/10;
                b=b->prev;
            }
            else if(b == NULL)
            {
                tem[0] = ((a->character + carry - '0')%10)+'0';
                carry = (a->character + carry - '0')/10;
                a=a->prev;
            }
            else
            {
                tem[0] = ((a->character + b->character + carry - 2*'0')%10)+'0';
                carry = (a->character + b->character + carry - 2*'0')/10;
                a=a->prev;
                b=b->prev;
            }
            tem[1] = '\0';
            insertString(z, tem);
        }
    }
    if(carry != 0)
    {
        tem[0] = carry+'0';
        tem[1] = '\0';
        insertString(z, tem);
    }
}
int main()
{
    stringObject *firstNumber = createObject_string();
    stringObject *secondNumber = createObject_string();
    stringObject *result = createObject_string();

    insertString(firstNumber,  "98941132798160");
    insertString(secondNumber,  "4457891245486");
    ///                        103399024043646
    addition(firstNumber, secondNumber, result);
    printString(result);
    return 0;
}
