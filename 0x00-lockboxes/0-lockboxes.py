#!/usr/bin/python3
""" You have n number of locked boxes in front of you. Each box is numbered
sequentially from 0 to n - 1 and each box may contain keys to the other boxes.
"""
import json


def canUnlockAll(boxes):
    """ Write a method that determines if all the boxes can be opened.
    @boxes is a list of lists
    """
    # Basic checks
    if not boxes:
        return False
    if type(boxes) is not list:
        return False

    unlocked = {'0': True}
    # Get first box unlocked
    for key in boxes[0]:
        unlocked_key = '{}'.format(key)
        unlocked[unlocked_key] = True

    # Unlock them
    for unlocked_key in list(unlocked.keys()):
        key_pos = int(unlocked_key)
        for key in boxes[key_pos]:
            deeper_unlocked = '{}'.format(key)
            unlocked[deeper_unlocked] = True

    # Move through boxes
    pos = 1
    for box in boxes[1:]:
        if str(pos) in list(unlocked.keys()):
            for key in box:
                unlocked['{}'.format(key)] = True
        pos += 1

    if len(boxes) > len(unlocked.keys()):
        return False
    else:
        return True
