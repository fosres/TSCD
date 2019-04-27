# TSCD Hex Dump

![alt text](https://img.shields.io/badge/build-passing-brightgreen.svg)

![alt text](https://img.shields.io/badge/License-GNU%20GPL%20v2.0-brightgreen.svg)


Introducing `tscd`: A Hex Dump For 256-bit ASCII Color-Supporting Terminal Emulators

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/pics/tscd_demo.gif)


## SUPPORTED TERMINAL EMULATORS

For 256-bit ASCII Color-Supporting Terminal Emulators

e.g.: xterm-256

## Download Instructions

### Command Line Instructions:

#### Step 1

```bash
aria2c https://raw.githubusercontent.com/tanveerasalim/TSCD/master/src/tscd6.c
```

#### Step 2

```bash
gcc tscd6.c -o tscd

mv tscd /usr/local/bin
```

#### Step 3 (Optional)

SHA CHECKSUMS (text file of SHA1, SHA256, and SHA512 checksums in shasums.txt):

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/sha/shasums_new_jpeg.JPG)

## Manual

### NAME

tscd

### SYNOPSIS

tscd [options] [infile [outfile]]

### DESCRIPTION

tscd can create a hexadecimal, decimal, binary, or octal dump of any file. The numerical values will be displayed in a table.To the rightmost of each row will be the ASCII characters corresponding to the ASCII codes in the table.

### COLOR ENCODINGS

#### Below is The Color Encoding Scheme (ASCII):

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/pics/ascii_color_encoding_scheme_jpeg.JPG)

### OPTIONS

-b Binary dump specified. Each character in file will be translated into its binary number form and displayed in the table.

-c Specify number of columns per row in ASCII code table.

-d Decimal Dump specified. Each character in file will be translated into its binary number form and displayed in the table.

-o Octal Dump specified. Each character in file will be translated into its octal number form and displayed in the table.

-p Print view specified. tscd will simply print the contents of the file directly intointo stdout.


## EXAMPLES

Print simple hexdump of a file to stdout

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/pics/tscd_swiss_jpeg.JPG)



Print simple hexdump of a file where 16 ASCII hexadecimal codes are printed per row to stdout

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/pics/tscd_c_16_swiss_cheese_c_jpeg.JPG)

Print binary dump of a file named tscd4.c to stdout

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/pics/tscd_binary_dump_tscd_4_c_jpeg.JPG)

Print binary dump of a file named swiss.txt where up to four binary octects appear per row, to stdout

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/pics/tscd_binary_dump_column_4_swiss_txt_jpeg.JPG)

Print binary dump of a file named swiss.txt to a separate file named swiss_binary_dump.txt

### Step 1:

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/pics/step_1_swiss_binary_txt_jpeg.JPG)

### Step 2:

(The file below is being viewed in vim. No color codes can be encoded into a text file.)

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/pics/tscd_swiss_binary_dump_txt_jpeg.JPG)

## CONTACT ME

All questions, comments, compliments, complaints, criticism, and hate mail can be sent to: Tanveer.Salim@ttu.edu

## LICENSE STATEMENT AND COPYLEFT PERMISSIONS

NOTICE: All the software in this repository

comes with absolutely

NO WARRANTY and provided "as is" basis.

Copyright (C) Tanveer Salim 2018-INFINITY

This software and all other software in this

repository is distributed with a GNU GPL

License v2.0. All are free to copy, share, 
	
	
distribute, and/or modify this software,
	
even commercially as long as it compliant

with GNU GPL v2.0 LICENSING terms as well

as the terms of this copyright and license

statement.

All software that was inspired

or is a derivative of this work must have

the exact same LICENSE and copyright permissions.





