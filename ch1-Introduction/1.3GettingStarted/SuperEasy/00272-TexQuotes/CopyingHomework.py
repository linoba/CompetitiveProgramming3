class CopyingHomework:
     def copy(self, friendsHomework):
        result = list(friendsHomework)
        result[0] -= 1
        result[1] -= 1
        result[2] -= 1
        result[3] -= 1
        result[4] += 4
        return result
            