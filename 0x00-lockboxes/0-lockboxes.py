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
                # Dont repeat founded keys
                if new_key not in founded_keys:
                    founded_keys.append(new_key)
    print("Keys to test {}".format(founded_keys))
    print("Boxes {}".format(boxes))
    for try_open in boxes:
        print("try open {} with {}".format(try_open, founded_keys))
        if len(founded_keys) == len(try_open):
            print("open")
            return True
        return False
