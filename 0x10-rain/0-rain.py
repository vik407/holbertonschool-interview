#!/usr/bin/python3
""" 0_rain.py
"""


def rain(walls):
    """ Return rainwater trapped with array of wall heights.
    """
    i, j = 0, len(walls) - 1
    lmax = rmax = res = 0
    while i < j:
        if walls[j] > walls[i]:
            if walls[i] > lmax:
                lmax = walls[i]
            else:
                res += lmax - walls[i]
            i += 1
        else:
            if walls[j] > rmax:
                rmax = walls[j]
            else:
                res += rmax - walls[j]
            j -= 1
    return res
