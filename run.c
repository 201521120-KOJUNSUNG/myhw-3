#include <sys/types.h>
#include <limits.h>
#include <sys/resource.h>
#include <unistd.h>
#include <sys/time.h>
#include "run.h"
#include "util.h"
void *last = 0;
void *base = 0;
void *my_brk;
struct rlimit my_rlimit;

p_meta find_meta(p_meta *last, size_t size) {
  
  p_meta index = base;
  p_meta result = -1;
  
 if(last==base)return result;

  switch(fit_flag){
    case FIRST_FIT:
    {   
      //FIRST FIT CODE
	while(index){
		if((index->free) && (index->size>=size)) result = index;
		if(index->next==NULL)result = index;
		index = index->next;
	}

    }
    break;

    case BEST_FIT:
    {
     
      //BEST_FIT CODE
      while(index){
	if((index->free) && (index->size>=size)){
	 if(result ->size > index->size)result = index;
}
index=index->next;
}

    }
    break;

    case WORST_FIT:
    {
	while(index){
	
	if((index->free)&& index->size>=size){ 
	if(result->size<index->size) result = index;
	index=index->next;
  }
    
 }
}
 break;
 }
  return result;
}
void *m_malloc(size_t size) {
 int total_size;
 p_meta result = find_meta(&last, size);
  size =((size+3)/4)*4;
 total_size = size + META_SIZE;
  base = sbrk(0);
  last = base;

return result ->data;
   
}

void m_free(void *ptr) {
   p_meta index = ptr -META_SIZE;
   index->free = 1;
}

void *m_realloc(void* ptr, size_t size){

}
