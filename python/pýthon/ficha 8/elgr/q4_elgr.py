dict_alpha_key = dict()
values = list()
all_info = input().split()
price = 0
points = 0
cars = list()

while all_info != ['*']:
    dict_alpha_key[all_info[0]] = all_info[1:3]
    all_info = input().split()

license_plate = input()
while license_plate != '*':
    for part in license_plate.split(' '):
        if dict_alpha_key.get(part, 0) != 0:
            values = dict_alpha_key.get(part, 0) + values

    for numbers in values[0::2]:
        price = float(numbers) + price
    for numbers in values[1::2]:
        points = int(numbers) + points
    license_plate = license_plate.split(' ')
    cars.append(str(f"{license_plate[0]} {price:.2f} {points}"))

    points = 0
    price = 0
    values = list()
    license_plate = input()

cars = sorted(cars)
for parts in cars:
    print(parts)