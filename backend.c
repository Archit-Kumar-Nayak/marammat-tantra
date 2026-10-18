#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef enum { WAITING, RECEIVED, DIAGNOSED, REPAIRED, DELIVERED } TicketStatus;

// --- LIFO Action Stack Structure ---
typedef struct {
    int ticketId;
    char actionType[30];
    TicketStatus prevStatus;
    int prevTechId;
    char description[100];
} ActionStackNode;

typedef struct {
    ActionStackNode items[MAX_STACK_SIZE];
    int top;
} ActionStack;

// --- FIFO Repair Queue Structure ---
typedef struct TicketNode {
    int ticketId;
    char customerName[50];
    char deviceModel[50];
    TicketStatus status;
    struct TicketNode* next;
} TicketNode;

typedef struct {
    TicketNode* head;
    TicketNode* tail;
    int size;
} RepairQueue;

// Initialize Queue
RepairQueue* initRepairQueue() {
    RepairQueue* q = (RepairQueue*)malloc(sizeof(RepairQueue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

// Enqueue Ticket Operation
void enqueueRepairTicket(RepairQueue* q, int id, const char* name, const char* model) {
    TicketNode* newNode = (TicketNode*)malloc(sizeof(TicketNode));
    newNode->ticketId = id;
    strcpy(newNode->customerName, name);
    strcpy(newNode->deviceModel, model);
    newNode->status = WAITING;
    newNode->next = NULL;

    if (q->tail == NULL) {
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->size++;
    printf("[QUEUE ENQUEUE (FIFO)] Ticket #%d | Customer: %s | Device: %s (Queue Size: %d)\n", 
           id, name, model, q->size);
}

// Push to Stack Operation
void pushAction(ActionStack* stack, int ticketId, const char* desc) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->top++;
        stack->items[stack->top].ticketId = ticketId;
        strcpy(stack->items[stack->top].description, desc);
        printf("[STACK PUSH (LIFO)] Index [%d] ➔ Action: '%s' for Ticket #%d\n", 
               stack->top, desc, ticketId);
    }
}

// Pop from Stack Operation (Undo)
void popAction(ActionStack* stack) {
    if (stack->top >= 0) {
        printf("[STACK POP (LIFO - UNDO)] Reverted: '%s' from Index [%d]\n", 
               stack->items[stack->top].description, stack->top);
        stack->top--;
    } else {
        printf("[STACK] Action Stack Empty!\n");
    }
}

// Main Standalone Driver Function
int main() {
    printf("============================================================\n");
    printf("   MARAMMAT TANTRA - C BACKEND KERNEL STANDALONE DEMO      \n");
    printf("============================================================\n\n");

    printf("--- 1. QUEUE EXECUTION (FIFO) ---\n");
    RepairQueue* repairQ = initRepairQueue();
    enqueueRepairTicket(repairQ, 9101, "Rajesh Verma", "iPhone 15 Pro");
    enqueueRepairTicket(repairQ, 9102, "Sunita Menon", "Galaxy S24 Ultra");

    printf("\n--- 2. STACK EXECUTION (LIFO) ---\n");
    ActionStack actionStack;
    actionStack.top = -1;
    pushAction(&actionStack, 9101, "Status Changed: Waiting -> Received");
    pushAction(&actionStack, 9102, "Reassigned Tech: Suresh -> Priya");

    printf("\n--- 3. UNDO OPERATION (POP) ---\n");
    popAction(&actionStack);

    printf("\n============================================================\n");
    return 0;
}