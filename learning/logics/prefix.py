from typing import List

def longestCommonPrefix(self, strs: List[str]) -> str:
    if not strs:
        return ""

    # Start with the first string as the prefix
    prefix = strs[0]

    # Iterate over the remaining strings
    for s in strs[1:]:
        # Trim the prefix until it's a prefix of string `s`
        while prefix != s[:len(prefix)]:
            prefix = prefix[:-1]
            if not prefix:
                return ""

    return prefix
