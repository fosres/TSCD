#if 0
Copyright (C) Tanveer Salim 2018-INFINITY

This software is distributed with a GNU GPL

License v2.0. All are free to copy, share, 
	
	
distribute, and/or modify this software.

All software that was inspired

or is a derivative of this work must have

the exact same LICENSE and copyright permissions.

#endif

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef __rsize_t_defined
typedef size_t rsize_t;
#define __rsize_t_defined 1
#endif

#ifdef __RSIZE_MAX__
#define RSIZE_MAX (__RSIZE_MAX__)
#else

#define RSIZE_MAX ( (SIZE_MAX ) >> ( 1 ) )
#endif


#ifndef __uint8_t_defined
typedef unsigned char uint8_t;
#define __uint8_t_defined 1
#endif

#ifndef __uint32_t_defined
typedef unsigned int uint32_t;
#define __uint32_t_defined 1
#endif


#if 0

Bug: When Number of characters in row

is equal to NUM_HEX_ROWS, the last f

in 0xff is deleted and replaced with

a period.

Bug: Number of columns == Number of bytes per row!

NUM_HEX_ROWS == (desired number of columns)/2

default number of columns: 16 to make 16 bytes displayed in total per row

So:

NUM_HEX_ROWS == Number of desired columns

Simple! :D
#endif
//#define NUM_HEX_ROWS_ORIGINAL 16

rsize_t NUM_HEX_ROWS = 16;

rsize_t NUM_BIN_ROWS = 6;

rsize_t NUM_OCT_ROWS = 12;

rsize_t NUM_DEC_ROWS = 12;

_Bool bintable_request = 0;

_Bool octtable_request = 0;

_Bool dectable_request = 0;

void colorchar(uint8_t c)
{
	
		if ( c == 0x0 )
		{
			printf("\e[38;5;244m");
		}

		else if ( isalpha(c) )
		{
			
			printf("\e[38;5;208m");


		}

		else if ( isdigit(c) )
		{
			printf("\e[38;5;226m");
		}	
	
		else if ( !isprint(c) )
		{
			printf("\e[38;5;196m");
		}

		else if ( isspace(c) )
		{
			printf("\e[38;5;40m");
		}

		else if ( ispunct(c) )
		{
//			printf("\e[38;5;164m");
			
			printf("\e[38;5;201m");
		}

		else if ( c < 16 )
		{
			printf("\e[0;32m");
		}

		else if ( c >= 16 && c <= 31 )
		{
			printf("\e[1;35m");
		}

}

void resetcolor(void)
{
	printf("\033[0m");
}

void reverse(unsigned char s[])
{
  for (int i = 0, j = strlen(s)-1; i < j; i++, j--)
  {
    unsigned char temp = s[i];

    s[i] = s[j];

    s[j] = temp;
  }
}

unsigned char * print_binary(unsigned char input)
{


  static unsigned char s[10];

  unsigned char * s_p = &s[0];

  while (input > 0)
  {
    *s_p++ = (unsigned char)((input&1)+'0');

    input >>= 1;
  }

  *s_p = '\0';
  
  reverse(s);

  return s;

}



