def find(search_list: list[int], value: int):
    left = 0
    right = len(search_list) - 1
    while left <= right:
        middle = left + (right - left) // 2
        item = search_list[middle]
        if value > item:
            left = middle + 1
        elif value < item:
            right = middle - 1
        else:
            return middle

    raise ValueError("value not in array")
