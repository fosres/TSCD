# TSCD
Official Repository for tscd ASCII-Color Encoded Hex Dump

Introducing tscd:

NAME

tscd

SYNOPSIS

tscd [options] [infile [outfile]]

DESCRIPTION

tscd can create a hexadecimal, decimal, binary, or octal dump of any file. The numerical values will be displayed in a table.To the rightmost of each row will be the ASCII characters corresponding to the ASCII codes in the table.

OPTIONS

-b Binary dump specified. Each character in file will be translated into its binary number form and displayed in the table.

-c Specify number of columns per row in ASCII code table.

-d Decimal Dump specified. Each character in file will be translated into its binary number form and displayed in the table.

-o Octal Dump specified. Each character in file will be translated into its octal number form and displayed in the table.

EXAMPLES

Print simple hexdump of a file to stdout

% tscd swiss.txt

00000000:  49 20 6c 69 6b 65 20 63 68 65 65 73 65 73 2e 0a I like cheeses.·⏎


Print simple hexdump of a file where 20 ASCII hexadecimal codes are printed per row to stdout

% tscd -c 20 swiss_cheese.c

00000000:  49 20 6c 69 6b 65 20 63 6f 6f 6b 69 65 73 2e 0a 0a 49 20 6c I like cookies.··I l
00000014:  69 6b 65 20 63 6f 6f 6b 69 65 73 2e 0a 0a 49 20 6c 69 6b 65 ike cookies.··I like
00000028:  20 63 6f 6f 6b 69 65 73 2e 0a 0a 49 20 6c 69 6b 65 20 63 6f  cookies.··I like co
0000003c:  6f 6b 69 65 73 2e 0a 0a 49 20 6c 69 6b 65 20 63 6f 6f 6b 69 okies.··I like cooki
00000050:  65 73 2e 0a 0a 49 20 6c 69 6b 65 20 63 6f 6f 6b 69 65 73 2e es.··I like cookies.
00000064:  0a 
\end{minted}

Print binary dump of a file named tscd4.c to a separate file named target.c

% tscd -b swiss.txt swiss_binary_dump.txt