void print_bintable2(FILE * in, FILE * out, unsigned char ASCII[], const rsize_t FILE_SIZE)
{
	rsize_t i = 0;
	
	rsize_t u = 0;

	unsigned long fpos = 0;

	rsize_t j = 0; //need this to create printable ASCII in output

	unsigned char c = 0;

	while ( i < FILE_SIZE )
	{
		c = fgetc(in);
		
#if 0

This printf actually forces printing of ASCII.

#endif	
		if ( i == 0 )
		{ colorchar(c); fprintf(out,"%08x:%c",i,0x20); resetcolor(); }
		
		else if ( (i%NUM_BIN_ROWS) == 0  )
		{
				fputc(0x20,out);
				
				if ( i >= NUM_BIN_ROWS )
				{	
				
					fseek(in,-NUM_BIN_ROWS-1,SEEK_CUR);

				}

				else
				{
					fseek(in,0,SEEK_SET);	
				}

				u = 0;				
				
				while ( 
					
					u < NUM_BIN_ROWS

							
				      )
				{
					( c = fgetc(in) );	
					
					colorchar(c);

					if ( isprint(c) )
					{	
						fputc(c,out);
					}

					else
					{
						fprintf(out,"\u00b7");
					}

					u++;

					resetcolor();
				}

				c = fgetc(in); //catch up to latest row


				colorchar(c);

				fprintf(out,"\n%08x:%c",i,0x20);

				resetcolor();	
		}
		
		colorchar(c);

		fprintf(out,"%08s%c",print_binary(c),0x20);

		resetcolor();

#if 0	
		(i%2 == 0) ? ( fprintf(out,"%08s",print_binary(c)) ) : ( fprintf(out,"%08s%c",print_binary(c),0x20) );

#endif		
		i++;	
		

		// Bug: Write code to place ff and extra spaces to align last ASCII line here
	}

		if ( i == FILE_SIZE )
		{
			rsize_t index = i;

			while ( index % NUM_BIN_ROWS != 0 ) 
			{
				
				
				(index%2 == 0) 
					
					? 
					
					( fprintf(out,"%*c",0x9,0x20) ) 
					
					: 
					
					( fprintf(out,"%*c",0x9,0x20) );
				
				index++;
			}
#if 0

This while loop is meant for

a line that is equal to

NUM_BIN_ROWS

#endif	

			if ( index % NUM_BIN_ROWS == 0 )
			{
				fputc(0x20,out);
			}	
	
		}

	

	if ( i == FILE_SIZE && (i%NUM_BIN_ROWS) != 0  )
	{

				rsize_t space_align = i;
				
				fpos = ftell(in);
				
				fseek(in,-(i%NUM_BIN_ROWS),SEEK_CUR);

				u = 0;				
				
				while ( 
					
					u < ( i%NUM_BIN_ROWS )

				      )
				{
					( c = fgetc(in) );	
					
					colorchar(c);	

					if ( isprint(c) )
					{	
						fputc(c,out);
					}

					else
					{
						fprintf(out,"\u00b7");
					}

					u++;

					resetcolor();
				}

				fseek(in,fpos,SEEK_SET);
			
	}
	
	else // ( i == FILE_SIZE && (i%NUM_BIN_ROWS) == 0  )
	{

				rsize_t space_align = i;
				
				fpos = ftell(in);
				
				fseek(in,-(NUM_BIN_ROWS),SEEK_CUR);

				u = 0;				
				
				while ( 
					
					u < ( NUM_BIN_ROWS )

				      )
				{
					( c = fgetc(in) );	

					colorchar(c);
					
					if ( isprint(c) )
					{	
						fputc(c,out);
					}

					else
					{
						fprintf(out,"\u00b7");
					}

					u++;

					resetcolor();
				}

				fseek(in,fpos,SEEK_SET);
			
	}

}

void print_dectable(FILE * in, FILE * out, unsigned char ASCII[], const rsize_t FILE_SIZE)
{
	rsize_t i = 0;
	
	rsize_t u = 0;

	unsigned long fpos = 0;

	rsize_t j = 0; //need this to create printable ASCII in output

	unsigned char c = 0;

	while ( i < FILE_SIZE )
	{
		c = fgetc(in);

		colorchar(c);	
#if 0

This printf actually forces printing of ASCII.

#endif	

		if ( i == 0 )
		{ fprintf(out,"%08x:%c",i,0x20); }


		else if ( (i%NUM_DEC_ROWS) == 0  )
		{
				fputc(0x20,out);
				
				if ( i >= NUM_DEC_ROWS )
				{	
				
					fseek(in,-NUM_DEC_ROWS-1,SEEK_CUR);

				}

				else
				{
					fseek(in,0,SEEK_SET);	
				}

				u = 0;				
				
				while ( 
					
					u < NUM_DEC_ROWS

							
				      )
				{
					( c = fgetc(in) );	

					colorchar(c);
					
					if ( isprint(c) )
					{	
						fputc(c,out);
					}

					else
					{
						fprintf(out,"\u00b7");
					}

					u++;

					resetcolor();
				}

				c = fgetc(in); //catch up to latest row

				colorchar(c);
				
				fprintf(out,"\n%08x:%c",i,0x20);
				
				resetcolor();	
		}

		colorchar(c);

		
		(i%1 != 0) ? ( fprintf(out,"%03u",c) ) : ( fprintf(out,"%c%03u",0x20,c) );
		
		i++;	
		
		resetcolor();

		// Bug: Write code to place ff and extra spaces to align last ASCII line here
	}

		if ( i == FILE_SIZE )
		{
			rsize_t index = i;

			while ( index % NUM_DEC_ROWS != 0 ) 
			{
				
				
				(index%2 == 0) 
					
					? 
					
					( fprintf(out,"%c%c%c%c",0x20,0x20,0x20,0x20) ) 
					
					: 
					
					( fprintf(out,"%c%c%c%c",0x20,0x20,0x20,0x20) );
				
				index++;
			}
#if 0

This while loop is meant for

a line that is equal to

NUM_DEC_ROWS

#endif	

			if ( index % NUM_DEC_ROWS == 0 )
			{
				fputc(0x20,out);
			}	
	
		}

	

	if ( i == FILE_SIZE && (i%NUM_DEC_ROWS) != 0  )
	{

				rsize_t space_align = i;
				
				fpos = ftell(in);
				
				fseek(in,-(i%NUM_DEC_ROWS),SEEK_CUR);

				u = 0;				
				
				while ( 
					
					u < ( i%NUM_DEC_ROWS )

				      )
				{
					( c = fgetc(in) );	
					
					colorchar(c);

					if ( isprint(c) )
					{	
						fputc(c,out);
					}

					else
					{
						fprintf(out,"\u00b7");
					}

					u++;

					resetcolor();
				}

				fseek(in,fpos,SEEK_SET);
			
	}
	
	else // ( i == FILE_SIZE && (i%NUM_DEC_ROWS) == 0  )
	{

				rsize_t space_align = i;
				
				fpos = ftell(in);
				
				fseek(in,-(NUM_DEC_ROWS),SEEK_CUR);

				u = 0;				
				
				while ( 
					
					u < ( NUM_DEC_ROWS )

				      )
				{
					( c = fgetc(in) );	
					
					colorchar(c);

					if ( isprint(c) )
					{	
						fputc(c,out);
					}

					else
					{
						fprintf(out,"\u00b7");
					}

					u++;

					resetcolor();
				}

				fseek(in,fpos,SEEK_SET);
			
	}

}

