while True:
    L = int(input())

    if L == 0:
        break

    decisions = input().split()
    current = '+x'

    for d in decisions:
        if d == 'No':
            continue

        if current == '+x':
            current = d
        elif current == '-x':
            minus_x_rules = {
                '+y': '-y',
                '-y': '+y',
                '+z': '-z',
                '-z': '+z'
            }
            current = minus_x_rules[d]
        elif current == '+y':
            plus_y_rules = {
                '+y': '-x',
                '-y': '+x',
                '+z': '+y',
                '-z': '+y'
            }
            current = plus_y_rules[d]
        elif current == '-y':
            minus_y_rules = {
                '+y': '+x',
                '-y': '-x',
                '+z': '-y',
                '-z': '-y'
            }
            current = minus_y_rules[d]
        elif current == '+z':
            plus_z_rules = {
                '+y': '+z',
                '-y': '+z',
                '+z': '-x',
                '-z': '+x'
            }
            current = plus_z_rules[d]
        elif current == '-z':
            minus_z_rules = {
                '+y': '-z',
                '-y': '-z',
                '+z': '+x',
                '-z': '-x'
            }
            current = minus_z_rules[d]
    
    print(current)

