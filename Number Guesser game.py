import random
num = int(input("How many chances do you want: "))
for i in range(num):
    y = int(input("Which number do you choose to be"
                  " guessed from 1 to 100:"))
    x = random.randint(1, 100)
    if y == x:
        print("You guessed the number correct")
    else:
        print("The no. you guessed is wrong")
        print(f"the number is {x}")