void print_octtable(FILE * in, FILE * out, unsigned char ASCII[], const rsize_t FILE_SIZE)
{
	rsize_t i = 0;
	
	rsize_t u = 0;

	unsigned long fpos = 0;

	rsize_t j = 0; //need this to create printable ASCII in output

	unsigned char c = 0;

	while ( i < FILE_SIZE )
	{
		c = fgetc(in);

		colorchar(c);	
#if 0

This printf actually forces printing of ASCII.

#endif	

		if ( i == 0 )
		{ fprintf(out,"%08x:%c",i,0x20); }


		else if ( (i%NUM_OCT_ROWS) == 0  )
		{
				fputc(0x20,out);
				
				if ( i >= NUM_OCT_ROWS )
				{	
				
					fseek(in,-NUM_OCT_ROWS-1,SEEK_CUR);

				}

				else
				{
					fseek(in,0,SEEK_SET);	
				}

				u = 0;				
				
				while ( 
					
					u < NUM_OCT_ROWS

							
				      )
				{
					( c = fgetc(in) );	

					colorchar(c);
					
					if ( isprint(c) )
					{	
						fputc(c,out);
					}

					else
					{
						fprintf(out,"\u00b7");
					}

					u++;

					resetcolor();
				}

				c = fgetc(in); //catch up to latest row

				colorchar(c);
				
				fprintf(out,"\n%08x:%c",i,0x20);
				
				resetcolor();	
		}

		colorchar(c);

		
		(i%1 != 0) ? ( fprintf(out,"%03o",c) ) : ( fprintf(out,"%c%03o",0x20,c) );
		
		i++;	
		
		resetcolor();

		// Bug: Write code to place ff and extra spaces to align last ASCII line here
	}

		if ( i == FILE_SIZE )
		{
			rsize_t index = i;

			while ( index % NUM_OCT_ROWS != 0 ) 
			{
				
				
				(index%2 == 0) 
					
					? 
					
					( fprintf(out,"%c%c%c%c",0x20,0x20,0x20,0x20) ) 
					
					: 
					
					( fprintf(out,"%c%c%c%c",0x20,0x20,0x20,0x20) );
				
				index++;
			}
#if 0

This while loop is meant for

a line that is equal to

NUM_OCT_ROWS

#endif	

			if ( index % NUM_OCT_ROWS == 0 )
			{
				fputc(0x20,out);
			}	
	
		}

	

	if ( i == FILE_SIZE && (i%NUM_OCT_ROWS) != 0  )
	{

				rsize_t space_align = i;
				
				fpos = ftell(in);
				
				fseek(in,-(i%NUM_OCT_ROWS),SEEK_CUR);

				u = 0;				
				
				while ( 
					
					u < ( i%NUM_OCT_ROWS )

				      )
				{
					( c = fgetc(in) );	
					
					colorchar(c);

					if ( isprint(c) )
					{	
						fputc(c,out);
					}

					else
					{
						fprintf(out,"\u00b7");
					}

					u++;

					resetcolor();
				}

				fseek(in,fpos,SEEK_SET);
			
	}
	
	else // ( i == FILE_SIZE && (i%NUM_OCT_ROWS) == 0  )
	{

				rsize_t space_align = i;
				
				fpos = ftell(in);
				
				fseek(in,-(NUM_OCT_ROWS),SEEK_CUR);

				u = 0;				
				
				while ( 
					
					u < ( NUM_OCT_ROWS )

				      )
				{
					( c = fgetc(in) );	
					
					colorchar(c);

					if ( isprint(c) )
					{	
						fputc(c,out);
					}

					else
					{
						fprintf(out,"\u00b7");
					}

					u++;

					resetcolor();
				}

				fseek(in,fpos,SEEK_SET);
			
	}

}

