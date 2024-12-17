# Tokenizer Lab Code

This repository contains two versions of a C program that tokenizes input from a file into identifiers, numbers, and special characters. 

## Description

- **Lab01.c**:  
   The initial version implemented during the lab session. This version is functional but has some limitations, such as fixed buffer sizes and less efficient memory handling.

- **UpdatedLab01.c**:  
   An optimized version with the following enhancements:
   - **Dynamic memory allocation** with `realloc` to handle larger input files safely.
   - Replaced inefficient functions like `strncat` with direct buffer indexing.
   - Added checks to prevent buffer overflows.
   - Improved maintainability and readability using cleaner code practices.

---

## How to Compile and Run

To compile and run either version, follow these steps:

1. Open a terminal in the directory containing the code files.
2. Use the `gcc` compiler to compile the program:

   For the **Lab01 version**:
   ```bash
   gcc Lab01.c -o Lab01
   ./Lab01
   ```

   For the **UpdatedLab01 version**:
   ```bash
   gcc UpdatedLab01.c -o UpdatedLab01
   ./UpdatedLab01
   ```

3. Ensure you have the required input files (`input.txt` or `inputx.txt`) in the same directory, as the program reads input from these files and writes output to `output.txt` or `outputx.txt`.

---

## Input and Output Example

### Sample Input (`input.txt`):
```
int main() {    
	int a, b, c;
	b= 10;
	c= 5;
	a = b+c;
	printf("%d", a);
}
```

### Output (`output.txt`):
```
int
main
(
)
{
int
a
,
b
,
c
;
b
=
10
;
c
=
5
;
a
=
b
+
c
;
printf
(
"
%
d
"
,
a
)
;
}
```

### Alternate Input (`inputx.txt`):
```
#include <stdio.h>
int main() {
    double a, b, product;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);  
 
    // Calculating product
    product = a * b;

    // %.2lf displays number up to 2 decimal point
    printf("Product = %.2lf", product);
    
    return 0;
}
```

### Output (`outputx.txt`):
```
#
include
<
stdio
.
h
>
int
main
(
)
{
double
a
,
b
,
product
;
printf
(
"
Enter
two
numbers
:
"
)
;
scanf
(
"
%
lf
%
lf
"
,
&
a
,
&
b
)
;
/
/
Calculating
product
product
=
a
*
b
;
/
/
%
.
2
lf
displays
number
up
to
2
decimal
point
printf
(
"
Product
=
%
.
2
lf
"
,
product
)
;
return
0
;
}
```

---

## File Structure

```
📆 LexicalAnalysis
├── Lab01.c                # Original version of the code
├── UpdatedLab01.c          # Optimized version with improvements
├── input.txt              # First input file for testing
├── output.txt             # First output file generated by Lab01
├── inputx.txt             # Alternate input file for testing
├── outputx.txt            # Alternate output file generated by UpdatedLab01
├── README.md              # Documentation file (this file)
```

---

## Why Two Versions?

The two versions demonstrate the process of improving a working program by:
- Identifying limitations in the original implementation.
- Applying better memory management and coding practices.
- Ensuring the program is more efficient, scalable, and maintainable.

---

## Author

- **[Your Name]**  
Feel free to reach out for any suggestions or questions!

### Contact Me
- **LinkedIn**: [Shakhawat Hossain](https://linkedin.com/in/shawal061)
- **Email**: [Shakhawat Hossain](mailto:u1904061@student.cuet.ac.bd)