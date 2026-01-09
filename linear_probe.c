//Given N employee records with a set K of Keys (4-digit) which uniquely determine the records. Let the keys in K and addresses in L are Integers. Design and develop a Program in C that uses Hash function H: K →L as H(K)=K mod m (remainder method) and implement hashing technique to map a given key K to the address space L. Resolve the collision (if any) using linear probing.

#include <stdio.h>
#include <string.h>

#define MAX 10   // size of hash table

// Structure for an employee record
struct Employee 
{
    int key;          		  // 4-digit key
    char name[30];      	 // employee name
    int occupied;      	 // 0 = empty, 1 = filled
};

struct Employee HT[MAX];   	// Hash table

// Hash function
int hash(int key) 
{
    return key % MAX;
}

// Insert using Linear Probing
void insert(int key, char name[]) 
{
    int index = hash(key);
    while (HT[index].occupied == 1) 
   {
        index = (index + 1) % MAX;    
   }

    HT[index].key = key;
    strcpy(HT[index].name, name);
    HT[index].occupied = 1;

    printf("Inserted Key %d at index %d\n", key, index);
}



// Display Hash Table
void display() 
{
    printf("\nHash Table Contents:\n");
    for (int i = 0; i < MAX; i++) 
    {
        if (HT[i].occupied)
             printf("Index %2d -> Key: %4d, Name: %s\n", i, HT[i].key, HT[i].name);
        else
            printf("Index %2d -> Empty\n", i);
    }
}

void main() 
{
    int n, key;
    char name[30];
    for (int i = 0; i < MAX; i++)
 	       HT[i].occupied = 0;

    printf("Enter number of employee records to insert: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter 4-digit key: ");
        scanf("%d", &key);
        printf("Enter employee name: ");
        scanf("%s", name);

        insert(key, name);
    }

    display();

    return;
}
