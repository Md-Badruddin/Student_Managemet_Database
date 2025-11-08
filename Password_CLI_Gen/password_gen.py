
import random
import string

def generate_password(length):
    chars = string.ascii_letters + string.digits + "!@#$%^&*()"
    return ''.join(random.choice(chars) for _ in range(length))

if __name__ == "__main__":
    length = input("Enter password length (min 4): ")
    try:
        l = int(length)
        if l < 4:
            print("Must be at least 4.")
        else:
            print("Your password:", generate_password(l))
    except ValueError:
        print("Invalid number.")
