# Write a program that asks the user for their name and greets them with their name.
# Modify the previous program such that only the users Alice and Bob are greeted with their names.

name = input("what is your name?")

vip = ["Alice", "Bob"]

for i in vip:
    if i == name:
        print("Hello " + name)