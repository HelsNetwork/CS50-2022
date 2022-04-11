# TODO
from cs50 import get_string
from math import floor

AE1 = "34"
AE2 = "37"
MC1 = "51"
MC2 = "52"
MC3 = "53"
MC4 = "54"
MC5 = "55"
Visa = "4"
brand = "INVALID"

# get and clean the input from the user
card = get_string("Number: ")
card = card.strip()
count = len(card)

if (count == 13):
    if (card[:1] == Visa):
        brand = "VISA"

elif (count == 15):
    if (card[:2] == AE1 or card[:2] == AE2):
        brand = "AMEX"

elif (count == 16):
    if (card[:2] == MC1 or card[:2] == MC2 or card[:2] == MC3 or card[:2] == MC4 or card[:2] == MC5):
        brand = "MASTERCARD"

    elif (card[:1] == Visa):
        brand = "VISA"

if (brand != "INVALID"):
    card = int(card)
    last = 0
    tempx = 0
    secToLast = 0

    while (card > 0):
        last += card % 10

        card /= 10
        card = floor(card)

        tempx = (card % 10) * 2

        if (tempx >= 10):
            secToLast += tempx % 10
            tempx /= 10
            secToLast += floor(tempx)

        else:
            secToLast += tempx

        card /= 10
        card = floor(card)

    if ((last + secToLast) % 10 == 0):
        print(brand)

    else:
        print("INVALID")
else:
    print(brand)