void print_hextable(FILE * in, FILE * out, unsigned char ASCII[], const rsize_t FILE_SIZE)
{
	rsize_t i = 0;
	
	rsize_t u = 0;

	unsigned long fpos = 0;

	rsize_t j = 0; //need this to create printable ASCII in output

	unsigned char c = 0;

	while ( i < FILE_SIZE )
	{
		c = fgetc(in);

		colorchar(c);	
#if 0

This printf actually forces printing of ASCII.

#endif	

		if ( i == 0 )
		{ fprintf(out,"%08x:%c",i,0x20); }


		else if ( (i%NUM_HEX_ROWS) == 0  )
		{
				fputc(0x20,out);
				
				if ( i >= NUM_HEX_ROWS )
				{	
				
					fseek(in,-NUM_HEX_ROWS-1,SEEK_CUR);

				}

				else
				{
					fseek(in,0,SEEK_SET);	
				}

				u = 0;				
				
				while ( 
					
					u < NUM_HEX_ROWS

							
				      )
				{
					( c = fgetc(in) );	

					colorchar(c);
					
					if ( isprint(c) )
					{	
						fputc(c,out);
					}

					else
					{
						fprintf(out,"\u00b7");
					}

					u++;

					resetcolor();
				}

				c = fgetc(in); //catch up to latest row

				colorchar(c);
				
				fprintf(out,"\n%08x:%c",i,0x20);
				
				resetcolor();	
		}

		colorchar(c);

		
		(i%1 != 0) ? ( fprintf(out,"%02x",c) ) : ( fprintf(out,"%c%02x",0x20,c) );
		
		i++;	
		
		resetcolor();

		// Bug: Write code to place ff and extra spaces to align last ASCII line here
	}

		if ( i == FILE_SIZE )
		{
			rsize_t index = i;

			while ( index % NUM_HEX_ROWS != 0 ) 
			{
				
				
				(index%2 == 0) 
					
					? 
					
					( fprintf(out,"%c%c%c",0x20,0x20,0x20) ) 
					
					: 
					
					( fprintf(out,"%c%c%c",0x20,0x20,0x20) );
				
				index++;
			}
#if 0

This while loop is meant for

a line that is equal to

NUM_HEX_ROWS

#endif	

			if ( index % NUM_HEX_ROWS == 0 )
			{
				fputc(0x20,out);
				
			}	
	
		}

	

	if ( i == FILE_SIZE && (i%NUM_HEX_ROWS) != 0  )
	{

				rsize_t space_align = i;
				
				fpos = ftell(in);
				
				fseek(in,-(i%NUM_HEX_ROWS),SEEK_CUR);

				u = 0;				
				
				while ( 
					
					u < ( i%NUM_HEX_ROWS )

				      )
				{
					( c = fgetc(in) );	
					
					colorchar(c);

					if ( isprint(c) )
					{	
						fputc(c,out);
					}

					else
					{
						fprintf(out,"\u00b7");
					}

					u++;

					resetcolor();
				}

				fseek(in,fpos,SEEK_SET);
			
	}
	
	else // ( i == FILE_SIZE && (i%NUM_HEX_ROWS) == 0  )
	{

				rsize_t space_align = i;
				
				fpos = ftell(in);
				
				fseek(in,-(NUM_HEX_ROWS),SEEK_CUR);

				u = 0;				
				
				while ( 
					
					u < ( NUM_HEX_ROWS )

				      )
				{
					( c = fgetc(in) );	
					
					colorchar(c);

					if ( isprint(c) )
					{	
						fputc(c,out);
					}

					else
					{
						fprintf(out,"\u00b7");
					}

					u++;

					resetcolor();
				}

				fseek(in,fpos,SEEK_SET);
			
	}

}

