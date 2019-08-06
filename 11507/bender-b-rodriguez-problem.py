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
            rules = {
                '+y': '-y',
                '-y': '+y',
                '+z': '-z',
                '-z': '+z'
            }
            current = rules[d]
        elif current == '+y':
            rules = {
                '+y': '-x',
                '-y': '+x',
                '+z': '+y',
                '-z': '+y'
            }
            current = rules[d]
        elif current == '-y':
            rules = {
                '+y': '+x',
                '-y': '-x',
                '+z': '-y',
                '-z': '-y'
            }
            current = rules[d]
        elif current == '+z':
            plus_z_rules = {
                '+y': '+z',
                '-y': '+z',
                '+z': '-x',
                '-z': '+x'
            }
            current = plus_z_rules[d]
        elif current == '-z':
            rules = {
                '+y': '-z',
                '-y': '-z',
                '+z': '+x',
                '-z': '-x'
            }
            current = rules[d]
    
    print(current)
