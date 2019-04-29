#if 0
tscd: A 256-bit ASCII Color Encoded Hexdump Program
Copyright (C) 2019 Tanveer Salim 

Email: Tanveer.Salim@ttu.edu

Mail:
Tanveer Salim
131A Bledsoe - TTU
Lubbock, TX, 79406-0016

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#endif

#include <stdio.h>

int main(void)
{

#if 0
	printf("\e[38;5;196m"); //Red
	
	putchar(0xa);putchar(0xa);

	printf("Red: Non-printable ASCII characters\n\n");
	
	printf("\e[0m");

	printf("\e[38;5;208m"); //Orange

	printf("Orange: Printable (Alphabetic) Characters\n\n");

	printf("\e[0m");

	printf("\e[38;5;226m"); //Yellow

	printf("Yellow: Base 10 Numerical Digits\n\n");

	printf("\e[0m");

	printf("\e[38;5;40m");

	printf("Green: ASCII Whitespace Characters\n\n");

	printf("\e[0m");

	printf("\e[38;5;201m"); //Purple

	printf("Purple: Punctuation Characters\n\n");

	printf("\e[0m");

	printf("\e[38;5;244m");

	printf("Gray: NUL byte (00)\n\n");
	
	printf("\e[0m");
#endif
	
	printf("\n\n\t\t\t");

	printf("\e[38;5;196m"); //Red
	
	putchar('T');	

	printf("\e[0m");
	
	printf("\e[38;5;208m"); //Orange
	
	putchar('S');

	printf("\e[0m");

	printf("\e[38;5;226m"); //Yellow
	
	putchar('C');
	
	printf("\e[0m");

	printf("\e[38;5;201m"); //Purple
	
	putchar('D');

	printf("\e[0m");

	printf("\n\n");

	return 0;
}