#if 0
Last argument, argument index

argc-1, must have filename
#endif

int main(int argc, char ** argv)
{

	FILE * in = NULL;

	FILE * out = stdout;

	if ( argc < 2 )
	{
		fprintf(in,"%llu: Less than two arguments!\n",__LINE__);

		return 1;
	}
	
	if ( ( (argc-2) > 0 ) && ( ( in = fopen(argv[argc-2],"rb") ) != NULL ) )
	{
		if ( ( out = fopen(argv[argc-1],"wb+") ) == NULL )
		{
			fprintf(stderr,"\033[1;31m\n\0");	
		
			fprintf(stdout,"%llu: Failed to write to file %s!\n",__LINE__,argv[argc-1]);

			fprintf(stderr,"\033[0m\n\0");

			return 1;
		}


	}
	
	else if ( ( in = fopen(argv[argc-1],"rb") ) == NULL )
	{
		fprintf(stderr,"\033[1;31m\n\0");	
		
		fprintf(stdout,"%llu: Failed to open file!\n",__LINE__);

		fprintf(stderr,"\033[0m\n\0");

		return 1;
	}
	
	fseek(in,0L,SEEK_END);

	const rsize_t SIZE = ftell(in);

	static unsigned char * ascii_line; 
	
	ascii_line = (unsigned char *)calloc(NUM_HEX_ROWS+1,sizeof(unsigned char));

	rewind(in);

	while ( *++argv != NULL && **argv == 0x2d )
	{
		switch ( *++(*argv)  )
		{
			
			case 0x63:
				{
					// get column number

					char const * column_num = *++argv; 

					while ( isdigit( *(*argv) ) != 0 )
					{	(*argv)++;	}

					if ( **argv != 0x0 )
					{
						
						fprintf(stderr,"\033[1;31m\n\0");	

						fprintf(stderr,"%llu: Error! Column"
								" argument is not a" 
								" type of unsigned"
								" integer!\n",
						        __LINE__
						       );

						fprintf(stderr,"\033[0m\n\0");

						return 1;
					}



					NUM_HEX_ROWS = (rsize_t)strtol(column_num,NULL,10);

					free(ascii_line);

					ascii_line = (unsigned char *)calloc(NUM_HEX_ROWS,sizeof(unsigned char));

					NUM_BIN_ROWS = (rsize_t)strtol(column_num,NULL,10);

					NUM_OCT_ROWS = (rsize_t)strtol(column_num,NULL,10);

					NUM_DEC_ROWS = (rsize_t)strtol(column_num,NULL,10);

					break;
				}

			case 0x62:
				{
					bintable_request = 1;	

					free(ascii_line);

					ascii_line = (unsigned char *)calloc(NUM_BIN_ROWS+1,sizeof(unsigned char));
					
					break;
				}

			case 0x64:
				{
					dectable_request = 1;

					free(ascii_line);					
					ascii_line = (unsigned char *)calloc(NUM_DEC_ROWS+1,sizeof(unsigned char));

					break;
				}
			
			case 0x6f: 
				{
					octtable_request = 1;	
					
					free(ascii_line);
					
					ascii_line = (unsigned char *)calloc(NUM_OCT_ROWS+1,sizeof(unsigned char));

					break;
				}	
			



			default:
				{
					break;
				}
		}	

	}

	if ( dectable_request == 1 )
	{
		print_dectable(in,out,ascii_line,SIZE);
	}

	else if ( octtable_request == 1 )
	{
		print_octtable(in,out,ascii_line,SIZE);
	}	
	
	else if ( bintable_request == 1 )
	{ 
		print_bintable2(in,out,ascii_line,SIZE);
	}

	else
	{
		print_hextable(in,out,ascii_line,SIZE);
	}

	if ( fclose(in) == EOF )
	{
		fprintf(stderr,"\033[1;31m\n\0");	
		
		fprintf(stderr,"%llu: Error! Failed to close %s\n",__LINE__,argv[argc-1]);

		fprintf(stderr,"\033[0m\n\0");
		
		return 1;
	}
	
	if ( fclose(out) == EOF )
	{
		fprintf(stderr,"\033[1;31m\n\0");	
		
		fprintf(stderr,"%llu: Error! Failed to close %s\n",__LINE__,argv[argc-1]);

		fprintf(stderr,"\033[0m\n\0");
		
		return 1;
	}
	

	return 0;
}
