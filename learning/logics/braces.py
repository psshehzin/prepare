def isValid(self, s: str) -> bool:
    stack = []
    matching_braces = {')': '(', ']': '[', '}': '{'}

    for char in s:
        if char in matching_braces:
            if stack and stack[-1] == matching_braces[char]:
                stack.pop()
            else:
                return False
        else:
            stack.append(char)

    return not stack