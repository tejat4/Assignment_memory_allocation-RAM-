#include<stdio.h>
#include<stdlib.h>
#define MEMORY_SIZE (100*1024) //total simulated heap size 100 kb
//simulated RAM
static unsigned char memory[MEMORY_SIZE];

//structure to store allocation info
typedef struct
{
	unsigned char *addr; //pointer to start of allocate block inside memory[]
	size_t size; //size of allocated block
	int flag; //0 in use(allocated), 1 is free(available for reuse)
}Block;

#define max_blocks 100
static Block *blocks[max_blocks];// array of pointer to block struts(all NULL initially)

/*--------------------------------------------------
  ALLOCATING FUNCTION
  -----------------------------------------------------*/

int *allocate(int size)
{
	static unsigned char *next_free=memory;

	// Empty slot(first time this slot is used)
	for(int i=0;i<max_blocks;i++)
	{
		if(blocks[i]==NULL) //checking raw space left in memory[]
		{
			if(next_free+size <= memory + MEMORY_SIZE)
			{
				blocks[i]=(Block*)malloc(sizeof(Block)); //creating record
				blocks[i]->addr=next_free; //starting address of the block
				blocks[i]->size=size; //storing size
				blocks[i]->flag=0; //making this block is un use(allocated)
				next_free += size; 
				return (int *)blocks[i]->addr; //return pointer to start of allocated block(cast to int*) 
			}
			else
			{
				return NULL; //out of raw space
			}
		}
	}
	//resuse a previously freed block if big enough
	for(int i=0;i<max_blocks;i++)
		{
	if(block[i]!=NULL && (blocks[i]->flag==1) && blocks[i]->size >= (size_t)size)
	{
		blocks[i]->flag=0; //make the block use it again
		return (int*)blocks[i]->addr; //return original starting address
	}
		}
	return NULL; //no slot or reusable block available
}

/*----------------------------------------------------------
  DEALLOCATING FUNCTION
  ------------------------------------------------------------*/

void deallocate(int *ptr)
{
	for(int i=0;i<max_blocks;i++)
	{
		if(blocks[i]!=NULL && blocks[i]->addr==(unsigned char *)ptr && !blocks[i]->flag)
		{
			blocks[i]->flag=1;//making block as free
			return;
		}
	}
}

/*------------------------------------------------------------
  MAIN FUNCTION
  --------------------------------------------------------------*/

int main()
{
	int *memory[100];
	memory[0]=allocate(128);
	memory[1]=allocate(1024);
	memory[2]=allocate(4096);
	deallocate(memory[1]);
	memory[1]=allocate(512);
}
