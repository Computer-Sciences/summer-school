#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sanitizer/coverage_interface.h>

FILE * covfp ; 

extern
void 
bye (void) 
{
	fclose(covfp) ;
}


extern 
void 
__sanitizer_cov_trace_pc_guard_init(uint32_t *start, uint32_t *stop) 
{
	static uint64_t N = 1 ;
	if (start == stop || *start) 
		return;
	for (uint32_t *x = start; x < stop; x++) {
		*x = N ;  
		N++ ;
	}


	covfp = fopen("coverage_log", "w") ;

	fprintf(covfp, "INIT: %p %p\n", start, stop);
	atexit(bye) ;
}


extern 
void 
__sanitizer_cov_trace_pc_guard(uint32_t *guard) 
{
	if (!*guard) 
		return;  

	void *PC = __builtin_return_address(0);
	char PcDescr[1024];

	 __sanitizer_symbolize_pc(PC, "%p %F %L", PcDescr, sizeof(PcDescr));
	fprintf(covfp, "guard: %p %x PC %s\n", guard, *guard, PcDescr);
}


