word = input()
count = {}
for letter in word:
    if letter in count:
        count[letter] += 1
    else:
        count[letter] = 1
print(count)
print(f'there are {len(count)} kinds of alphabets.')
max_value = max(count.values())
print(f'max alphabet count is {max_value}.')
for key in count.keys():
    if count[key] == max_value:
        print(f'the alphabet is \'{key}\'.')
