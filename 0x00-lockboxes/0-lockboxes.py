#!/usr/bin/python3
"""
"""
def canUnlockAll(boxes):
    """
    """
    # Basic requirements
    if not boxes:
        return False
    if type(boxes) is not list:
        return False
    for box in boxes:
        if type(box) is not list:
            return False

    founded_keys = [key for key in boxes[0]]
    print("Init keys {}".format(founded_keys))
    # Get all the keys
    for box in boxes:
        if len(founded_keys) == 0:
            return False
        for key in box:
            temp_key = []
            if key < len(boxes):
                for new_key in boxes[key]:
                    temp_key.append(new_key)
            for new_key in temp_key:
                if new_key not in founded_keys:
                    founded_keys.append(new_key)
    """
    for index, item in enumerate():
    print(index, item[index]);
    """
    for test_key in range(0, len(boxes) - 1):
        print("Founded Keys {}".format(founded_keys))
        print("Number on boxes {}".format(boxes))
        if test_key not in founded_keys:
            print("Test key {} -> Founded key {}".format(test_key, founded_keys))
            return False
    return True
