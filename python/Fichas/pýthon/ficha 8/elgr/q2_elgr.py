food = input().split(',')
food_dict = dict()
controller = 0
value = 0
T = 110
T2 = 130

while food != ['*']:
    food_dict[food[0]] = int(food[1])
    food = input().split(',')

person_key = int(input())

while person_key != 0:
    while person_key != controller:
        person_food = input().split(' ', 1)
        value = int(person_food[0]) * food_dict[person_food[1]] + value
        controller += 1

    if T < value < T2:
        print(f'{value} mg')
    elif value > T2:
        value_new = value - T2
        print(f'Menos {value_new} mg')
    elif value < T:
        value_new = T - value
        print(f'Mais {value_new} mg')
    value = 0
    controller = 0
    person_key = int(input())