#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main( int argc, const char* argv[] )
{
	printf("-----------------------------------\n");
	printf("-         PAKET DOWNLOADER        -\n");
	printf("-            V. 1.0.1             -\n");
	printf("-      by: Ignacio de Gregorio    -\n");
	printf("-----------------------------------\n");
	printf("-           My GitHub:            -\n");
	printf("-   https://github.com/nachog95   -\n");
	printf("-----------------------------------\n");

	char stringURL[100];	

	printf("This program download a file from http://212.128.69.216/lolo \n");

	int estado;	
	int pid = fork();
	
	switch(pid)
	{
		case -1: // Si pid es -1 quiere decir que ha habido un error
			perror("No se ha podido crear el proceso hijo\n");
			break;
		case 0: // Cuando pid es cero quiere decir que es el proceso hijo
			// aqui creamos el proceso que descargará el archivo	
			//COMANDO A EJECUTAR:
			//curl -H "Range: bytes=0-20" http://212.128.69.216/lolo2.txt-s -o myfile.txt
			execlp("curl","curl", "-H","\"Range: bytes=0-20\"","http://212.128.69.216/lolo","-o","mylolo.txt",NULL);		
			break;
		default: // Cuando es distinto de cero es el padre
			
			// La función wait detiene el proceso padre y se queda esperando hasta
			// que termine el hijo
			if (waitpid(pid, &estado, 0) > 0) {
             
           			 if (WIFEXITED(estado) && !WEXITSTATUS(estado)) 
					printf("-------DESCARGA TERMINADA---------.\n");
			}
			else {
          		 // waitpid() failed
         		  printf("waitpid() failed\n");
       		        }
			exit(0);
			break;
     			 
	}

return 0;
}

