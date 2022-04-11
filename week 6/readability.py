# TODO
from cs50 import get_string

text = get_string("Text: \n")

letters = 0
words = 0
sentences = 0
counter = 0

for i in text:
    counter += 1

for i in range(counter):

    if (ord(text[i]) >= 65 and ord(text[i]) <= 122):
        letters += 1

        elif (ord(text[i]) == 32 and (ord(text[i - 1]) != 33 and ord(text[i - 1]) != 46 and ord(text[i - 1]) != 63)):
        words += 1

        elif (ord(text[i]) == 33 or ord(text[i]) == 46 or ord(text[i]) == 63):
        sentences += 1
        words += 1

L = letters * 100 / words
S = sentences * 100 / words

index = round(0.0588 * L - 0.296 * S - 15.8)


if (index < 1):
    print("Before Grade 1")

elif (index >= 16):
    print("Grade 16+")

else:
    print(f"Grade {index}")
