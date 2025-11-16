
def add(x, y):
    return x + y

def subtract(x, y):
    return x - y

def multiply(x, y):
    return x * y

def divide(x, y):
    if y == 0:
        return "Error: Division by zero!"
    return x / y

def main():
    print("Simple Calculator")
    print("Select operation:")
    print("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit")

    while True:
        choice = input("Enter choice (1/2/3/4/5): ").strip()
        if choice == "5":
            print("Goodbye!")
            break
        if choice not in {"1", "2", "3", "4"}:
            print("Invalid choice.")
            continue
        try:
            num1 = float(input("Enter first number: "))
            num2 = float(input("Enter second number: "))
        except ValueError:
            print("Invalid input! Enter numeric values.")
            continue
        
        if choice == "1":
            print(f"{num1} + {num2} = {add(num1, num2)}")
        elif choice == "2":
            print(f"{num1} - {num2} = {subtract(num1, num2)}")
        elif choice == "3":
            print(f"{num1} * {num2} = {multiply(num1, num2)}")
        elif choice == "4":
            print(f"{num1} / {num2} = {divide(num1, num2)}")
        print()

if __name__ == "__main__":
    main()
