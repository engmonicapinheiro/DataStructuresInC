#include <stdio.h>
enum states
{
    STATE_A = 0,
    STATE_B,
    STATE_C
};

typedef enum states State_Type;

void state_A(void);
void state_B(void);
void state_C(void);
void StateMachineInit(void);

//array of function pointers
static void (*state_table[])(void) = {state_A, state_B, state_C};

static State_Type current_state;
static int clock;

int main(void)
{
    StateMachineInit();

    while(1)
    {
        state_table[current_state]();
        clock++;

    }
    return 0;
}

void StateMachineInit(void)
{
    current_state = STATE_A;
    clock = 0;
}
void state_A(void)
{
    if(clock == 2)
    {
        current_state = STATE_B;
        printf("This is the execution of state A.\n");
    }
}
void state_B(void)
{
    if(clock == 5)
    {
        current_state = STATE_C;
        printf("This is the execution of state B.\n");
    }
}
void state_C(void)
{
    if(clock == 9)
    {
        current_state = STATE_A;
        printf("This is the execution of state C.\n");
        clock = 0;
    }
}
