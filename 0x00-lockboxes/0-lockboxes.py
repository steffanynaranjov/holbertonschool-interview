#!/usr/bin/python3
""" Unlocking boxes module """


def canUnlockAll(boxes):
    """
    check if all boxes can be unlocked method
    A key with the same number as a box(index) opens that box
    Each box is numbered sequentially from 0 to n - 1
    The first box in boxes [0] is unlocked
    Return:
        True - if all boxes can be unlocked otherwise, false
    """
    keys_stack = [0]
    locked_box = 0
    unlocked_box = 1
    # first boxes index will be always unlocked
    unlocked_checker = [unlocked_box] + [locked_box] * (len(boxes) - 1)
    if len(boxes) == 0:
        return True
    if not isinstance(boxes, list):
        return False
    while keys_stack:
        index = keys_stack.pop()
        for key in boxes[index]:
            if key < len(boxes) and unlocked_checker[key] == locked_box:
                unlocked_checker[key] = unlocked_box
                keys_stack.append(key)  # lets check for those keys as index

    if locked_box in unlocked_checker:
        return False
    return True