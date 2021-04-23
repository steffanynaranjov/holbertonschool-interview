#!/usr/bin/python3
"""
This a solution for a lockboxes challenge
"""


def canUnlockAll(boxes):
    """
    Rreturns True if all boxes can be opened or
    Returns False if they are not
    """

    keys = [0]
    unlockedBoxes = list(range(len(boxes)))

    # if there is not more boxes the loops will stop with this parameter
    lockedBox = True

    while lockedBox:
        lockedBox = False
        for x in range(len(boxes)):
            if (x in keys and x in unlockedBoxes):
                keys.extend(boxes[x])
                while(unlockedBoxes.count(x)):
                    unlockedBoxes.remove(x)
                lockedBox = True
    if not unlockedBoxes:
        return True
    return False
    