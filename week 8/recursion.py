def pow(num, power):
    if (power == 1):
        return num
    return num * pow(num, power-1)

def palindrome(word):
    length = len(word)
    #print("length was %d" % length)
    if (length <= 1):
        return True
    #print( "comparing %s with %s result is %r" % (word[0], word[length-1], (word[0] == word[length-1])))
    return (word[0] == word[length-1]) and palindrome(word[1:length-1])

def reverse(word):
    length = len(word)
    if (length <= 1):
        return word
    return word[length-1] + reverse(word[:length-1]);

print(pow(3,4))

print(palindrome("dood"))
print(palindrome("madam"))
print(palindrome("cinimod"))

print(reverse("cinimod"))

print(reverse("GMIT"))
