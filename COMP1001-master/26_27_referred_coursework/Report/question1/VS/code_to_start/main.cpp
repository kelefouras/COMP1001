/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <emmintrin.h>
#include <limits.h>
#include <pmmintrin.h>
#include <immintrin.h>

//function declarations
void edge_detection( );
void read_image(char* filename);
void write_image2(char* filename);
void openfile(char *filename, FILE** finput);
int getint(FILE *fp);


//CRITICAL POINT: images' paths - You need to change these paths
char IN[] = "C:\\Users\\vboxuser\\source\\repos\\image_processing\\image_processing\\input_images\\a30.pgm";
char OUT[] = "C:\\Users\\vboxuser\\source\\repos\\image_processing\\image_processing\\output_images\\b30.pgm";

//IMAGE DIMENSIONS
#define M_in 1028 //cols of input image
#define N_in 1028 //rows of input image

#define M_out 1028 //cols of output image
#define N_out 1028 //rows of output image


//CRITICAL POINT:these arrays are defined statically. Consider creating these arrays dynamically instead.
unsigned char input_image[N_in * M_in];//input image
unsigned char output_image[N_out * M_out];//output image




char header[100];
errno_t err;

int main( ){

	
 read_image(IN);//read image from disc

 rotate90();


 write_image2(OUT); //store output image to the disc
	

    return 0;
}





//This routine needs to be completed by you
//note that when N,M differ the shape/size of the image changes and thus the write_image routine needs to be updated accordingly. 
void rotate90()
{
    for (int y = 0; y < N_in; y++) {
        for (int x = 0; x < M_in; x++) {

            output_image[y * M_in + x] = input_image[y * M_in + x];
        }
    }
}






void read_image( char* filename)
{

	int c;
	FILE* finput;
	int i, j, temp;

	printf("\nReading %s image from disk ...", filename);
	finput = NULL;
	openfile(filename, &finput);

	if ((header[0] == 'P') && (header[1] == '5')) { //if P5 image

		for (j = 0; j < N_in; j++) {
			for (i = 0; i < M_in; i++) {

				//if (fscanf_s(finput, "%d", &temp,20) == EOF)
				//	exit(EXIT_FAILURE);
				temp = getc(finput);

				input_image[M_in * j + i] = (unsigned char)temp;
			}
		}
	}
	else if ((header[0] == 'P') && (header[1] == '2'))  { //if P2 image
		for (j = 0; j < N_in; j++) {
			for (i = 0; i < M_in; i++) {

				if (fscanf_s(finput, "%d", &temp,20) == EOF)
					exit(EXIT_FAILURE);

				input_image[M_in * j + i] = (unsigned char)temp;
			}
		}
	}
	else {
		printf("\nproblem with reading the image");
		exit(EXIT_FAILURE);
	}

	fclose(finput);
	printf("\nimage successfully read from disc\n");

}



void write_image2( char* filename)
{

	FILE* foutput;
	int i, j;



	printf("  Writing result to disk ...\n");

	if ((err = fopen_s(&foutput,filename, "wb")) != NULL) {
		fprintf(stderr, "Unable to open file %s for writing\n", filename);
		exit(-1);
	}

	fprintf(foutput, "P2\n");
	fprintf(foutput, "%d %d\n", M_out, N_out);
	fprintf(foutput, "%d\n", 255);

	for (j = 0; j < N_out; ++j) {
		for (i = 0; i < M_out; ++i) {
			fprintf(foutput, "%3d ", output_image[M_out * j + i]);
			if (i % 32 == 31) fprintf(foutput, "\n");
		}
		if (M_out % 32 != 0) fprintf(foutput, "\n");
	}
	fclose(foutput);


}




void openfile(char* filename, FILE** finput)
{
	int x0, y0, x , aa;

	if (( err = fopen_s(finput,filename, "rb")) != NULL) {
		fprintf(stderr, "Unable to open file %s for reading\n", filename);
		exit(-1);
	}

	aa = fscanf_s(*finput, "%s", header, 20);

	x0 = getint(*finput);//this is M
	y0 = getint(*finput);//this is N
	printf("\t header is %s, while x=%d,y=%d", header, x0, y0);


	//CRITICAL POINT: AT THIS POINT YOU CAN ASSIGN x0,y0 to M,N 
	// printf("\n Image dimensions are M=%d,N=%d",M,N);


	x = getint(*finput); /* read and throw away the range info */
	//printf("\n range info is %d",x);

}



//CRITICAL POINT: you can define your routines here that create the arrays dynamically; now, the arrays are defined statically.



int getint(FILE* fp) /* adapted from "xv" source code */
{
	int c, i, firstchar;//, garbage;

	/* note:  if it sees a '#' character, all characters from there to end of
	   line are appended to the comment string */

	   /* skip forward to start of next number */
	c = getc(fp);
	while (1) {
		/* eat comments */
		if (c == '#') {
			/* if we're at a comment, read to end of line */
			char cmt[256], * sp;

			sp = cmt;  firstchar = 1;
			while (1) {
				c = getc(fp);
				if (firstchar && c == ' ') firstchar = 0;  /* lop off 1 sp after # */
				else {
					if (c == '\n' || c == EOF) break;
					if ((sp - cmt) < 250) *sp++ = c;
				}
			}
			*sp++ = '\n';
			*sp = '\0';
		}

		if (c == EOF) return 0;
		if (c >= '0' && c <= '9') break;   /* we've found what we were looking for */

		/* see if we are getting garbage (non-whitespace) */
	   // if (c!=' ' && c!='\t' && c!='\r' && c!='\n' && c!=',')
		//	garbage=1;

		c = getc(fp);
	}

	/* we're at the start of a number, continue until we hit a non-number */
	i = 0;
	while (1) {
		i = (i * 10) + (c - '0');
		c = getc(fp);
		if (c == EOF) return i;
		if (c < '0' || c>'9') break;
	}
	return i;
}








