# TSCD Hex Dump

![](https://github.com/tanveerasalim/TSCD/blob/master/pics/tscd_logo_jpeg.JPG)

![](https://img.shields.io/badge/price-free-blue.svg) ![](https://img.shields.io/badge/build-passing-brightgreen.svg) ![](https://img.shields.io/badge/License-GNU%20GPL%20v2.0-brightgreen.svg) [![Github All Releases](https://img.shields.io/github/downloads/tanveerasalim/TSCD/total.svg)]()


Introducing `tscd`: A Hex Dump For 256-bit ASCII Color-Supporting Terminal Emulators

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/pics/tscd_demo.gif)


## SUPPORTED PLATFORMS/TERMINALS

* CYGWIN on Windows

* macOS-Terminal

* macOS-iTerm2

* All Linux Terminal Emulators

## Download Options

### Option 1 - Using aria2c:

#### Step 1

```bash
aria2c https://raw.githubusercontent.com/tanveerasalim/TSCD/master/src/tscd6.c
```

#### Step 2

```bash
gcc tscd6.c -o tscd

mv tscd /usr/local/bin
```

### Option 2 - Cloning Into Repository:

#### Step 1

```bash
git clone https://github.com/tanveerasalim/TSCD.git

```

#### Step 2

```bash
cd TSCD/

cd src/

gcc tscd6.c -o tscd

sudo cp tscd /usr/local/bin
```

### Option 3 - Use Install Script After Git Clone:

NOTE: Will NOT Work in CYGWIN

#### Step 1

```bash
git clone https://github.com/tanveerasalim/TSCD.git
```

#### Step 2

```bash
cd TSCD/

sudo chmod u+x install.sh

./install.sh
```

### (Optional: Verify SHA Checksums)

SHA CHECKSUMS (text file of SHA1, SHA256, and SHA512 checksums in shasums.txt):

#### SHA1SUM

```bash
1c4d47967e12dfb8d824b3c380b304af9a70adef *tscd6.c
```
#### SHA256SUM

```bash
b6d3024cf3c8802ffc4c5d64b5004d282a5328e00abb20e6c771ea57b42f7230 *tscd6.c
```

#### SHA512SUM

```bash
be29d2ea8c2c01b043853d1ab366bc2ba0458e3ef9842924de87220e3434b881d639a6f5154a4d407e81b3076acc9b9a66903fe9c9dc5e1a88e2444f6533ad93 *tscd6.c
```

## Manual

### NAME

tscd

### SYNOPSIS

tscd [options] [infile [outfile]]

### DESCRIPTION

tscd can create a hexadecimal, decimal, binary, or octal dump of any file. The numerical values will be displayed in a table.To the rightmost of each row will be the ASCII characters corresponding to the ASCII codes in the table.

### COLOR ENCODINGS

#### Below Is The Color Encoding Scheme (ASCII):

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/pics/ascii_color_encoding_scheme_jpeg.JPG)

### OPTIONS

-b Binary dump specified. Each character in file will be translated into its binary number form and displayed in the table.

-c [Number of Columns] Specify number of columns per row in ASCII code table.

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





