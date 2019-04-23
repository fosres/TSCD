# TSCD
Official Repository for tscd ASCII-Color Encoded Hex Dump For 256-bit ASCII Color-Supporting Terminal Emulators

Introducing tscd:

INSTRUCTIONS TO DOWNLOAD:

Step 1:

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/step_1_download_instructions_jpeg.JPG)

You can also use another command-line utility online download tool, like curl or wget.

Step 2:

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/step_2_download_instructions_jpeg.JPG)

NAME

tscd

SYNOPSIS

tscd [options] [infile [outfile]]

DESCRIPTION

tscd can create a hexadecimal, decimal, binary, or octal dump of any file. The numerical values will be displayed in a table.To the rightmost of each row will be the ASCII characters corresponding to the ASCII codes in the table.

COLOR ENCODINGS

Below is the Color Encoding Scheme (ASCII):

Red: Non-printable ASCII characters

Orange: Printable (Alphabetic) Characters

Yellow: Base 10 Numerical Digits

Green: ASCII Whitespace Characters

Purple: Punctuation Characters

Gray: NUL byte (00)

OPTIONS

-b Binary dump specified. Each character in file will be translated into its binary number form and displayed in the table.

-c Specify number of columns per row in ASCII code table.

-d Decimal Dump specified. Each character in file will be translated into its binary number form and displayed in the table.

-o Octal Dump specified. Each character in file will be translated into its octal number form and displayed in the table.

EXAMPLES

Print simple hexdump of a file to stdout

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/tscd_swiss_jpeg.JPG)



Print simple hexdump of a file where 16 ASCII hexadecimal codes are printed per row to stdout

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/tscd_c_16_swiss_cheese_c_jpeg.JPG)

Print binary dump of a file named tscd4.c to stdout

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/tscd_binary_dump_tscd_4_c_jpeg.JPG)

Print binary dump of a file named tscd4.c to a separate file named target.c

Step 1:

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/step_1_swiss_binary_txt_jpeg.JPG)

Step 2:

![alt text](https://github.com/tanveerasalim/TSCD/blob/master/tscd_swiss_binary_dump_txt_jpeg.JPG)

(The file above is being viewed in vim. No color codes can be encoded into a text file.)

CONTACT ME

All questions, comments, complaints, criticism, and hate mail can be sent to: Tanveer.Salim@ttu.edu


