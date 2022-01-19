# 42-printf

A partial reimplementation of the printf in C. Handles only the following conversions.

| Conversion | Short Description                                                                             |
|------------|-----------------------------------------------------------------------------------------------|
| %c         | Print a single character.                                                                     |
| %s         | Print a string of characters.                                                                 |
| %p         | The void * pointer argument is printed in hexadecimal. • %d print a decimal (base 10) number. |
| %i         | Print an integer in base 10.                                                                  |
| %u         | Print an unsigned decimal (base 10) number.                                                   |
| %x         | Print a number in hexadecimal (base 16), with lowercase.                                      |
| %X         | Print a number in hexadecimal (base 16), with uppercase.                                      |
| %%         | Print a percent sign.                                                                         |

See the subject.pdf for further details.

### Dependency

Requires the libft library to run. The full libft should be placed in the subdirectory `libft/`. This includes src folder, Makefile, etc. Libft will be compiled through recursive invocation of make.

### Branch description

| Branch | Description                                                                          |
|--------|--------------------------------------------------------------------------------------|
| main   | Main branch. Contains the repo contents as at (or close to the state) at submission. |
| dev    | Development branch. Was used to code the main feature set of the mandatory behavior. |
| bonus  | Bonus branch. Used to work on the bonus content.                                     |
