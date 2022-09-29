t = int(input())
case = 1

while t != 0:
    rows = int(input())
    cols = int(input())

    matrix = []
    for row in range(rows):
        matrix.append(list(input()))

    contested = 0
    storeChar = {}
    seenChar = []
    visited = set()

    def dfs(r, c, char):
        if (r < 0 or c < 0 or 
            r == rows or c == cols or 
            matrix[r][c] == "#" or 
            (r, c) in visited):
            return

        visited.add((r, c))

        if matrix[r][c] != "." and matrix[r][c] != char:
            seenChar.append(matrix[r][c])

        dfs(r + 1, c, char)
        dfs(r - 1, c, char)
        dfs(r, c + 1, char)
        dfs(r, c - 1, char)

    for r in range(rows):
        for c in range(cols):
            if matrix[r][c] != "#" and matrix[r][c] != "." and (r, c) not in visited:
                dfs(r, c, matrix[r][c])

                if len(seenChar) == 0:
                    if matrix[r][c] not in storeChar:
                        storeChar[matrix[r][c]] = 1
                    else:
                        storeChar[matrix[r][c]] += 1
                    
                if len(seenChar) > 0:
                    contested += 1

                seenChar = []

    # sort alphabetically
    alphabeticStoreChar = {k: v for k, v in sorted(storeChar.items())}

    print(f"Case {case}")
    for key in alphabeticStoreChar:
        print(key, alphabeticStoreChar[key])
    print("contested", contested)

    case += 1
    t -= 1
