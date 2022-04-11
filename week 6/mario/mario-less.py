# TODO
from cs50 import get_int

height = 0
while (height > 8 or height < 1):
    height = get_int("Height:\n")

# prints a pyramid of hashes
for i in range(1, height + 1):
    print(" " * (height - i), end="")
    print("#" * (i))
