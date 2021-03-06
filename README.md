# 42-printf

### Final Grade

**125/100**

A 42 Project. A partial reimplementation of printf in C from the standard library. Submitted and passed the Moulinette including all bonuses.

### Overview

A partial reimplementation of the printf in C. Handles the following conversions.

| Conversion | Short Description                                                                             |
|------------|-----------------------------------------------------------------------------------------------|
| %c         | Print a single character.                                                                     |
| %s         | Print a string of characters.                                                                 |
| %p         | The void * pointer argument is printed in hexadecimal.                                        |
| %d         | Print a decimal (base 10) number.                                                             |
| %i         | Print an integer in base 10.                                                                  |
| %u         | Print an unsigned decimal (base 10) number.                                                   |
| %x         | Print a number in hexadecimal (base 16), with lowercase.                                      |
| %X         | Print a number in hexadecimal (base 16), with uppercase.                                      |
| %%         | Print a percent sign.                                                                         |

See the subject.pdf for further details.

### Dependency

Requires the libft library to run. The full libft is in the subdirectory `libft/`. This includes src folder, Makefile, etc. Libft will be compiled through recursive invocation of make.

### Bonus

Handles the additional flags as described below. This is only a short description. For long description, see the man file for printf. In particular, a number of odd corner cases that need to be covered to match the inbuilt implementation of `printf` has not been described here in detail.

| Characters | Modifier             | Short Description                                                                                                        |
|------------|----------------------|--------------------------------------------------------------------------------------------------------------------------|
| 1234567890 | Minimum Field Width  | The minimum number of chars the field should occupy. Pad out to this size if it is smaller.                              |
| -          | Negative Field Width | Pads on the right rather than the left (ie 'left aligns').                                                               |
| 0          | Zero Padding         | Pads with zeros rather than spaces.                                                                                      |
| .          | Precision            | Minimum precision of a numeric value. Ie adds leading zeros.                                                             |
| #          | Alternate mode       | Renders in alternate mode (the only applicable one to the conversions handled is to prefix certain conversions with 0x). |
|  (space)   | Leading space        | For numeric conversions. If number is positive add leading space.                                                        |
| +          | Leading sign         | For numeric conversions. If number is positive add leading `+` char.                                                     |

### Branch description

| Branch | Description                                                                          |
|--------|--------------------------------------------------------------------------------------|
| main   | Main branch. Contains the repo contents as at (or close to the state) at submission. |
| dev    | Development branch. Was used to code the main feature set of the mandatory behavior. |
| bonus  | Bonus branch. Used to work on the bonus content.                                     |
