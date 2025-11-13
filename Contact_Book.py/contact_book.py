
import json
import os

FILENAME = "contacts.json"

def load_contacts():
    if not os.path.exists(FILENAME):
        return []
    with open(FILENAME, "r") as file:
        return json.load(file)

def save_contacts(contacts):
    with open(FILENAME, "w") as file:
        json.dump(contacts, file, indent=2)

def add_contact(contacts):
    name = input("Enter name: ").strip()
    phone = input("Enter phone: ").strip()
    email = input("Enter email: ").strip()
    contacts.append({"name": name, "phone": phone, "email": email})
    save_contacts(contacts)
    print("Contact added.\n")

def view_contacts(contacts):
    if not contacts:
        print("No contacts found.\n")
        return
    print("\nAll Contacts:")
    for idx, c in enumerate(contacts, start=1):
        print(f"{idx}. {c['name']} | {c['phone']} | {c['email']}")
    print()

def search_contacts(contacts):
    q = input("Search name: ").lower()
    matches = [c for c in contacts if q in c['name'].lower()]
    if not matches:
        print("No matching contacts.\n")
        return
    print("\nMatches:")
    for c in matches:
        print(f"{c['name']} | {c['phone']} | {c['email']}")
    print()

def delete_contact(contacts):
    view_contacts(contacts)
    idx = input("Enter number of contact to delete: ")
    if idx.isdigit() and 1 <= int(idx) <= len(contacts):
        deleted = contacts.pop(int(idx)-1)
        save_contacts(contacts)
        print(f"Deleted: {deleted['name']}\n")
    else:
        print("Invalid input.\n")

def main():
    contacts = load_contacts()
    while True:
        print("Contact Book:")
        print("1. Add Contact\n2. View Contacts\n3. Search Contacts\n4. Delete Contact\n5. Exit")
        choice = input("Choose option: ").strip()
        if choice == "1":
            add_contact(contacts)
        elif choice == "2":
            view_contacts(contacts)
        elif choice == "3":
            search_contacts(contacts)
        elif choice == "4":
            delete_contact(contacts)
        elif choice == "5":
            print("Goodbye!")
            break
        else:
            print("Invalid choice!\n")

if __name__ == "__main__":
    main()
