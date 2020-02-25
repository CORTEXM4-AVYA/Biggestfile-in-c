
#include <stdio.h> 
#include <dirent.h>
int main(){
	DIR *dir;
  	struct dirent *file;
  	char fileName[255];
 	int x,y; 
    int i,j=0;
    char name[255][255];
    int arr[15];
    int small,large;
    small=large=arr[0];
  	dir = opendir(".");
  	// READING THE DIRECTORY AND COPY NAMES TO FILENAME 
    while ((file = readdir(dir)) != NULL)
    {
        printf("  %s\n", file->d_name);
        strncpy(fileName, file->d_name, 254);
        fileName[254] = '\0';
        printf("%s\n", fileName);
    // Finding size of each file in the directory
        FILE *fp;  
    	int size = 0;
    	fp = fopen(fileName, "r");
    	if (fp == NULL)
    		{
        		printf("\nFile unable to open...");
    		}
    	else
   		 	{
        printf("\nFile opened...");
    		}
   		fseek(fp, 0, 2);    /* File pointer at the end of file */
    	size = ftell(fp);   /* Take a position of file pointer in size variable */
   		printf("The size of %s is: %d bytes\n",fileName, size);
  		strncpy(name[j],fileName, 254);
     	arr[i]=size;
    	i++;
   		j++; 
   		fclose(fp); 
    }
    //FINDING SMALLEST AND LARGEST FILE IN DIRECTORY
   for(i=0;i<15;i++)
    {   if(arr[i]<small)
    		small=arr[i];
            x=i;
    	if(arr[i]>large)
    		large=arr[i];
    		y=j;
	}
	//OUTPUT PRINTING
	printf("***********************************************************************************");
	printf("\n\nSmallest file is %s of  %d bytes \n and largest file is  %s of %d bytes",name[x],small,name[y],large);
    closedir(dir);
    printf("\n\n*********************************************************************************");
return 0;
}
