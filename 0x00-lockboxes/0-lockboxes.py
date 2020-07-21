#!/usr/bin/python3
""" You have n number of locked boxes in front of you. Each box is numbered
sequentially from 0 to n - 1 and each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """ Write a method that determines if all the boxes can be opened.
    @boxes is a list of lists
    """
    # Basic checks
    if not boxes:
        return False
    if type(boxes) is not list:
        return False

    # Position on first box that is unlocked
    unlocked = [0]
    for n in unlocked:
        # Move to the desired box
        for key in boxes[n]:
            # Try to open
            if key not in unlocked and key < len(boxes):
                # unlocked store the key
                unlocked.append(key)
    # Its all the boxes unlocked?
    if len(unlocked) == len(boxes):
        return True
    # Can't unlock all!
    return False
