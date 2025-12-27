name = ["Ana", "Marcos", "Alberto"]
age = [33, 21, 79]
weight = [70, 65, 59]
height = [1.74, 1.79, 1.68]

def CreatePerson():
    name.append(input("Enter the name of the person: "))
    age.append(int(input("Enter the age of the person: ")))
    weight.append(float(input("Enter the weight of the person: ")))
    height.append(float(input("Enter the height of the person: ")))

def ReadPerson():
    searchName = input("Enter the name of the person you want to search for: ")
    for i in range(len(name)):
        if name[i].lower() == searchName.lower():
            print("Name: ", name[i])
            print("Age: ", age[i])
            print("Weight: ", weight[i])
            print("Height: ", height[i])
            return
    print("The person called '",searchName,"' cannot be found")

def UpdatePerson():
    searchName = input("Enter the name of the person you want to update: ")
    for i in range(len(name)):
        if name[i].lower() == searchName.lower():
            searchName = i
            break
    else:
        print("The person called '",searchName,"' cannot be found")
        return

    print("What do you want to update about '",name[searchName],"'?")
    print("1 - Name")
    print("2 - Age")
    print("3 - Weight")
    print("4 - Height")
    option = input("")
    match option:
        case "1":
            oldname = name[searchName]
            name[searchName] = input("Enter the new name: ")
            print("The name was updated from '",oldname,"' to '",name[searchName],"'.")
        case "2":
            oldage = age[searchName]
            age[searchName] = int(input("Enter the new age: "))
            print("The age was updated from '",oldage,"' to '",age[searchName],"'.")
        case "3":
            oldweight = weight[searchName]
            weight[searchName] = float(input("Enter the new weight: "))
            print("The weight was updated from '",oldweight,"' to '",weight[searchName],"'.")
        case "4":
            oldheight = height[searchName]
            height[searchName] = float(input("Enter the new height: "))
            print("The height was updated from '",oldheight,"' to '",height[searchName],"'.")
        case _:
            print("Invalid Option")

def DeletePerson():
    searchName = input("Enter the name of the person you want to delete: ")
    for i in range(len(name)):
        if name[i].lower() == searchName.lower():
            print("The person named '",name.pop(i),"' has been deleted.")
            del age[i]
            del weight[i]
            del height[i]
            return
    print("The person called '",searchName,"' cannot be found")

def Main():
    print("Choose the above options: ")
    print("1 - Create Person")
    print("2 - Read Person")
    print("3 - Update Person")
    print("4 - Delete Person")
    option = input("Enter your option: ")
    match option:
        case "1":
            print("Create Person option choosed.")
            CreatePerson()
            Main()
        case "2":
            print("Read Person option choosed.")
            ReadPerson()
            Main()
        case "3":
            print("Update Person option choosed.")
            UpdatePerson()
            Main()
        case "4":
            print("Delete Person option choosed.")
            DeletePerson()
            Main()
        case _:
            print("Invalid Option")
            Main()
            
Main()