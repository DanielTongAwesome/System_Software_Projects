#include "..\rt.h"
#include <stdio.h>
#include <iostream>

int			pipe1data, pipe2data, pipe3data, pipe4data;

int main() {
	CPipe	p1("Pipe1", 1024);		// pipeline 1 connected to the pump1 
	CPipe	p2("Pipe2", 1024);		// pipeline 2 connected to the pump2  
	CPipe	p3("Pipe3", 1024);		// pipeline 3 connected to the pump3 
	CPipe   p4("Pipe4", 1024);		// pipeline 4 connected to the pump4 


	while (1) {
		if ((p1.TestForData()) >= sizeof(pipe1data)) {		// if at least 1 integer in pipeline
			p1.Read(&pipe1data, sizeof(pipe1data));		// read data from pipe 	
			printf("Parent Read '%d' from pump1\n", pipe1data);
		}

		if ((p2.TestForData()) >= sizeof(pipe2data)) {	// if at least 1 integer in pipeline
			p2.Read(&pipe2data, sizeof(pipe2data));		// read data from pipe
			printf("Parent Read '%d' from pump2\n", pipe2data);
		}

		if ((p3.TestForData()) >= sizeof(pipe3data)) {		// if at least 1 integer in pipelinee 
			p3.Read(&pipe3data, sizeof(pipe3data));		// read data from pipe
			printf("Parent Read '%d' from pump3\n", pipe3data);
		}

		if ((p4.TestForData()) >= sizeof(pipe4data)) {		// if at least 1 integer in pipelinee 
			p4.Read(&pipe4data, sizeof(pipe4data));		// read data from pipe
			printf("Parent Read '%d' from pump4\n", pipe4data);
		}
	}



}