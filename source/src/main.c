#include <stdio.h>
#include <malloc.h>

int main(int argc, char* argv[])
{
	printf("bin2h\n");
	
	//No arguments specified
	if (argc <= 1)
	{
		printf("Drag and drop a file to convert it.\n");
	}
	else
	{
		//Repeat for each argument
		int arg = 1;
//		for (; arg < argc; arg++)
		{
			printf("\n------------------------\n");
			
			char* inPath = argv[arg];
			char outPath[512];
			
			FILE* fin = fopen(inPath, "rb");
			FILE* fout;
			
			if (!fin)
			{
				printf("Error: Could not open file %s\n", inPath);
			}
			else
			{
				//Open out file
				sprintf(outPath, "%s.txt", inPath);
				fout = fopen(outPath, "wt");
				
				if (!fout)
				{
					printf("Error: Could not open file %s\n", outPath);
				}
				else
				{					
					printf("Converting %s\n", inPath);
					
					//
					const int BUF_SIZE = (1024*1024*2);
					unsigned char* buffer = (unsigned char*)malloc(BUF_SIZE);
				
					//Get file size
					fseek(fin, 0, SEEK_END);
					int fsize = ftell(fin);
					fseek(fin, 0, SEEK_SET);
					
					fprintf(fout, "%d\n\n", fsize);
					
					//
					int fileRead = 0;					
					do
					{
						fileRead = fread(buffer, 1, fsize, fin);
						
						for (int i = 0; i < fileRead; i++)
						{
							fprintf(fout, "0x%02X, ", buffer[i]);
							
							if (i % 16 == 15 && i != 0)
								fprintf(fout, "\n");
						}
					}
					while (fileRead == BUF_SIZE);			
				
					free(buffer);
					
					printf("Done\n");
				}			
				
				fclose(fout);
			}
			
			fclose(fin);
		}	
	}
	
	return 0;
}